/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinChecking
*/

#include "WinChecking.hpp"

#include "../../scene/WinScreen.hpp"
#include "../Universe.hpp"
#include "../component/Music.hpp"
#include "../component/SkinColor.hpp"

using namespace ecs::system;

WinChecking::WinChecking(ecs::WorldManager* worldManager) : System(worldManager)
{
}

WinChecking::~WinChecking() = default;

void WinChecking::update()
{
    ecs::Universe* universe = worldManager->getUniverse();

    if (entities.size() <= 1) {
        auto music = worldManager->getEntities<ecs::component::Music>();

        worldManager->getComponent<ecs::component::Music>(music[0]).music->stop();
        if (entities.empty()) {
            std::string draw = "draw";
            scene::WinScreen::init(universe, draw);
            universe->setCurrentWorldManager("WinScreen");
        } else {
            auto& skinColor = worldManager->getComponent<ecs::component::SkinColor>(*entities.begin());

            scene::WinScreen::init(universe, skinColor.color);
            universe->setCurrentWorldManager("WinScreen");
        }
    }
}
