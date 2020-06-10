/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinScreen
*/

#include "WinScreen.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Render.hpp"

std::vector<ecs::Entity> scene::WinScreen::images = {};

void scene::WinScreen::init(ecs::Universe *universe)
{
    auto worldManager = universe->createWorldManager("WinScreen");
    auto gui = universe->getDevice()->getGUIEnvironment();
    auto driver = universe->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Image>();

    worldManager->registerSystem<ecs::system::Render>();
    
    universe->getDevice()->getTimer()->stop();

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
    ecs::component::Image(gui, driver, scene::winScreen::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    images.push_back(background);
}

void scene::WinScreen::destroy(ecs::Universe *universe)
{
     for (auto& entity : scene::WinScreen::images) {
        auto& img = universe->getWorldManager("WinScreen")->getComponent<ecs::component::Image>(entity);
        img.image->remove();
    }

    universe->getDevice()->getTimer()->start();
    universe->deleteWorldManager("WinScreen");
    images.clear();
}