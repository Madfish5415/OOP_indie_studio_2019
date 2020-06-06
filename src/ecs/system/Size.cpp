/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Size
*/

#include "Size.hpp"
#include "../Universe.hpp"

#include "../component/Size.hpp"
#include "../component/Render3d.hpp"


using namespace ecs::system;

Size::Size(WorldManager *worldManager) : ecs::System(worldManager)
{
}

Size::~Size() = default;

void Size::update() 
{
    for (const auto& entity : entities) {
        auto& node = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        auto& size = worldManager->getComponent<ecs::component::Size>(entity).size;
        if (node->getScale() != size) {
            node->setScale(size);
        }
    }
}