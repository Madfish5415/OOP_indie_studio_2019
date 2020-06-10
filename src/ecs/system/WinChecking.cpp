/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinChecking
*/

#include "WinChecking.hpp"

#include "../Universe.hpp"
#include "scene/Bomberman.hpp"
#include "../component/Player.hpp"
#include "../component/AI.hpp"

using namespace ecs::system;

WinChecking::WinChecking(ecs::WorldManager* worldManager) : System(worldManager)
{
}

WinChecking::~WinChecking() = default;

void WinChecking::update()
{
    std::vector<ecs::Entity> entities = worldManager->getEntities<ecs::component::Player, ecs::component::AI>();
    ecs::Universe *universe = worldManager->getUniverse();

    if (entities.size() <= 1) {
        if (entities.size() == 0) {
            //Draw screen
        }
        //Win screen
    }
}
