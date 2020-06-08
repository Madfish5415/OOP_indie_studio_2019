/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomberman.cpp
*/

#include "Bomberman.hpp"

#include <cstdlib>
#include <ctime>

#include "../ecs/component/AI.hpp"
#include "../ecs/component/Animation.hpp"
#include "../ecs/component/Collision.hpp"
#include "../ecs/component/Motion.hpp"
#include "../ecs/component/Render3d.hpp"
#include "../ecs/component/Stats.hpp"
#include "../ecs/component/Transform.hpp"
#include "../ecs/component/Unbreakable.hpp"
#include "../ecs/system/Animation.hpp"
#include "../ecs/system/Motion.hpp"
#include "../ecs/system/Movement.hpp"
#include "../ecs/system/Player.hpp"
#include "../ecs/system/Render.hpp"
#include "../map-generator/MapGenerator.hpp"
#include "GameHud.hpp"

using namespace scene;

std::vector<ecs::Entity> Bomberman::playerIds = {};
irr::scene::IMetaTriangleSelector *Bomberman::metaTriangleSelector = nullptr;

static irr::scene::IAnimatedMeshSceneNode *addCollisions(
    ecs::WorldManager *worldManager, irr::scene::ISceneManager *smgr, irr::scene::IAnimatedMeshSceneNode *characterMesh)
{
    irr::scene::ITriangleSelector *selector =
        smgr->createOctreeTriangleSelector(characterMesh->getMesh(), characterMesh, 128);
    characterMesh->setTriangleSelector(selector);

    irr::core::aabbox3d<irr::f32> box(0, 0, 0, 9.5, 9.5, 9.5);
    irr::core::vector3df radius = box.MaxEdge - box.getCenter();

    irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(Bomberman::metaTriangleSelector,
        characterMesh, radius, irr::core::vector3df(0, -10, 0), irr::core::vector3df(0, 0, 0));
    characterMesh->addAnimator(anim);
    anim->drop();
    selector->drop();
    return (characterMesh);
}

static void createPlayer(ecs::WorldManager *worldManager, const ecs::component::Player &player_comp,
    const irr::core::vector3df &pos, size_t charNbr, const std::string &path)
{
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    ecs::Entity character = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *characterMesh =
        smgr->addAnimatedMeshSceneNode(smgr->getMesh(bomberman::ninja::NINJA.c_str()));

    characterMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    characterMesh->setPosition(pos);
    if (charNbr == 0 || charNbr == 1)
        characterMesh->setRotation(irr::core::vector3df(0, 90, 0));
    else
        characterMesh->setRotation(irr::core::vector3df(0, -90, 0));
    characterMesh->setScale(irr::core::vector3df(1.9, 1.9, 1.9));
    characterMesh->setFrameLoop(183, 204);

    characterMesh->setMaterialTexture(0, driver->getTexture(path.c_str()));
    bomberman::ninja::PLAYER_SKINS[path] = true;

    characterMesh = addCollisions(worldManager, smgr, characterMesh);

    worldManager->addComponent<ecs::component::Render3d>(character, ecs::component::Render3d(characterMesh));
    worldManager->addComponent<ecs::component::Player>(character, player_comp);
    worldManager->addComponent<ecs::component::Motion>(character, ecs::component::Motion());
    worldManager->addComponent<ecs::component::Transform>(
        character, ecs::component::Transform(characterMesh->getPosition()));
    worldManager->addComponent<ecs::component::Stats>(character, ecs::component::Stats((std::rand() % 9 + 1), (std::rand() % 9 + 1), (std::rand() % 9 + 1)));
    worldManager->addComponent<ecs::component::Animation>(character,
        ecs::component::Animation(
            std::unordered_map<std::string, std::pair<size_t, size_t>>({{"IDLE", {183, 204}}, {"WALKING", {0, 13}}})));
    worldManager->addComponent<ecs::component::Collision>(character, ecs::component::Collision());

    Bomberman::playerIds.push_back(character);
}

static const std::string getUnusedSkin()
{
    auto item = bomberman::ninja::PLAYER_SKINS.begin();

    std::srand(std::time(nullptr));
    while (true) {
        item = bomberman::ninja::PLAYER_SKINS.begin();
        std::advance(item, std::rand() % bomberman::ninja::PLAYER_SKINS.size());
        if (!item->second) {
            item->second = true;
            return item->first;
        }
    }
}

