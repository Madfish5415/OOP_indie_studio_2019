/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Spinner.cpp
*/

#include "Spinner.hpp"

#include "../Universe.hpp"
#include "../component/Render3d.hpp"
#include "../component/Spinner.hpp"

using namespace ecs::system;

Spinner::Spinner(ecs::WorldManager* worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

void Spinner::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();

    for (const auto& entity : entities) {
        auto& spinner = worldManager->getComponent<ecs::component::Spinner>(entity);
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        if (spinner.lastUpdate == 0) {
            spinner.lastUpdate = time;
        } else if (time - spinner.lastUpdate > spinner.delay) {
            render3d.node->setRotation(render3d.node->getRotation() + spinner.rotation);
            spinner.lastUpdate = time;
        }
    }
}

Spinner::~Spinner() = default;
