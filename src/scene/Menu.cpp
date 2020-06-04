/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Image.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

static void createButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const wchar_t* text,
    const wchar_t* tooltipText = nullptr)
{
    ecs::Entity button = worldManager->createEntity();
    worldManager->addComponent<ecs::component::Button>(
        button, ecs::component::Button(gui, rect, parent, id, text, tooltipText));
}

void Menu::init(ecs::WorldManager* worldManager)
{
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Image>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Image>());
        worldManager->setSystemSignature<ecs::system::Image>(signature);
    }
    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(driver, "./assets/background.jpg", new irr::core::position2d<irr::s32> {0, 0},
            new irr::core::rect<irr::s32> {0, 0, 1920, 1080}));
    ecs::Entity bombermanLogo = worldManager->createEntity();
    worldManager->addComponent(bombermanLogo,
        ecs::component::Image(driver, "./assets/bomberman_logo.png", new irr::core::position2d<irr::s32> {960 - 364, 100},
            new irr::core::rect<irr::s32> {0, 0, 728, 202}));
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(400 - 200, 800, 400 + 200, 800 + 60), nullptr,
        GUI_MENU_PLAY, L"PLAY");
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 200, 800, 960 + 200, 800 + 60), nullptr,
        GUI_MENU_QUIT, L"QUIT");
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1520 - 200, 800, 1520 + 200, 800 + 60), nullptr,
        GUI_MENU_HTP, L"HOW TO PLAY");
}
