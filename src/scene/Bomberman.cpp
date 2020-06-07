/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomberman.cpp
*/

#include "Bomberman.hpp"

#include <ctime>

#include "../ecs/component/Render3d.hpp"
#include "../ecs/component/Transform.hpp"
#include "../ecs/component/Unbreakable.hpp"
#include "../ecs/component/AI.hpp"
#include "../ecs/component/Motion.hpp"
#include "../ecs/component/Animation.hpp"
#include "../ecs/component/Stats.hpp"
#include "../ecs/component/Collision.hpp"
#include "../ecs/system/Render.hpp"
#include "../ecs/system/Movement.hpp"
#include "../ecs/system/Motion.hpp"
#include "../ecs/system/Player.hpp"
#include "../ecs/system/Animation.hpp"
#include "../map-generator/MapGenerator.hpp"


using namespace scene;

std::vector<ecs::Entity> Bomberman::playerIds = {};

static irr::scene::IAnimatedMeshSceneNode *addCollisions(ecs::WorldManager *worldManager, irr::scene::ISceneManager *smgr, irr::scene::IAnimatedMeshSceneNode *caracter_mesh)
{
    std::vector<ecs::Entity> collisionList; //= FONCTIONMAGIQUE

    irr::scene::ITriangleSelector* selector = smgr->createOctreeTriangleSelector(caracter_mesh->getMesh(), caracter_mesh, 128);
    caracter_mesh->setTriangleSelector(selector);

    for (auto it : collisionList) {
        irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector, worldManager->getComponent<ecs::component::Render3d>(it).node, irr::core::vector3df(30,50,30), irr::core::vector3df(0,-10,0), irr::core::vector3df(0,30,0));
        caracter_mesh->addAnimator(anim);
        anim->drop();
    }
    selector->drop();
    return (caracter_mesh);
}

static void createPlayer(ecs::WorldManager *worldManager, const ecs::component::Player& player_comp, const irr::core::vector3df& pos, size_t charNbr, const std::string& path)
{
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    ecs::Entity caracter = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *caracter_mesh = smgr->addAnimatedMeshSceneNode(smgr->getMesh(bomberman::ninja::NINJA.c_str()));

    caracter_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    caracter_mesh->setPosition(pos);
    if (charNbr == 0 || charNbr == 1)
        caracter_mesh->setRotation(irr::core::vector3df(0, 90, 0));
    else
        caracter_mesh->setRotation(irr::core::vector3df(0, -90, 0));
    caracter_mesh->setScale(irr::core::vector3df(1.9,1.9,1.9));
    caracter_mesh->setFrameLoop(183, 204);

    caracter_mesh->setMaterialTexture(0, driver->getTexture(path.c_str()));
    bomberman::ninja::PLAYER_SKINS[path] = true;

    //caracter_mesh = addCollisions(worldManager, smgr, caracter_mesh);

    worldManager->addComponent<ecs::component::Render3d>(caracter, ecs::component::Render3d(caracter_mesh));
    worldManager->addComponent<ecs::component::Player>(caracter, player_comp);
    worldManager->addComponent<ecs::component::Motion>(caracter, ecs::component::Motion());
    worldManager->addComponent<ecs::component::Transform>(caracter, ecs::component::Transform(caracter_mesh->getPosition()));
    worldManager->addComponent<ecs::component::Stats>(caracter, ecs::component::Stats());
    worldManager->addComponent<ecs::component::Animation>(caracter, ecs::component::Animation(std::unordered_map<std::string, std::pair<size_t, size_t>>({{"IDLE", {183, 204}}, {"WALK", {0, 13}}})));
    worldManager->addComponent<ecs::component::Collision>(caracter, ecs::component::Collision());

    Bomberman::playerIds.push_back(caracter);
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
    ecs::Entity caracter = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *caracter_mesh = smgr->addAnimatedMeshSceneNode(smgr->getMesh(bomberman::ninja::NINJA.c_str()));

    caracter_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    caracter_mesh->setPosition(pos);
    if (charNbr == 0 || charNbr == 1)
        caracter_mesh->setRotation(irr::core::vector3df(0, 90, 0));
    else
        caracter_mesh->setRotation(irr::core::vector3df(0, -90, 0));
    caracter_mesh->setScale(irr::core::vector3df(1.9,1.9,1.9));
    caracter_mesh->setFrameLoop(183, 204);

    caracter_mesh->setMaterialTexture(0, driver->getTexture(getUnusedSkin().c_str()));

    //caracter_mesh = addCollisions(worldManager, smgr, caracter_mesh);

    worldManager->addComponent<ecs::component::Render3d>(caracter, ecs::component::Render3d(caracter_mesh));
    worldManager->addComponent<ecs::component::AI>(caracter, ecs::component::AI());
    worldManager->addComponent<ecs::component::Motion>(caracter, ecs::component::Motion());
    worldManager->addComponent<ecs::component::Transform>(caracter, ecs::component::Transform(caracter_mesh->getPosition()));
    worldManager->addComponent<ecs::component::Stats>(caracter, ecs::component::Stats());
    worldManager->addComponent<ecs::component::Animation>(caracter, ecs::component::Animation(std::unordered_map<std::string, std::pair<size_t, size_t>>({{"IDLE", {183, 204}}, {"WALK", {0, 13}}})));
    worldManager->addComponent<ecs::component::Collision>(caracter, ecs::component::Collision());
}

