/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

#include "../WorldManager.hpp"
#include "../component/Position.hpp"
#include "../component/Velocity.hpp"

using namespace ecs::system;

Motion::Motion(ecs::WorldManager* worldManager) : System(worldManager)
{
}

Motion::~Motion() = default;

void Motion::update()
{
    for (const auto& entity : entities) {
        auto& position = worldManager->getComponent<ecs::component::Position>(entity);
        auto& velocity = worldManager->getComponent<ecs::component::Velocity>(entity);

        position.x += velocity.x;
        position.y += velocity.y;
        velocity.x = 0;
        velocity.y = 0;

        if (position.x < 1)
            position.x = 1;
        if (position.x > 11)
            position.x = 11;
        if (position.y < 1)
            position.y = 1;
        if (position.y > 11)
            position.y = 11;
    }
}