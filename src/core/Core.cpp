/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core.cpp
*/

#include "../scene/PlayerSelector.hpp"
#include "../scene/Menu.hpp"
#include "../scene/Bomberman.hpp"

#include "Core.hpp"

using namespace core;

Core::Core()
{
    _universe = std::make_unique<ecs::Universe>();
}

Core::~Core() = default;

void Core::init()
{
    // _universe->createWorldManager("Menu");
    // scene::Menu::init(_universe->getWorldManager("Menu"));
    _universe->createWorldManager("Bomberman");
    scene::Bomberman::init(_universe->getWorldManager("Bomberman"));
    //scene::PlayerSelector::init();
    // _universe->setCurrentWorldManager("Menu");
    _universe->setCurrentWorldManager("Bomberman");
}

void Core::run()
{
    while (_universe->getDevice()->run()) {
        _universe->getDevice()->getVideoDriver()->beginScene();
        _universe->getCurrentWorldManager()->updateSystem();
        _universe->getDevice()->getVideoDriver()->endScene();
    }
}
