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
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Image.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

static void createButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const irr::io::path& normalImage,
    const irr::io::path& hoverImage, const irr::io::path& setPressedImage)
{
    ecs::Entity button = worldManager->createEntity();
    auto videoDriver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    auto buttonComp = ecs::component::Button(gui, rect, parent, id, L"", L"");

    buttonComp.setImage(videoDriver->getTexture(normalImage));
    buttonComp.setHoverImage(videoDriver->getTexture(hoverImage));
    buttonComp.setPressedImage(videoDriver->getTexture(setPressedImage));
    worldManager->addComponent<ecs::component::Button>(button, buttonComp);
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
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(driver, "./assets/img/background.jpg", new irr::core::position2d<irr::s32> {0, 0},
            new irr::core::rect<irr::s32> {0, 0, 1920, 1080}));

    ecs::Entity bombermanLogo = worldManager->createEntity();
    worldManager->addComponent(bombermanLogo,
        ecs::component::Image(driver, "./assets/img/bomberman_logo.png",
            new irr::core::position2d<irr::s32>(960 - 640, 0), new irr::core::rect<irr::s32> {0, 0, 1280, 356}, nullptr,
            irr::video::SColor(255, 255, 255, 255), true));

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(400 - 150, 800, 400 + 150, 800 + 150), nullptr,
        GUI_MENU_PLAY, "assets/img/button/button-play-normal.png", "assets/img/button/button-play-hover.png", "assets/img/button/button-play-pressed.png");
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 150, 800, 960 + 150, 800 + 150), nullptr,
        GUI_MENU_HTP, "assets/img/button/button-htp-normal.png", "assets/img/button/button-htp-hover.png", "assets/img/button/button-htp-pressed.png");
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1520 - 150, 800, 1520 + 150, 800 + 150), nullptr,
        GUI_MENU_QUIT, "assets/img/button/button-quit-normal.png", "assets/img/button/button-quit-hover.png",
        "assets/img/button/button-quit-pressed.png");
}
