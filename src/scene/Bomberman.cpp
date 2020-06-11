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
#include "../ecs/component/BombStats.hpp"
#include "../ecs/component/BombTimer.hpp"
#include "../ecs/component/BoundingBox.hpp"
#include "../ecs/component/Breakable.hpp"
#include "../ecs/component/Collision.hpp"
#include "../ecs/component/Delay.hpp"
#include "../ecs/component/Motion.hpp"
#include "../ecs/component/Music.hpp"
#include "../ecs/component/Owner.hpp"
#include "../ecs/component/SkinColor.hpp"
#include "../ecs/component/Particle.hpp"
#include "../ecs/component/PlayerId.hpp"
#include "../ecs/component/PowerUp.hpp"
#include "../ecs/component/Render3d.hpp"
#include "../ecs/component/Sound.hpp"
#include "../ecs/component/Spinner.hpp"
#include "../ecs/component/Stats.hpp"
#include "../ecs/component/ToDelete.hpp"
#include "../ecs/component/Transform.hpp"
#include "../ecs/component/Unbreakable.hpp"
#include "../ecs/system/Animation.hpp"
#include "../ecs/system/BombTimer.hpp"
#include "../ecs/system/BoundingBox.hpp"
#include "../ecs/system/ExplosionDelay.hpp"
#include "../ecs/system/Motion.hpp"
#include "../ecs/system/Movement.hpp"
#include "../ecs/system/Music.hpp"
#include "../ecs/system/Player.hpp"
#include "../ecs/system/PowerUp.hpp"
#include "../ecs/system/Render.hpp"
#include "../ecs/system/Shrink.hpp"
#include "../ecs/system/Sound.hpp"
#include "../ecs/system/Spinner.hpp"
#include "../ecs/system/WinChecking.hpp"
#include "../map-generator/MapGenerator.hpp"
#include "GameHud.hpp"

using namespace scene;

std::vector<ecs::Entity> Bomberman::playerIds = {};
std::array<irr::scene::IMetaTriangleSelector *, 4> Bomberman::metaTriangleSelector = {
    nullptr, nullptr, nullptr, nullptr};

void Bomberman::createExplosion(ecs::WorldManager *worldManager, irr::u32 delay, const irr::core::vector3df& pos)
{
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    ecs::Entity explosion = worldManager->createEntity();

    irr::scene::ISceneNode *explosionMesh = smgr->addCubeSceneNode();
    irr::scene::IParticleSystemSceneNode *particleSystem = smgr->addParticleSystemSceneNode(false);

    explosionMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    explosionMesh->setPosition(pos);
    explosionMesh->setScale(irr::core::vector3df(1, 1, 1));
    explosionMesh->setVisible(false);

    irr::scene::IParticleEmitter* emitter = particleSystem->createBoxEmitter(
        irr::core::aabbox3d<irr::f32>(irr::core::vector3df(pos.X + 3, pos.Y - 20, pos.Z - 3)),
        irr::core::vector3df(0.0f,0.05f,0.0f),
        400,400,
        irr::video::SColor(0,0,255,255),
        irr::video::SColor(0,0,255,255),
        500, 500,
        20,
        irr::core::dimension2df(10.0f,10.0f),
        irr::core::dimension2df(15.0f,15.0f));

    particleSystem->setEmitter(emitter);
    emitter->drop();
    particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particleSystem->setMaterialTexture(0, driver->getTexture(bomberman::bomb::EXPLOSION.c_str()));
    particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    irr::scene::IParticleAffector* affector =
    particleSystem->createFadeOutParticleAffector(
    irr::video::SColor(0,0,0,0), 100);
    particleSystem->addAffector(affector);
    affector->drop();

    worldManager->addComponent<ecs::component::Render3d>(explosion, ecs::component::Render3d(explosionMesh));
    worldManager->addComponent<ecs::component::Delay>(explosion, ecs::component::Delay(delay));
    worldManager->addComponent<ecs::component::Particle>(explosion, ecs::component::Particle(particleSystem));
}


