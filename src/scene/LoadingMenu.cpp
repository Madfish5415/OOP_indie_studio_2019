/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** LoadingMenu.cpp
*/

#include "LoadingMenu.hpp"

#include "../ecs/component/Blink.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Blink.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

void LoadingMenu::init(ecs::Universe *universe)
{
    auto worldManager = universe->createWorldManager("LoadingMenu");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Blink>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Blink>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Blink>());
        signature.set(worldManager->getComponentType<ecs::component::Image>());
        worldManager->setSystemSignature<ecs::system::Blink>(signature);
    }

    auto logo = worldManager->createEntity();
    worldManager->addComponent(logo,
                               ecs::component::Image(gui, driver, loadingmenu::LOGO, new irr::core::position2d<irr::s32> {720, 50}));

    auto text = worldManager->createEntity();
    worldManager->addComponent(text,
                               ecs::component::Image(gui, driver, loadingmenu::TEXT, new irr::core::position2d<irr::s32> {410, 730}));
    worldManager->addComponent(text, ecs::component::Blink(600));

    irr::gui::IGUIInOutFader* fader = universe->getDevice()->getGUIEnvironment()->addInOutFader();
    fader->setColor(irr::video::SColor(0,0,0,0));
    fader->fadeIn(10000);
}

void LoadingMenu::destroy(ecs::Universe *universe)
{
    universe->deleteWorldManager("LoadingMenu");
    universe->getDevice()->getGUIEnvironment()->clear();
}
