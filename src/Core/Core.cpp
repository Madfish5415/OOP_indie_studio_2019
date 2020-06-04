/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core.cpp
*/

#include "../scene/PlayerSelector.hpp"
#include "../scene/Menu.hpp"

#include "Core.hpp"

using namespace core;

Core::Core()
{
    _universe = std::make_unique<ecs::Universe>();
}

Core::~Core() = default;

void Core::init()
{
    scene::Menu::init();
    scene::PlayerSelector::init();
    _universe->setCurrentWorldManager("Menu");
}

[[noreturn]] void Core::run()
{
    while (true) {
        _universe->getCurrentWorldManager()->updateSystem();
    }
}