static irr::scene::IAnimatedMeshSceneNode *addCollisions(ecs::WorldManager *worldManager,
    irr::scene::ISceneManager *smgr, irr::scene::IAnimatedMeshSceneNode *characterMesh, size_t charNbr)
{
    irr::scene::ITriangleSelector *selector =
        smgr->createOctreeTriangleSelector(characterMesh->getMesh(), characterMesh, 128);
    characterMesh->setTriangleSelector(selector);

    irr::core::aabbox3d<irr::f32> box(0, 0, 0, 9.5, 10, 9.5);

    irr::core::vector3df radius = box.MaxEdge - box.getCenter();

    irr::scene::ISceneNodeAnimator *anim =
        smgr->createCollisionResponseAnimator(Bomberman::metaTriangleSelector[charNbr], characterMesh, radius,
            irr::core::vector3df(0, -10, 0), irr::core::vector3df(0, -5, 0));
    characterMesh->addAnimator(anim);
    anim->drop();
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

    characterMesh = addCollisions(worldManager, smgr, characterMesh, charNbr);

    worldManager->addComponent<ecs::component::Render3d>(character, ecs::component::Render3d(characterMesh));
    worldManager->addComponent<ecs::component::Player>(character, player_comp);
    worldManager->addComponent<ecs::component::Motion>(character, ecs::component::Motion());
    worldManager->addComponent<ecs::component::Transform>(
        character, ecs::component::Transform(characterMesh->getPosition()));
    worldManager->addComponent<ecs::component::Stats>(
        character, ecs::component::Stats());
    worldManager->addComponent<ecs::component::Animation>(character,
        ecs::component::Animation(
            std::unordered_map<std::string, std::pair<size_t, size_t>>({{"IDLE", {183, 204}}, {"WALKING", {0, 13}}})));
    worldManager->addComponent<ecs::component::Collision>(character, ecs::component::Collision());
    worldManager->addComponent<ecs::component::PlayerId>(character, ecs::component::PlayerId(charNbr));

    Bomberman::playerIds.push_back(character);
}

static void createBot(ecs::WorldManager *worldManager, irr::core::vector3df pos, size_t charNbr, const std::string &path)
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

    characterMesh = addCollisions(worldManager, smgr, characterMesh, charNbr);

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
    worldManager->addComponent<ecs::component::PlayerId>(character, ecs::component::PlayerId(charNbr));

    Bomberman::playerIds.push_back(character);
}

static void createCharacters(ecs::WorldManager *worldManager, irr::u32 tileSize, irr::u32 nbTile,
    std::vector<ecs::component::Player> players, std::vector<std::string> paths, std::vector<bool> playerType)
{
    irr::f32 offset = tileSize / 2;
    std::vector<irr::core::vector3df> characterPositions = {
        irr::core::vector3df(tileSize + offset, 0.0, tileSize + offset),
        irr::core::vector3df(tileSize + offset, 0.0, tileSize * (nbTile - 2) + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 0.0, tileSize + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 0.0, tileSize * (nbTile - 2) + offset)};

    for (size_t i = 0; i < playerType.size(); i++) {
        if (!playerType[i]) {
            createPlayer(worldManager, players[i], characterPositions[i], i, paths[i]);
        } else {
            createBot(worldManager, characterPositions[i], i, paths[i]);
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
                    for (auto& metaSelector : scene::Bomberman::metaTriangleSelector)
                        metaSelector->addTriangleSelector(selector);
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
                    for (auto& metaSelector : scene::Bomberman::metaTriangleSelector)
                        metaSelector->addTriangleSelector(selector);
                    selector->drop();

                    wallMesh->setMaterialTexture(0, driver->getTexture(bomberman::map::BOX.c_str()));
                    wallMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wallMesh->setPosition(irr::core::vector3df(
                        (x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wallMesh));
                    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
                    worldManager->addComponent<ecs::component::Breakable>(wall, ecs::component::Breakable());
                }
            }
        }
    }
}

void scene::Bomberman::createBomb(
    ecs::WorldManager *worldManager, ecs::Entity playerId, size_t bombRadius, bool wallPass, const irr::core::vector3d<irr::f32> &pos)
{
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    ecs::Entity bomb = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *bombMesh =
        smgr->addAnimatedMeshSceneNode(smgr->getMesh(bomberman::bomb::BOMB.c_str()));
    bombMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    bombMesh->setMaterialTexture(0, driver->getTexture(bomberman::bomb::TEXTURE.c_str()));
    auto newPos = pos;
    newPos.X = static_cast<int>(pos.X / 10.f) * 10 + 5;
    newPos.Y = 4;
    newPos.Z = static_cast<int>(pos.Z / 10.f) * 10 + 5;
    bombMesh->setPosition(newPos);
    bombMesh->setScale(irr::core::vector3df(30, 30, 30));

    irr::scene::IMeshSceneNode *boxMesh = smgr->addCubeSceneNode(10);
    boxMesh->setMaterialTexture(0, driver->getTexture(bomberman::map::BOUNDING_BOX.c_str()));
    boxMesh->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
    newPos.X = static_cast<int>(pos.X / 10.f) * 10 + 5;
    newPos.Y = 5;
    newPos.Z = static_cast<int>(pos.Z / 10.f) * 10 + 5;
    boxMesh->setPosition(newPos);

    irr::scene::ITriangleSelector *selector = smgr->createOctreeTriangleSelector(boxMesh->getMesh(), boxMesh, 128);
    boxMesh->setTriangleSelector(selector);

    worldManager->addComponent<ecs::component::Render3d>(bomb, ecs::component::Render3d(bombMesh));
    worldManager->addComponent<ecs::component::BombStats>(bomb, ecs::component::BombStats(bombRadius, wallPass));
    worldManager->addComponent<ecs::component::BombTimer>(bomb, ecs::component::BombTimer(3000));
    worldManager->addComponent<ecs::component::Owner>(bomb, ecs::component::Owner(playerId));
    worldManager->addComponent<ecs::component::BoundingBox>(bomb, ecs::component::BoundingBox(boxMesh, selector));
    worldManager->addComponent<ecs::component::Breakable>(bomb, ecs::component::Breakable());
    worldManager->addComponent<ecs::component::Sound>(bomb, ecs::component::Sound({{"explosion", scene::bomberman::sound::EXPLOSION}}));
}

