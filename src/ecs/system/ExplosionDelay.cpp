/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ExplosionDelay
*/

#include "ExplosionDelay.hpp"

#include "../component/Render3d.hpp"
#include "../component/Delay.hpp"
#include "../Universe.hpp"

using namespace ecs::system;


ExplosionDelay::ExplosionDelay(ecs::WorldManager *worldManager) : System(worldManager)
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();

    time = timer->getTime();
}

ExplosionDelay::~ExplosionDelay() = default;

void ExplosionDelay::update()
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();

    time = timer->getTime();

    for (const auto& entity : entities) {
        auto& delay = worldManager->getComponent<ecs::component::Delay>(entity);
        auto& render = worldManager->getComponent<ecs::component::Render3d>(entity);

        if (time - delay.lastUpdate > delay.value) {
            render.node->setScale(irr::core::vector3df(3, 3, 3));
        }
    }
}
