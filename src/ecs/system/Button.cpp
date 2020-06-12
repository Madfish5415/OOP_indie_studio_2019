/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Button.cpp
*/

#include "Button.hpp"

#include "../Universe.hpp"
#include "../component/Button.hpp"

using namespace ecs::system;

Button::Button(ecs::WorldManager* worldManager) : ecs::System(worldManager)
{
    mouse = worldManager->getUniverse()->getDevice()->getCursorControl();
    driver = worldManager->getUniverse()->getDevice()->getVideoDriver();
}

Button::~Button() = default;

void Button::update()
{
    for (const auto& entity : entities) {
        auto& button = worldManager->getComponent<ecs::component::Button>(entity);
        if (button.button->getRelativePosition().isPointInside(mouse->getPosition())) {
            button.button->setImage(button.hoverImage);
        } else {
            button.button->setImage(button.normalImage);
        }
    }
}