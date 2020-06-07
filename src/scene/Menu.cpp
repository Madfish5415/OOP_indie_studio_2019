/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

#include <irrlicht.h>

#include "../ecs/Universe.hpp"
#include "../ecs/component/Blink.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Blink.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

static void createButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const std::string& normalImage,
                         const std::string& hoverImage, const std::string& setPressedImage)
{
    ecs::Entity button = worldManager->createEntity();
    auto videoDriver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    auto buttonComp = ecs::component::Button(gui, rect, parent, id, L"", L"");

    buttonComp.setImage(videoDriver->getTexture(normalImage.c_str()));
    buttonComp.setHoverImage(videoDriver->getTexture(hoverImage.c_str()));
    buttonComp.setPressedImage(videoDriver->getTexture(setPressedImage.c_str()));
    worldManager->addComponent<ecs::component::Button>(button, buttonComp);
}

void Menu::init(ecs::Universe* universe)
{
    auto worldManager = universe->createWorldManager("Menu");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Blink>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }
    worldManager->registerSystem<ecs::system::Blink>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Blink>());
        signature.set(worldManager->getComponentType<ecs::component::Image>());
        worldManager->setSystemSignature<ecs::system::Blink>(signature);
    }

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, scene::menu::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    ecs::Entity bombermanLogo = worldManager->createEntity();
    worldManager->addComponent(bombermanLogo,
        ecs::component::Image(gui, driver, scene::menu::BOMBERMAN_LOGO, new irr::core::position2d<irr::s32>(960 - 640, 0)));
    worldManager->addComponent(bombermanLogo, ecs::component::Blink(500));

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(400 - 150, 800, 400 + 150, 800 + 150), nullptr,
        GUI_MENU_PLAY, menu::button::play::NORMAL, menu::button::play::HOVER, menu::button::play::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 150, 800, 960 + 150, 800 + 150), nullptr,
        GUI_MENU_HTP, menu::button::htp::NORMAL, menu::button::htp::HOVER, menu::button::htp::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1520 - 150, 800, 1520 + 150, 800 + 150), nullptr,
        GUI_MENU_QUIT, menu::button::quit::NORMAL, menu::button::quit::HOVER, menu::button::quit::PRESSED);
}

void Menu::destroy(ecs::Universe* universe)
{
    universe->deleteWorldManager("Menu");
    universe->getDevice()->getGUIEnvironment()->clear();
}