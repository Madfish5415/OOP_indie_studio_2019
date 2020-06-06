/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Bomberman.cpp
*/

#include "Bomberman.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Render3d.hpp"
#include "../ecs/component/Transform.hpp"
#include "../ecs/component/Unbreakable.hpp"
#include "../ecs/component/AI.hpp"
#include "../ecs/system/Render.hpp"
#include "../map_generator/MapGenerator.hpp"

static void createPlayer(ecs::WorldManager *worldManager, ecs::component::Player player_comp, irr::core::vector3df pos)
{

}

static void createBot(ecs::WorldManager *worldManager, irr::core::vector3df pos)
{
    irr::scene::ISceneManager *smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    irr::video::IVideoDriver *driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    ecs::Entity caracter = worldManager->createEntity();
    irr::scene::IAnimatedMeshSceneNode *caracter_mesh = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/ninja.b3d"));

    caracter_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    caracter_mesh->setPosition(pos);
    worldManager->addComponent<ecs::component::Render3d>(caracter, ecs::component::Render3d(caracter_mesh));
    worldManager->addComponent<ecs::component::AI>(caracter, ecs::component::AI());
}

static void createCaracters(ecs::WorldManager *worldManager, irr::u32 tileSize, irr::u32 nbTile, std::vector<ecs::component::Player> players)
{
    irr::f32 offset = tileSize / 2;
    std::vector<irr::core::vector3df> caracterPositions = {
        irr::core::vector3df(tileSize + offset, 5.0, tileSize + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 5.0, tileSize + offset),
        irr::core::vector3df(tileSize + offset, 0.0, tileSize * (nbTile - 2) + offset),
        irr::core::vector3df(tileSize * (nbTile - 2) + offset, 5.0, tileSize * (nbTile - 2) + offset)};

    for (size_t i = 0; i < 4; i++) {
        if (i < players.size()) {
            createPlayer(worldManager, players[i], caracterPositions[i]);
        }
        else {
            createBot(worldManager, caracterPositions[i]);
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
                    wall_mesh->setMaterialTexture(0, driver->getTexture("./media/min_brick.png"));
                    wall_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wall_mesh->setPosition(irr::core::vector3df((x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wall_mesh));
                    worldManager->addComponent<ecs::component::Unbreakable>(wall, ecs::component::Unbreakable());
                }
            }
            else if (tileMap[y][x] == '*') {
                {
                    ecs::Entity wall = worldManager->createEntity();
                    irr::scene::ISceneNode *wall_mesh = smgr->addCubeSceneNode(tileSize);
                    wall_mesh->setMaterialTexture(0, driver->getTexture("./media/box.jpg"));
                    wall_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    wall_mesh->setPosition(irr::core::vector3df((x * tileSize) + (tileSize / 2), tileSize / 2, (y * tileSize) + (tileSize / 2)));
                    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wall_mesh));
                }
            }
        }
    }
}

void scene::Bomberman::init(ecs::WorldManager *worldManager, std::vector<ecs::component::Player> players)
{
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    irr::core::vector3df ground_pos;
    irr::f32 tileSize = 10.0;
    irr::u32 nbTile = 13;

    worldManager->registerComponent<ecs::component::Render3d>();
    worldManager->registerComponent<ecs::component::Transform>();
    worldManager->registerComponent<ecs::component::Unbreakable>();
    worldManager->registerComponent<ecs::component::AI>();

    worldManager->registerSystem<ecs::system::Render>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Render3d>());
        worldManager->setSystemSignature<ecs::system::Render>(signature);
    }

    // irr::scene::ISceneNode *cube = smgr->addCubeSceneNode();
    // cube->setPosition(irr::core::vector3df(0.0, 0.0, 0.0));
    // cube->setMaterialTexture(0, driver->getTexture("./media/not_a_petite_fille.png"));
    // cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    // irr::scene::ISceneNode *sphere = smgr->addSphereSceneNode();
    // sphere->setPosition(irr::core::vector3df((nbTile * tileSize) / 2, 0.0, 0.0));
    // sphere->setMaterialTexture(0, driver->getTexture("./media/not_a_petite_fille.png"));
    // sphere->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    // irr::scene::ISceneNode *lil_cube = smgr->addCubeSceneNode(5.0);
    // lil_cube->setPosition(irr::core::vector3df(0.0, 0.0, (nbTile * tileSize) / 2));
    // lil_cube->setMaterialTexture(0, driver->getTexture("./media/not_a_petite_fille.png"));
    // lil_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    ecs::Entity ground = worldManager->createEntity();
    irr::scene::IMeshSceneNode *ground_mesh = smgr->addMeshSceneNode(smgr->getGeometryCreator()->createPlaneMesh(irr::core::dimension2df(tileSize, tileSize), irr::core::dimension2du(nbTile, nbTile)));
    if (ground_mesh) {
        smgr->getMeshManipulator()->makePlanarTextureMapping(ground_mesh->getMesh(), 0.1f, 0.1f, 1, irr::core::vector3df(0.0, 0.0, 5.0));
        ground_mesh->setMaterialTexture(0, driver->getTexture("./media/min_grass.png"));
        ground_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        ground_pos = ground_mesh->getPosition();
        ground_pos.X = ground_pos.X + ((tileSize * nbTile) / 2);
        ground_pos.Z = ground_pos.Z + ((tileSize * nbTile) / 2);
        ground_mesh->setPosition(ground_pos);
    }
    worldManager->addComponent<ecs::component::Render3d>(ground, ecs::component::Render3d(ground_mesh));
    worldManager->addComponent<ecs::component::Transform>(ground, ecs::component::Transform(ground_mesh->getPosition()));

    ecs::Entity camera = worldManager->createEntity();
    irr::scene::ICameraSceneNode *camera_node = smgr->addCameraSceneNodeFPS();
    if (camera_node) {
        camera_node->setPosition(irr::core::vector3df((tileSize * nbTile) * 0.7, 125.0, (tileSize * nbTile) / 2));
        camera_node->setTarget(ground_mesh->getPosition());
    }
    worldManager->addComponent<ecs::component::Render3d>(camera, ecs::component::Render3d(camera_node));

    createMap(worldManager, tileSize);

    createCaracters(worldManager, tileSize, nbTile, players);
}