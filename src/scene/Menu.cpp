/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

static void createButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const wchar_t* text,
    const wchar_t* tooltipText = nullptr)
{
    ecs::Entity button = worldManager->createEntity();
    worldManager->addComponent<ecs::component::Button>(button, ecs::component::Button(gui, rect, parent, id, text, tooltipText));
}

void Menu::init(ecs::WorldManager* worldManager)
{
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerSystem<ecs::system::Render>();
    createButton(
        worldManager, gui, new irr::core::rect<irr::s32>(960 - 200, 300, 960 + 200, 300 + 60), nullptr, GUI_MENU_PLAY, L"PLAY");
    createButton(
        worldManager, gui, new irr::core::rect<irr::s32>(960 - 200, 400, 960 + 200, 400 + 60), nullptr, GUI_MENU_QUIT, L"QUIT");
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 200, 500, 960 + 200, 500 + 60), nullptr, GUI_MENU_HTP,
        L"HOW TO PLAY");
}