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
    _universe->createWorldManager("Menu");
    scene::Menu::init(_universe->getWorldManager("Menu"));
    //scene::PlayerSelector::init();
    _universe->setCurrentWorldManager("Menu");
}

void Core::run()
{
    while (_universe->getDevice()->run()) {
        _universe->getDevice()->getVideoDriver()->beginScene();
        _universe->getCurrentWorldManager()->updateSystem();
        _universe->getDevice()->getVideoDriver()->endScene();
    }
}
