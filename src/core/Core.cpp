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
    scene::Bomberman::init(_universe->getWorldManager("Bomberman"), std::vector<ecs::component::Player>());
    //scene::PlayerSelector::init();
    // _universe->setCurrentWorldManager("Menu");
    _universe->setCurrentWorldManager("Bomberman");
}

void Core::run()
{
    irr::IrrlichtDevice *device = _universe->getDevice();
    irr::core::vector3df posCam = device->getSceneManager()->getActiveCamera()->getPosition();

    while (_universe->getDevice()->run()) {
        wchar_t titre[100];
        posCam = device->getSceneManager()->getActiveCamera()->getPosition();
        swprintf(titre, 100, L"X : %f Y : %f Z : %f", posCam.X, posCam.Y, posCam.Z);
        device->setWindowCaption(titre);
        _universe->getDevice()->getVideoDriver()->beginScene();
        _universe->getCurrentWorldManager()->updateSystem();
        _universe->getDevice()->getVideoDriver()->endScene();
    }
}
