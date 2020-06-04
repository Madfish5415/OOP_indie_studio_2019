/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Movement.cpp
*/

#include "Movement.hpp"

#include "../component/Motion.hpp"
#include "../component/Render3d.hpp"
#include "../component/Transform.hpp"

using namespace ecs::system;

Movement::Movement(ecs::WorldManager* worldManager) : System(worldManager)
{
}

Movement::~Movement() = default;

void Movement::update()
{
    for (const auto& entity : entities) {
        auto& node = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        auto& motion = worldManager->getComponent<ecs::component::Motion>(entity);
        auto& tranform = worldManager->getComponent<ecs::component::Transform>(entity);
        tranform.position += motion.direction * motion.movementSpeed;
        node->setPosition(tranform.position);
    }
}