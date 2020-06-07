/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Blink.cpp
*/

#include "Blink.hpp"

#include "../component/Blink.hpp"
#include "../component/Image.hpp"
#include "../Universe.hpp"

using namespace ecs::system;

Blink::Blink(ecs::WorldManager *worldManager) : System(worldManager)
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();

    time = timer->getTime();
}

Blink::~Blink() = default;

void Blink::update()
{
    auto timer = worldManager->getUniverse()->getDevice()->getTimer();

    time = timer->getTime();

    for (const auto& entity : entities) {
        auto& blink = worldManager->getComponent<ecs::component::Blink>(entity);
        auto& image = worldManager->getComponent<ecs::component::Image>(entity);

        if (time - blink.lastUpdate > blink.millisecond) {
            image.image->setVisible(!image.image->isVisible());
            blink.lastUpdate = time;
        }
    }
}
