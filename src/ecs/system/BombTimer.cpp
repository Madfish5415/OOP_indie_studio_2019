/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#include "BombTimer.hpp"

#include "../../scene/Bomberman.hpp"
#include "../Universe.hpp"
#include "../component/BombTimer.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/Render3d.hpp"

using namespace ecs::system;

BombTimer::BombTimer(ecs::WorldManager *worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

BombTimer::~BombTimer() = default;

void BombTimer::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
    std::vector<ecs::Entity> entitiesDelete = {};

    for (const auto& entity : entities) {
        auto& timer = worldManager->getComponent<ecs::component::BombTimer>(entity);

        if (timer.lastUpdate == 0) {
            timer.lastUpdate = time;
        } else {
            timer.elapsed += time - timer.lastUpdate;
            timer.lastUpdate = time;
            if (timer.elapsed >= timer.delay)
                timer.elapsed = timer.delay;
        }

        auto diff = timer.delay - timer.elapsed;

        if (diff == 0) {
            auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);
            auto& boundingBox = worldManager->getComponent<ecs::component::BoundingBox>(entity);
            auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

            for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                metaTriangleSelector->removeTriangleSelector(boundingBox.selector);
            smgr->addToDeletionQueue(render3d.node);
            smgr->addToDeletionQueue(boundingBox.mesh);
            entitiesDelete.push_back(entity);
        }
    }
    for (auto& entity : entitiesDelete) {
        worldManager->destroyEntity(entity);
    }
}