/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Pause.cpp
*/

#include "Pause.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Render.hpp"

std::vector<ecs::Entity> scene::Pause::buttons = {};
std::vector<ecs::Entity> scene::Pause::images = {};

static ecs::Entity createButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
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
    scene::Pause::buttons.push_back(button);

    return button;
}

void scene::Pause::init(ecs::Universe* universe)
{
    auto worldManager = universe->createWorldManager("Pause");
    auto gui = universe->getDevice()->getGUIEnvironment();
    auto driver = universe->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::Image>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }

    universe->getDevice()->getTimer()->stop();

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, scene::pause::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));
    images.push_back(background);

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 370, 835 + 250, 370 + 100), nullptr,
        GUI_PAUSE_RESUME, pause::button::resume::NORMAL, pause::button::resume::HOVER, pause::button::resume::PRESSED);

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 500, 835 + 250, 500 + 100), nullptr,
        GUI_PAUSE_SETTINGS, pause::button::settings::NORMAL, pause::button::settings::HOVER,
        pause::button::settings::PRESSED);

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 630, 835 + 250, 630 + 100), nullptr,
        GUI_PAUSE_MENU, pause::button::menu::NORMAL, pause::button::menu::HOVER, pause::button::menu::PRESSED);
}

void scene::Pause::destroy(ecs::Universe* universe)
{
    for (const auto& entity : scene::Pause::images) {
        auto& img = universe->getWorldManager("Pause")->getComponent<ecs::component::Image>(entity);
        img.image->remove();
    }
    for (const auto& entity : scene::Pause::buttons) {
        auto& btn = universe->getWorldManager("Pause")->getComponent<ecs::component::Button>(entity);
        btn.button->remove();
    }

    universe->deleteWorldManager("Pause");
    images.clear();
    buttons.clear();
    universe->getDevice()->getTimer()->start();
}
