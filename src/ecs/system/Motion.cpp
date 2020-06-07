/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

#include "../Universe.hpp"
#include "../component/Motion.hpp"
#include "../component/Render3d.hpp"
#include "../component/Transform.hpp"

using namespace ecs::system;

Motion::Motion(ecs::WorldManager* worldManager) : System(worldManager)
{
    _then = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

Motion::~Motion() = default;

void Motion::update()
{
    const irr::u32 now = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
    const irr::f32 deltaTime = static_cast<irr::f32>(now - _then) / 1000.f;
    _then = now;

    for (const auto& entity : entities) {
        auto& motion = worldManager->getComponent<ecs::component::Motion>(entity);
        auto& tranform = worldManager->getComponent<ecs::component::Transform>(entity);
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        tranform = render3d.node->getPosition();
        tranform.position += motion.direction * motion.movementSpeed * deltaTime;
    }
}