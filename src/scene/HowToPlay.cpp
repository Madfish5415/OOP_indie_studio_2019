/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** HowToPlay.cpp
*/

#include "HowToPlay.hpp"

#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/system/Render.hpp"
#include "../ecs/system/Button.hpp"

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

void HowToPlay::init(ecs::Universe *universe)
{
    auto worldManager = universe->createWorldManager("HowToPlay");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::Image>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background, ecs::component::Image(gui, driver, scene::howtoplay::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(175 - 125, 40, 175 + 125, 40 + 100), nullptr,
                 GUI_HTP_MENU, howtoplay::button::back::NORMAL, howtoplay::button::back::HOVER,
                 howtoplay::button::back::PRESSED);
}

void HowToPlay::destroy(ecs::Universe* universe)
{
    universe->deleteWorldManager("HowToPlay");
    universe->getDevice()->getGUIEnvironment()->clear();
}
