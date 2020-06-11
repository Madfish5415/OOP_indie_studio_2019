/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Settings.cpp
*/

#include "Settings.hpp"

#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/Music.hpp"
#include "../ecs/component/PushButton.hpp"
#include "../ecs/component/Sound.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Music.hpp"
#include "../ecs/system/Render.hpp"

std::vector<ecs::Entity> scene::Settings::buttons = {};
std::vector<ecs::Entity> scene::Settings::pushButtons = {};
std::vector<ecs::Entity> scene::Settings::images = {};

float scene::Settings::soundVolume = 50;
float scene::Settings::musicVolume = 50;

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
    scene::Settings::buttons.push_back(button);
}

static ecs::Entity createPushButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
                                    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const std::string& normalImage,
                                    const std::string& setPressedImage)
{
    ecs::Entity button = worldManager->createEntity();
    auto videoDriver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    auto buttonComp = ecs::component::PushButton(gui, rect, parent, id, L"", L"");

    buttonComp.setImage(videoDriver->getTexture(normalImage.c_str()));
    buttonComp.setPressedImage(videoDriver->getTexture(setPressedImage.c_str()));
    worldManager->addComponent<ecs::component::PushButton>(button, buttonComp);
    scene::Settings::pushButtons.push_back(button);

    return button;
}

void scene::Settings::init(ecs::Universe* universe)
{
    auto worldManager = universe->createWorldManager("Settings");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::PushButton>();
    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Music>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Music>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Music>());
        worldManager->setSystemSignature<ecs::system::Music>(signature);
    }
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }
    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, settings::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));
    images.push_back(background);

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 630, 835 + 250, 630 + 100), nullptr, BUTTON_ID::GUI_SETTINGS_BACK, settings::button::back::NORMAL,
        settings::button::back::HOVER, settings::button::back::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(0, 0, 0, 0), nullptr, BUTTON_ID::GUI_SETTINGS_MUSIC_VOL_MINUS, settings::button::minus::NORMAL,
                 settings::button::minus::HOVER, settings::button::minus::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(0, 0, 0, 0), nullptr, BUTTON_ID::GUI_SETTINGS_MUSIC_VOL_PLUS, settings::button::plus::NORMAL,
                 settings::button::plus::HOVER, settings::button::plus::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(0, 0, 0, 0), nullptr, BUTTON_ID::GUI_SETTINGS_MUSIC_VOL_MINUS, settings::button::minus::NORMAL,
                 settings::button::minus::HOVER, settings::button::minus::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(0, 0, 0, 0), nullptr, BUTTON_ID::GUI_SETTINGS_MUSIC_VOL_PLUS, settings::button::plus::NORMAL,
                 settings::button::plus::HOVER, settings::button::plus::PRESSED);
}

void scene::Settings::destroy(ecs::Universe* universe)
{
    for (auto& entity : scene::Settings::images) {
        auto& img = universe->getWorldManager("Settings")->getComponent<ecs::component::Image>(entity);
        img.image->remove();
    }
    for (auto& entity : scene::Settings::buttons) {
        auto& btn = universe->getWorldManager("Settings")->getComponent<ecs::component::Button>(entity);
        btn.button->remove();
    }
    for (auto& entity : scene::Settings::pushButtons) {
        auto& btn = universe->getWorldManager("Settings")->getComponent<ecs::component::PushButton>(entity);
        btn.button->remove();
    }

    universe->deleteWorldManager("Settings");
    images.clear();
    buttons.clear();
    pushButtons.clear();
}