static void createCaracters(ecs::WorldManager *worldManager, irr::u32 tileSize, irr::u32 nbTile, std::vector<ecs::component::Player> players, std::vector<std::string> paths)
{
    irr::f32 offset = tileSize / 2;
    std::vector<irr::core::vector3df> caracterPositions = {
        irr::core::vector3df(tileSize + offset, 0.0, tileSize + offset),
        irr::core::vector3df(tileSize + offset, 0.0, tileSize * (nbTile - 2) + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 0.0, tileSize + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 0.0, tileSize * (nbTile - 2) + offset)};

    for (size_t i = 0; i < 4; i++) {
        if (i < players.size()) {
            createPlayer(worldManager, players[i], caracterPositions[i], i, paths[i]);
        }
        else {
            createBot(worldManager, caracterPositions[i], i);
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
                    irr::scene::ISceneNode *wall_mesh = smgr->addCubeSceneNode(tileSize);
                    wall_mesh->setMaterialTexture(0, driver->getTexture(bomberman::map::WALL.c_str()));
                    wall_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wall_mesh->setPosition(irr::core::vector3df((x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wall_mesh));
                    worldManager->addComponent<ecs::component::Unbreakable>(wall, ecs::component::Unbreakable());
                    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
                }
            }
            else if (tileMap[y][x] == '*') {
                {
                    ecs::Entity wall = worldManager->createEntity();
                    irr::scene::ISceneNode *wall_mesh = smgr->addCubeSceneNode(tileSize);
                    wall_mesh->setMaterialTexture(0, driver->getTexture(bomberman::map::BOX.c_str()));
                    wall_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wall_mesh->setPosition(irr::core::vector3df((x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wall_mesh));
                    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
                }
            }
        }
    }
}

void scene::Bomberman::init(ecs::Universe *universe, std::vector<ecs::component::Player> players, std::vector<std::string> paths)
{
    auto worldManager = universe->createWorldManager("Bomberman");
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    irr::core::vector3df ground_pos;
    irr::f32 tileSize = 10.0;
    irr::u32 nbTile = 13;

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
        worldManager->setSystemSignature<ecs::system::Player>(signature);
    }
    worldManager->subscribe(*(playerSystem.get()), &ecs::system::Player::receiveKeyEvent);

    ecs::Entity ground = worldManager->createEntity();
    irr::scene::IMeshSceneNode *ground_mesh = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createPlaneMesh(irr::core::dimension2df(tileSize, tileSize), irr::core::dimension2du(nbTile, nbTile)));
    if (ground_mesh) {
        smgr->getMeshManipulator()->makePlanarTextureMapping(ground_mesh->getMesh(), 0.1f, 0.1f, 1, irr::core::vector3df(0.0, 0.0, 5.0));
        ground_mesh->setMaterialTexture(0, driver->getTexture(bomberman::map::GROUND.c_str()));
        ground_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        ground_pos = ground_mesh->getPosition();
        ground_pos.X = ground_pos.X + ((tileSize * nbTile) / 2);
        ground_pos.Z = ground_pos.Z + ((tileSize * nbTile) / 2);
        ground_mesh->setPosition(ground_pos);
    }
    worldManager->addComponent<ecs::component::Render3d>(ground, ecs::component::Render3d(ground_mesh));
    worldManager->addComponent<ecs::component::Transform>(ground, ecs::component::Transform(ground_mesh->getPosition()));

    ecs::Entity camera = worldManager->createEntity();


    irr::scene::ICameraSceneNode *cameraNode = nullptr;
#ifndef DEBUG
    cameraNode = smgr->addCameraSceneNode();
#else
    cameraNode = smgr->addCameraSceneNodeFPS();
#endif
    if (cameraNode) {
        cameraNode->setPosition(irr::core::vector3df((tileSize * nbTile) * 0.88, 125.0, (tileSize * nbTile) / 2));
        auto vector = ground_mesh->getPosition();
        vector.X += 30;
        cameraNode->setTarget(vector);
    }
    worldManager->addComponent<ecs::component::Render3d>(camera, ecs::component::Render3d(cameraNode));

    createMap(worldManager, tileSize);

    createCaracters(worldManager, tileSize, nbTile, players, paths);
}

void scene::Bomberman::destroy(ecs::Universe *universe)
{
    universe->deleteWorldManager("PlayerSelector");
    universe->getDevice()->getGUIEnvironment()->clear();
    Bomberman::playerIds.clear();
    for (auto& skin : bomberman::ninja::PLAYER_SKINS) {
        skin.second = false;
    }
}