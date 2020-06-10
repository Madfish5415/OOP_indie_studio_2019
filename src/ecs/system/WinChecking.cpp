/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinChecking
*/

#include "WinChecking.hpp"

#include "../Universe.hpp"
#include "../../scene/Bomberman.hpp"
#include "../../scene/WinScreen.hpp"
#include "../../scene/DrawScreen.hpp"
#include "../component/PlayerId.hpp"
#include "../component/Stats.hpp"

#include <iostream>

using namespace ecs::system;

WinChecking::WinChecking(ecs::WorldManager* worldManager) : System(worldManager)
{
}

WinChecking::~WinChecking() = default;

void WinChecking::update()
{
    ecs::Universe *universe = worldManager->getUniverse();

    if (entities.size() <= 1) {
        std::cout << entities.size() << std::endl;
        if (entities.size() == 0) {
            scene::DrawScreen::init(universe);
            universe->setCurrentWorldManager("DrawScreen");
        }
        else {
            scene::WinScreen::init(universe);
            universe->setCurrentWorldManager("WinScreen");
        }
    }
}
