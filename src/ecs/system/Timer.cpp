/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

#include "../Universe.hpp"
#include "../component/Timer.hpp"

using namespace ecs::system;

Timer::Timer(WorldManager* worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

Timer::~Timer() = default;

void Timer::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();

    for (const auto& entity : entities) {
        auto& timer = worldManager->getComponent<ecs::component::Timer>(entity);

        if (timer.lastUpdate == 0) {
            timer.lastUpdate = time;
        } else {
            timer.elapsed += time - timer.lastUpdate;
            timer.lastUpdate = time;
            if (timer.elapsed >= timer.delay)
                timer.elapsed = timer.delay;
        }
    }
}