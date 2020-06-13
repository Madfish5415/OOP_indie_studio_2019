/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ExplosionDelay
*/

#include "ExplosionDelay.hpp"

#include "../../scene/Bomberman.hpp"
#include "../component/BombStats.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/Breakable.hpp"
#include "../component/Delay.hpp"
#include "../component/Image.hpp"
#include "../component/Owner.hpp"
#include "../component/Particle.hpp"
#include "../component/PlayerId.hpp"
#include "../component/Render3d.hpp"
#include "../component/Sound.hpp"
#include "../component/ToDelete.hpp"
#include "BombTimer.hpp"

using namespace ecs::system;

ExplosionDelay::ExplosionDelay(ecs::WorldManager* worldManager) : System(worldManager)
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();

    time = timer->getTime();
}

ExplosionDelay::~ExplosionDelay() = default;

static void explodeObjects(ecs::WorldManager* worldManager, ecs::component::Render3d& render)
{
    std::vector<ecs::Entity> breakableBoxes = worldManager->getEntities<ecs::component::Breakable>();
    const auto& pos = render.node->getPosition();
    auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

    for (const auto& entity : breakableBoxes) {
        auto& boxRender = worldManager->getComponent<ecs::component::Render3d>(entity);
        const auto& boxPos = boxRender.node->getPosition();

        if (pos == boxPos || boxPos == irr::core::vector3d<irr::f32>(pos.X, 4, pos.Z)) {
            try {
                auto& boundingBox = worldManager->getComponent<ecs::component::BoundingBox>(entity);
                auto& bombStats = worldManager->getComponent<ecs::component::BombStats>(entity);

                if (!bombStats.explode) {
                    bombStats.explode = true;
                    BombTimer::explode(worldManager, entity);
                } else {
                    continue;
                }

                for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                    metaTriangleSelector->removeTriangleSelector(boundingBox.selector);
                smgr->addToDeletionQueue(boundingBox.mesh);
            } catch (std::exception& e) {
                if (rand() % 3 == 0) {
                    scene::Bomberman::createPowerUp(worldManager->getUniverse(), pos);
                }
            }
            for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                metaTriangleSelector->removeTriangleSelector(boxRender.node->getTriangleSelector());
            smgr->addToDeletionQueue(boxRender.node);
            worldManager->destroyEntity(entity);
        }
    }
}

static void explodePlayers(ecs::WorldManager* worldManager, ecs::component::Render3d& render)
{
    std::vector<ecs::Entity> players = worldManager->getEntities<ecs::component::PlayerId>();

    const auto& pos = render.node->getPosition();
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

void ExplosionDelay::update()
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();
    std::vector<ecs::Entity> entitiesDelete = {};

    time = timer->getTime();

    for (const auto& entity : entities) {
        auto& delay = worldManager->getComponent<ecs::component::Delay>(entity);
        auto& render = worldManager->getComponent<ecs::component::Render3d>(entity);
        auto& particle = worldManager->getComponent<ecs::component::Particle>(entity);

        explodeObjects(worldManager, render);
        explodePlayers(worldManager, render);

        if (delay.lastUpdate == 0)
            delay.lastUpdate = time;
        if (time - delay.lastUpdate >= delay.value) {
            worldManager->getUniverse()->getDevice()->getSceneManager()->addToDeletionQueue(render.node);
            worldManager->getUniverse()->getDevice()->getSceneManager()->addToDeletionQueue(particle.particleSystem);
            entitiesDelete.push_back(entity);
        }
    }
    for (const auto& entity : entitiesDelete) {
        worldManager->destroyEntity(entity);
    }
}