void Bomberman::updateCollision(ecs::WorldManager *worldManager)
{
    std::vector<ecs::Entity> entities = worldManager->getEntities<ecs::component::Render3d, ecs::component::PlayerId>();

    for (auto &entity : entities) {
        auto &render3d = worldManager->getComponent<ecs::component::Render3d>(entity);
        auto &playerId = worldManager->getComponent<ecs::component::PlayerId>(entity);

        irr::core::aabbox3d<irr::f32> box(0, 0, 0, 9.5, 10, 9.5);
        irr::core::vector3df radius = box.MaxEdge - box.getCenter();
        auto &characterMesh = render3d.node;

        irr::scene::ISceneNodeAnimator *anim =
            worldManager->getUniverse()->getDevice()->getSceneManager()->createCollisionResponseAnimator(
                metaTriangleSelector[playerId.id], characterMesh, radius, irr::core::vector3df(0, -10, 0),
                irr::core::vector3df(0, -5, 0));
        characterMesh->addAnimator(anim);
        anim->drop();
    }
}

void scene::Bomberman::init(
    ecs::Universe *universe, std::vector<ecs::component::Player> players, std::vector<std::string> paths, std::vector<bool> playerType)
{
    auto worldManager = universe->createWorldManager("Bomberman");
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    irr::core::vector3df ground_pos;
    irr::f32 tileSize = 10.0;
    irr::u32 nbTile = 13;

    for (auto& metaSelector : scene::Bomberman::metaTriangleSelector)
        metaSelector = smgr->createMetaTriangleSelector();

    worldManager->registerComponent<ecs::component::Render3d>();
    worldManager->registerComponent<ecs::component::Player>();
    worldManager->registerComponent<ecs::component::Transform>();
    worldManager->registerComponent<ecs::component::Unbreakable>();
    worldManager->registerComponent<ecs::component::AI>();
    worldManager->registerComponent<ecs::component::Motion>();
    worldManager->registerComponent<ecs::component::Animation>();
    worldManager->registerComponent<ecs::component::Stats>();
    worldManager->registerComponent<ecs::component::Collision>();
    worldManager->registerComponent<ecs::component::Delay>();
    worldManager->registerComponent<ecs::component::Particle>();
    worldManager->registerComponent<ecs::component::BombTimer>();
    worldManager->registerComponent<ecs::component::BombStats>();
    worldManager->registerComponent<ecs::component::Owner>();
    worldManager->registerComponent<ecs::component::BoundingBox>();
    worldManager->registerComponent<ecs::component::PlayerId>();
    worldManager->registerComponent<ecs::component::PowerUp>();
    worldManager->registerComponent<ecs::component::Breakable>();
    worldManager->registerComponent<ecs::component::ToDelete>();
    worldManager->registerComponent<ecs::component::Spinner>();
    worldManager->registerComponent<ecs::component::Music>();
    worldManager->registerComponent<ecs::component::Sound>();
    worldManager->registerComponent<ecs::component::SkinColor>();

    worldManager->registerSystem<ecs::system::Sound>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Sound>());
        worldManager->setSystemSignature<ecs::system::Sound>(signature);
    }
    worldManager->registerSystem<ecs::system::Music>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Music>());
        worldManager->setSystemSignature<ecs::system::Music>(signature);
    }
    worldManager->registerSystem<ecs::system::Render>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Render>(signature);
    }
    worldManager->registerSystem<ecs::system::PowerUp>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::PowerUp>());
        worldManager->setSystemSignature<ecs::system::PowerUp>(signature);
    }
    worldManager->registerSystem<ecs::system::Spinner>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Spinner>());
        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Spinner>(signature);
    }
    worldManager->registerSystem<ecs::system::BoundingBox>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::BoundingBox>());
        worldManager->setSystemSignature<ecs::system::BoundingBox>(signature);
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
    worldManager->registerSystem<ecs::system::ExplosionDelay>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        signature.set(worldManager->getComponentType<ecs::component::Delay>());
        worldManager->setSystemSignature<ecs::system::ExplosionDelay>(signature);
    }
    std::shared_ptr<ecs::system::Shrink> shrinkSystem = worldManager->registerSystem<ecs::system::Shrink>();
    worldManager->subscribe(*(shrinkSystem.get()), &ecs::system::Shrink::startShrinking);
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
    worldManager->registerSystem<ecs::system::BombTimer>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::BombTimer>());
        worldManager->setSystemSignature<ecs::system::BombTimer>(signature);
    }
    worldManager->registerSystem<ecs::system::WinChecking>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::PlayerId>());
        signature.set(worldManager->getComponentType<ecs::component::Stats>());
        worldManager->setSystemSignature<ecs::system::WinChecking>(signature);
    }

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
    for (auto& metaSelector : scene::Bomberman::metaTriangleSelector)
        metaSelector->addTriangleSelector(selector);
    selector->drop();

    worldManager->addComponent<ecs::component::Render3d>(ground, ecs::component::Render3d(groundMesh));
    worldManager->addComponent<ecs::component::Transform>(ground, ecs::component::Transform(groundMesh->getPosition()));
    worldManager->addComponent<ecs::component::Collision>(ground, ecs::component::Collision());

    ecs::Entity music = worldManager->createEntity();
    worldManager->addComponent<ecs::component::Music>(music, ecs::component::Music(scene::bomberman::MUSIC));

    auto sfx = worldManager->createEntity();
    worldManager->addComponent<ecs::component::Sound>(sfx, ecs::component::Sound({{"powerup", scene::bomberman::sound::POWERUP}, {"death", scene::bomberman::sound::DEATH}}));
    worldManager->addComponent<ecs::component::ToDelete>(sfx, ecs::component::ToDelete());

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
    createCharacters(worldManager, tileSize, nbTile, players, paths, playerType);

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


