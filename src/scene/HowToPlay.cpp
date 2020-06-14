/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** HowToPlay.cpp
*/

#include "HowToPlay.hpp"

#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/Music.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Music.hpp"
#include "../ecs/system/Render.hpp"
#include "Menu.hpp"

using namespace scene;

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

    return button;
}

void HowToPlay::init(ecs::Universe* universe, sf::Time musicTimer)
{
    auto worldManager = universe->createWorldManager("HowToPlay");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Music>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }
    worldManager->registerSystem<ecs::system::Music>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Music>());
        worldManager->setSystemSignature<ecs::system::Music>(signature);
    }

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, scene::howtoplay::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    ecs::Entity music = worldManager->createEntity();
    worldManager->addComponent(music, ecs::component::Music(scene::menu::MUSIC, musicTimer));

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(175 - 125, 40, 175 + 125, 40 + 100), nullptr,
        GUI_HTP_MENU, howtoplay::button::back::NORMAL, howtoplay::button::back::HOVER,
        howtoplay::button::back::PRESSED);
}

void HowToPlay::destroy(ecs::Universe* universe)
{
    universe->deleteWorldManager("HowToPlay");
    universe->getDevice()->getGUIEnvironment()->clear();
}
