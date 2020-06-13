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

Sliding::Sliding(ecs::WorldManager* worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
    _then = time;
}

Sliding::~Sliding() = default;

void Sliding::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
    const irr::f32 deltaTime = static_cast<irr::f32>(time - _then) / 1000.f;
    _then = time;

    for (const auto& entity : entities) {
        auto& sliding = worldManager->getComponent<ecs::component::Sliding>(entity);

        if (sliding.lastUpdate == 0) {
            sliding.lastUpdate = time;
        } else if (time - sliding.lastUpdate >= sliding.delay) {
            sliding.lastUpdate = time;

            auto& image = worldManager->getComponent<ecs::component::Image>(entity);
            const auto& pos = image.image->getRelativePosition();

            if (pos.UpperLeftCorner != sliding.endPosition) {
                image.position->X += static_cast<irr::s32>(sliding.addPosition.X * deltaTime);
                image.position->Y += static_cast<irr::s32>(sliding.addPosition.Y * deltaTime);
            }
            if (sliding.addPosition.X < 0) {
                if (image.position->X < sliding.endPosition.X)
                    image.position->X = sliding.endPosition.X;
            } else {
                if (image.position->X > sliding.endPosition.X)
                    image.position->X = sliding.endPosition.X;
            }
            if (sliding.addPosition.Y < 0) {
                if (image.position->Y < sliding.endPosition.Y)
                    image.position->Y = sliding.endPosition.Y;
            } else {
                if (image.position->Y > sliding.endPosition.Y)
                    image.position->Y = sliding.endPosition.Y;
            }
            image.image->setRelativePosition(*image.position);
        }
    }
}
