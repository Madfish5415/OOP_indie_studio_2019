/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Shrink
*/

#include "Shrink.hpp"

#include "../../scene/Bomberman.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/Breakable.hpp"
#include "../component/Collision.hpp"
#include "../component/Image.hpp"
#include "../component/Owner.hpp"
#include "../component/PlayerId.hpp"
#include "../component/Render3d.hpp"
#include "../component/Sound.hpp"
#include "../component/Spinner.hpp"
#include "../component/Stats.hpp"
#include "../component/ToDelete.hpp"
#include "../component/Unbreakable.hpp"

using namespace ecs::system;

Shrink::Shrink(ecs::WorldManager* worldManager) : System(worldManager)
{
    shrink = false;
    shrinkMaxSize = {11, 11};
    shrinkSize = {0, 0};
    shrinkDirection = {"up", "down"};
    shrinkPosition = {irr::core::vector3d<irr::f32>(125, 5, 15), irr::core::vector3d<irr::f32>(5, 5, 115)};
    delay = 1000;
    lastUpdate = 0;
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

Shrink::~Shrink() = default;

static void destroyObjects(ecs::WorldManager* worldManager, const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> breakableBoxes = worldManager->getEntities<ecs::component::Breakable>();
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

    for (const auto& entity : breakableBoxes) {
        auto& boxRender = worldManager->getComponent<ecs::component::Render3d>(entity);
        const auto& boxPos = boxRender.node->getPosition();

        if (pos == boxPos || boxPos == irr::core::vector3d<irr::f32>(pos.X, 4, pos.Z)) {
            try {
                auto& boundingBox = worldManager->getComponent<ecs::component::BoundingBox>(entity);

                for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                    metaTriangleSelector->removeTriangleSelector(boundingBox.selector);
                smgr->addToDeletionQueue(boundingBox.mesh);
            } catch (std::exception& e) {
            }
            for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                metaTriangleSelector->removeTriangleSelector(boxRender.node->getTriangleSelector());
            smgr->addToDeletionQueue(boxRender.node);
            worldManager->destroyEntity(entity);
        }
    }
}

static void destroyPlayers(ecs::WorldManager* worldManager, const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> players = worldManager->getEntities<ecs::component::PlayerId>();
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

    int idx = 0;
    for (const auto& entity : players) {
        auto& playerRender = worldManager->getComponent<ecs::component::Render3d>(entity);
        const auto& playerPos = playerRender.node->getPosition();

        irr::core::vector3d<irr::f32> ajustedPos = playerPos;
        ajustedPos.X = static_cast<irr::f32>(static_cast<int>(playerPos.X / 10.f) * 10 + 5);
        ajustedPos.Y = playerPos.Y;
        ajustedPos.Z = static_cast<irr::f32>(static_cast<int>(playerPos.Z / 10.f) * 10 + 5);

        if (pos.X == ajustedPos.X && pos.Z == ajustedPos.Z) {
            std::vector<ecs::Entity> imageEntities =
                worldManager->getEntities<ecs::component::Image, ecs::component::Owner>();
            auto sounds = worldManager->getEntities<ecs::component::Sound, ecs::component::ToDelete>();
            auto& sound = worldManager->getComponent<ecs::component::Sound>(sounds[0]);

            sound.soundsToPlay.emplace_back("death");

            for (const auto& imageEnt : imageEntities) {
                auto& owner = worldManager->getComponent<ecs::component::Owner>(imageEnt);

                if (owner.entity == entity) {
                    auto& image = worldManager->getComponent<ecs::component::Image>(imageEnt);

                    image.image->remove();
                    worldManager->destroyEntity(imageEnt);
                }
            }
            smgr->addToDeletionQueue(playerRender.node);
            worldManager->destroyEntity(entity);
        }
        idx++;
    }
}

static void destroyPowerUp(ecs::WorldManager* worldManager, const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> powerUp = worldManager->getEntities<ecs::component::Spinner, ecs::component::Stats>();
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

    for (const auto& entity : powerUp) {
        auto& powerRender = worldManager->getComponent<ecs::component::Render3d>(entity);
        const auto& powerPos = powerRender.node->getPosition();

        if (pos.X == powerPos.X && pos.Z == powerPos.Z) {
            smgr->addToDeletionQueue(powerRender.node);
            worldManager->destroyEntity(entity);
        }
    }
}

static void createWall(ecs::WorldManager* worldManager, const irr::core::vector3d<irr::f32>& pos)
{
    ecs::Entity wall = worldManager->createEntity();
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    irr::scene::IMeshSceneNode* wallMesh = smgr->addCubeSceneNode(10);

    irr::scene::ITriangleSelector* selector = smgr->createOctreeTriangleSelector(wallMesh->getMesh(), wallMesh, 128);
    wallMesh->setTriangleSelector(selector);
    for (auto& metaSelector : scene::Bomberman::metaTriangleSelector)
        metaSelector->addTriangleSelector(selector);
    selector->drop();

    wallMesh->setMaterialTexture(0, driver->getTexture(scene::bomberman::map::WALL.c_str()));
    wallMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    wallMesh->setPosition(pos);
    worldManager->addComponent<ecs::component::Render3d>(wall, ecs::component::Render3d(wallMesh));
    worldManager->addComponent<ecs::component::Unbreakable>(wall, ecs::component::Unbreakable());
    worldManager->addComponent<ecs::component::Collision>(wall, ecs::component::Collision());
}

void Shrink::update()
{
    if (!shrink)
        return;

    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();

    if (lastUpdate == 0) {
        lastUpdate = time;
    } else if (time - lastUpdate >= delay) {
        lastUpdate = time;
        for (int i = 0; i < 2; i++) {
            irr::core::vector3d<irr::f32> addPos(0, 0, 0);

            if (shrinkDirection[i] == "up") {
                addPos.X -= 10;
            } else if (shrinkDirection[i] == "down") {
                addPos.X += 10;
            } else if (shrinkDirection[i] == "left") {
                addPos.Z -= 10;
            } else if (shrinkDirection[i] == "right") {
                addPos.Z += 10;
            }
            shrinkSize[i]++;
            shrinkPosition[i] += addPos;
            if (shrinkSize[i] == shrinkMaxSize[i]) {
                shrinkSize[i] = 0;
                if (shrinkDirection[i] == "up") {
                    shrinkMaxSize[i] = shrinkMaxSize[i] - 2;
                    shrinkDirection[i] = "right";
                } else if (shrinkDirection[i] == "down") {
                    shrinkMaxSize[i] = shrinkMaxSize[i] - 2;
                    shrinkDirection[i] = "left";
                } else if (shrinkDirection[i] == "left") {
                    shrinkDirection[i] = "up";
                } else if (shrinkDirection[i] == "right") {
                    shrinkDirection[i] = "down";
                }
            }
            destroyObjects(worldManager, shrinkPosition[i]);
            destroyPlayers(worldManager, shrinkPosition[i]);
            destroyPowerUp(worldManager, shrinkPosition[i]);
            createWall(worldManager, shrinkPosition[i]);
        }
    }
    if (shrinkMaxSize[0] < 1 || shrinkMaxSize[1] < 1)
        shrink = false;
}

void Shrink::startShrinking(ecs::event::TimerEnd& event)
{
    shrink = true;
}