void scene::Bomberman::createPowerUp(ecs::Universe *universe, irr::core::vector3df position)
{
    irr::scene::ISceneManager *smgr = universe->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = universe->getDevice()->getVideoDriver();
    auto worldManager = universe->getWorldManager("Bomberman");
    ecs::Entity powerUp = worldManager->createEntity();
    irr::scene::IMeshSceneNode *powerUpMesh = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createCubeMesh(
        irr::core::vector3d<irr::f32>(0.1, 10, 10)));
    size_t powerUpChoice = std::rand() % 10;

    if (powerUpMesh) {
        powerUpMesh->setPosition(position);
        powerUpMesh->setRotation(irr::core::vector3df(0.0, 0.0, 45.0));
        powerUpMesh->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
        powerUpMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    worldManager->addComponent<ecs::component::Render3d>(powerUp, ecs::component::Render3d(powerUpMesh));
    worldManager->addComponent<ecs::component::Collision>(powerUp, ecs::component::Collision());
    worldManager->addComponent<ecs::component::PowerUp>(powerUp, ecs::component::PowerUp());
    worldManager->addComponent<ecs::component::Spinner>(powerUp, ecs::component::Spinner(irr::core::vector3d<irr::f32>(0, 5, 0), 100));

    if (powerUpChoice < 4) {
        powerUpMesh->setMaterialTexture(0, driver->getTexture(bomberman::powerUp::MAX_SPEED.c_str()));
        worldManager->addComponent<ecs::component::Stats>(powerUp, ecs::component::Stats(1, 0, 0, false));
    } else if (powerUpChoice < 6) {
        powerUpMesh->setMaterialTexture(0, driver->getTexture(bomberman::powerUp::BOMB_RADIUS.c_str()));
        worldManager->addComponent<ecs::component::Stats>(powerUp, ecs::component::Stats(0, 1, 0, false));
    } else if (powerUpChoice < 8) {
        powerUpMesh->setMaterialTexture(0, driver->getTexture(bomberman::powerUp::MAX_BOMB.c_str()));
        worldManager->addComponent<ecs::component::Stats>(powerUp, ecs::component::Stats(0, 0, 1, false));
    } else {
        powerUpMesh->setMaterialTexture(0, driver->getTexture(bomberman::powerUp::WALL_PASS.c_str()));
        worldManager->addComponent<ecs::component::Stats>(powerUp, ecs::component::Stats(0, 0, 0, true));
    }
}
