/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include "../scene/LoadingMenu.hpp"

using namespace core;

Core::Core()
{
    _universe = std::make_unique<ecs::Universe>();
}

Core::~Core() = default;

void Core::init()
{
    scene::LoadingMenu::init(_universe.get());
    _universe->setCurrentWorldManager("LoadingMenu");
}

void Core::run()
{
    while (_universe->getDevice()->run()) {
        _universe->getDevice()->getVideoDriver()->beginScene();
        _universe->getCurrentWorldManager()->updateSystem();
        _universe->getDevice()->getVideoDriver()->endScene();
    }
}
