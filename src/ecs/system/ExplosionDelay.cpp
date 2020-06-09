/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ExplosionDelay
*/

#include "ExplosionDelay.hpp"

#include <iostream>

#include "../../scene/Bomberman.hpp"
#include "../Universe.hpp"
#include "../component/BombStats.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/Breakable.hpp"
#include "../component/Delay.hpp"
#include "../component/Particle.hpp"
#include "../component/Render3d.hpp"
#include "BombTimer.hpp"

using namespace ecs::system;


ExplosionDelay::ExplosionDelay(ecs::WorldManager *worldManager) : System(worldManager)
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
            }
            for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                metaTriangleSelector->removeTriangleSelector(boxRender.node->getTriangleSelector());
            smgr->addToDeletionQueue(boxRender.node);
            worldManager->destroyEntity(entity);
        }
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
