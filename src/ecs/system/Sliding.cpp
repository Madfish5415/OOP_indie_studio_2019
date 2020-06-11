/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sliding
*/

#include "Sliding.hpp"

#include "../Universe.hpp"
#include "../component/Image.hpp"
#include "../component/Sliding.hpp"

using namespace ecs::system;

Sliding::Sliding(ecs::WorldManager *worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

Sliding::~Sliding() = default;

void Sliding::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();

    for (const auto& entity : entities) {
        auto& sliding = worldManager->getComponent<ecs::component::Sliding>(entity);

        if (sliding.lastUpdate == 0) {
            sliding.lastUpdate = time;
        } else if (time - sliding.lastUpdate >= sliding.delay) {
            sliding.lastUpdate = time;

            auto& image = worldManager->getComponent<ecs::component::Image>(entity);
            const auto& pos = image.image->getRelativePosition();

            if (pos.UpperLeftCorner != sliding.endPosition) {
                image.position->X += sliding.addPosition.X;
                image.position->Y += sliding.addPosition.Y;

                image.image->setRelativePosition(*image.position);
            }
        }
    }
}
