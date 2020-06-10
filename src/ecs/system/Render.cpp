/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Render
*/

#include "Render.hpp"

#include "../Universe.hpp"

using namespace ecs::system;

Render::Render(WorldManager *worldManager) : ecs::System(worldManager)
{
    irr::IrrlichtDevice *device = worldManager->getUniverse()->getDevice();

    smgr = device->getSceneManager();
    gui = device->getGUIEnvironment();
}

Render::~Render() = default;

void Render::update()
{
    if (smgr)
        smgr->drawAll();
    if (gui)
        gui->drawAll();
}