static void createBot(ecs::WorldManager *worldManager, irr::core::vector3df pos, size_t charNbr)
{
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    ecs::Entity character = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *characterMesh =
        smgr->addAnimatedMeshSceneNode(smgr->getMesh(bomberman::ninja::NINJA.c_str()));

    characterMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    characterMesh->setPosition(pos);
    if (charNbr == 0 || charNbr == 1)
        characterMesh->setRotation(irr::core::vector3df(0, 90, 0));
    else
        characterMesh->setRotation(irr::core::vector3df(0, -90, 0));
    characterMesh->setScale(irr::core::vector3df(1.9, 1.9, 1.9));
    characterMesh->setFrameLoop(183, 204);

    characterMesh->setMaterialTexture(0, driver->getTexture(getUnusedSkin().c_str()));

    // characterMesh = addCollisions(worldManager, smgr, characterMesh);

    worldManager->addComponent<ecs::component::Render3d>(character, ecs::component::Render3d(characterMesh));
    worldManager->addComponent<ecs::component::AI>(character, ecs::component::AI());
    worldManager->addComponent<ecs::component::Motion>(character, ecs::component::Motion());
    worldManager->addComponent<ecs::component::Transform>(
        character, ecs::component::Transform(characterMesh->getPosition()));
    worldManager->addComponent<ecs::component::Stats>(character, ecs::component::Stats());
    worldManager->addComponent<ecs::component::Animation>(character,
        ecs::component::Animation(
            std::unordered_map<std::string, std::pair<size_t, size_t>>({{"IDLE", {183, 204}}, {"WALKING", {0, 13}}})));
    worldManager->addComponent<ecs::component::Collision>(character, ecs::component::Collision());
}

static void createCharacters(ecs::WorldManager *worldManager, irr::u32 tileSize, irr::u32 nbTile,
    std::vector<ecs::component::Player> players, std::vector<std::string> paths)
{
    irr::f32 offset = tileSize / 2;
    std::vector<irr::core::vector3df> characterPositions = {
        irr::core::vector3df(tileSize + offset, 5.0, tileSize + offset),
        irr::core::vector3df(tileSize + offset, 5.0, tileSize * (nbTile - 2) + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 5.0, tileSize + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 5.0, tileSize * (nbTile - 2) + offset)};

    for (size_t i = 0; i < 4; i++) {
        if (i < players.size()) {
            createPlayer(worldManager, players[i], characterPositions[i], i, paths[i]);
        } else {
            createBot(worldManager, characterPositions[i], i);
        }
    }
}

