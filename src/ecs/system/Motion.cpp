/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

#include "../component/Motion.hpp"
#include "../component/Transform.hpp"

ecs::system::Motion::Motion(ecs::WorldManager* worldManager) : System(worldManager)
{
}

ecs::system::Motion::~Motion() = default;

void ecs::system::Motion::update()
{
    for (const auto& entity : entities) {
        auto& motion = worldManager->getComponent<ecs::component::Motion>(entity);
        auto& tranform = worldManager->getComponent<ecs::component::Transform>(entity);

        tranform.position += motion.direction * motion.movementSpeed;
    }
}