static void createMap(ecs::WorldManager *worldManager, irr::u32 tileSize)
{
    MapGenerator mapGenerator;
    std::array<std::array<char, 13>, 13> tileMap = mapGenerator.getMap();
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    for (size_t y = 0; y < 13; y++) {
        for (size_t x = 0; x < 13; x++) {
            if (tileMap[y][x] == '#') {
                {
                    ecs::Entity wall = worldManager->createEntity();
                    irr::scene::IMeshSceneNode *wallMesh = smgr->addCubeSceneNode(tileSize);

                    irr::scene::ITriangleSelector *selector =
                        smgr->createOctreeTriangleSelector(wallMesh->getMesh(), wallMesh, 128);
                    wallMesh->setTriangleSelector(selector);
                    Bomberman::metaTriangleSelector->addTriangleSelector(selector);
                    selector->drop();

                    wallMesh->setMaterialTexture(0, driver->getTexture(bomberman::map::WALL.c_str()));
                    wallMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wallMesh->setPosition(irr::core::vector3df(
                        (x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wallMesh));
                    worldManager->addComponent<ecs::component::Unbreakable>(wall, ecs::component::Unbreakable());
                    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
                }
            } else if (tileMap[y][x] == '*') {
                {
                    ecs::Entity wall = worldManager->createEntity();
                    irr::scene::IMeshSceneNode *wallMesh = smgr->addCubeSceneNode(tileSize);

                    irr::scene::ITriangleSelector *selector =
                        smgr->createOctreeTriangleSelector(wallMesh->getMesh(), wallMesh, 128);
                    wallMesh->setTriangleSelector(selector);
                    //Bomberman::metaTriangleSelector->addTriangleSelector(selector);
                    selector->drop();

                    wallMesh->setMaterialTexture(0, driver->getTexture(bomberman::map::BOX.c_str()));
                    wallMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wallMesh->setPosition(irr::core::vector3df(
                        (x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wallMesh));
                    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
                }
            }
        }
    }
}

void scene::Bomberman::init(
    ecs::Universe *universe, std::vector<ecs::component::Player> players, std::vector<std::string> paths)
{
    auto worldManager = universe->createWorldManager("Bomberman");
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    irr::core::vector3df ground_pos;
    irr::f32 tileSize = 10.0;
    irr::u32 nbTile = 13;

    Bomberman::metaTriangleSelector = smgr->createMetaTriangleSelector();

    worldManager->registerComponent<ecs::component::Render3d>();
    worldManager->registerComponent<ecs::component::Player>();
    worldManager->registerComponent<ecs::component::Transform>();
    worldManager->registerComponent<ecs::component::Unbreakable>();
    worldManager->registerComponent<ecs::component::AI>();
    worldManager->registerComponent<ecs::component::Motion>();
    worldManager->registerComponent<ecs::component::Animation>();
    worldManager->registerComponent<ecs::component::Stats>();
    worldManager->registerComponent<ecs::component::Collision>();

    worldManager->registerSystem<ecs::system::Render>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Render>(signature);
    }
    worldManager->registerSystem<ecs::system::Motion>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Motion>());
        signature.set(worldManager->getComponentType<ecs::component::Transform>());
        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Motion>(signature);
    }
    worldManager->registerSystem<ecs::system::Movement>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        signature.set(worldManager->getComponentType<ecs::component::Transform>());
        worldManager->setSystemSignature<ecs::system::Movement>(signature);
    }
    worldManager->registerSystem<ecs::system::Animation>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        signature.set(worldManager->getComponentType<ecs::component::Animation>());
        worldManager->setSystemSignature<ecs::system::Animation>(signature);
    }
    std::shared_ptr<ecs::system::Player> playerSystem = worldManager->registerSystem<ecs::system::Player>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        signature.set(worldManager->getComponentType<ecs::component::Player>());
        signature.set(worldManager->getComponentType<ecs::component::Stats>());
        signature.set(worldManager->getComponentType<ecs::component::Motion>());
        signature.set(worldManager->getComponentType<ecs::component::Animation>());
        worldManager->setSystemSignature<ecs::system::Player>(signature);
    }
    worldManager->subscribe(*(playerSystem.get()), &ecs::system::Player::receiveKeyEvent);

    ecs::Entity ground = worldManager->createEntity();
    irr::scene::IMeshSceneNode *groundMesh = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createPlaneMesh(
        irr::core::dimension2df(tileSize, tileSize), irr::core::dimension2du(nbTile, nbTile)));
    if (groundMesh) {
        smgr->getMeshManipulator()->makePlanarTextureMapping(
            groundMesh->getMesh(), 0.1f, 0.1f, 1, irr::core::vector3df(0.0, 0.0, 5.0));
        groundMesh->setMaterialTexture(0, driver->getTexture(bomberman::map::GROUND.c_str()));
        groundMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        ground_pos = groundMesh->getPosition();
        ground_pos.X = ground_pos.X + ((tileSize * nbTile) / 2);
        ground_pos.Z = ground_pos.Z + ((tileSize * nbTile) / 2);
        groundMesh->setPosition(ground_pos);
    }

    irr::scene::ITriangleSelector *selector =
        smgr->createOctreeTriangleSelector(groundMesh->getMesh(), groundMesh, 128);
    groundMesh->setTriangleSelector(selector);
    Bomberman::metaTriangleSelector->addTriangleSelector(selector);
    selector->drop();

    worldManager->addComponent<ecs::component::Render3d>(ground, ecs::component::Render3d(groundMesh));
    worldManager->addComponent<ecs::component::Transform>(ground, ecs::component::Transform(groundMesh->getPosition()));
    worldManager->addComponent<ecs::component::Collision>(ground, ecs::component::Collision());

    ecs::Entity camera = worldManager->createEntity();

    irr::scene::ICameraSceneNode *cameraNode = nullptr;
#ifndef DEBUG
    cameraNode = smgr->addCameraSceneNode();
#else
    cameraNode = smgr->addCameraSceneNodeFPS();
#endif
    if (cameraNode) {
        cameraNode->setPosition(irr::core::vector3df((tileSize * nbTile) * 0.88, 125.0, (tileSize * nbTile) / 2));
        auto vector = groundMesh->getPosition();
        vector.X += 30;
        cameraNode->setTarget(vector);
    }
    worldManager->addComponent<ecs::component::Render3d>(camera, ecs::component::Render3d(cameraNode));

    createMap(worldManager, tileSize);
    createCharacters(worldManager, tileSize, nbTile, players, paths);
    GameHud::init(universe, paths);
}

void scene::Bomberman::destroy(ecs::Universe *universe)
{
    GameHud::destroy(universe);
    universe->getDevice()->getSceneManager()->clear();
    universe->deleteWorldManager("Bomberman");
    Bomberman::playerIds.clear();
    for (auto &skin : bomberman::ninja::PLAYER_SKINS) {
        skin.second = false;
    }
}