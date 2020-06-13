/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Kebinding.cpp
*/

#include "Keybinding.hpp"

#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/PushButton.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene::keybinding;

ecs::component::Player* scene::Keybinding::player = nullptr;
std::vector<ecs::Entity> scene::Keybinding::buttons = {};
std::vector<ecs::Entity> scene::Keybinding::pushButtons = {};
std::vector<ecs::Entity> scene::Keybinding::images = {};

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
    scene::Keybinding::buttons.push_back(button);

    return button;
}

static ecs::Entity createPushButton(ecs::WorldManager* worldManager, irr::gui::IGUIEnvironment* gui,
    irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent, irr::s32 id, const std::string& normalImage,
    const std::string& setPressedImage)
{
    ecs::Entity button = worldManager->createEntity();
    auto videoDriver = worldManager->getUniverse()->getDevice()->getVideoDriver();
    auto buttonComp = ecs::component::PushButton(gui, rect, parent, id, L"", L"");

    buttonComp.setFont(FONT.c_str());
    buttonComp.setImage(videoDriver->getTexture(normalImage.c_str()));
    buttonComp.setPressedImage(videoDriver->getTexture(setPressedImage.c_str()));
    worldManager->addComponent<ecs::component::PushButton>(button, buttonComp);
    scene::Keybinding::pushButtons.push_back(button);

    return button;
}

void scene::Keybinding::init(ecs::Universe* universe, const std::string& pathTexture, ecs::component::Player* ply)
{
    auto worldManager = universe->createWorldManager("Keybinding");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    Keybinding::player = ply;

    worldManager->registerComponent<ecs::component::Button>();
    worldManager->registerComponent<ecs::component::PushButton>();
    worldManager->registerComponent<ecs::component::Image>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }

    ecs::Entity blackFilter = worldManager->createEntity();
    worldManager->addComponent(blackFilter,
        ecs::component::Image(gui, driver, keybinding::BLACKFILTER, new irr::core::position2d<irr::s32> {0, 0}));
    scene::Keybinding::images.push_back(blackFilter);

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, keybinding::BACKGROUND, new irr::core::position2d<irr::s32> {460, 225}));
    scene::Keybinding::images.push_back(background);

    ecs::Entity playerImage = worldManager->createEntity();
    worldManager->addComponent(playerImage,
        ecs::component::Image(gui, driver, pathTexture, new irr::core::position2d<irr::s32> {460 + 85, 225 + 85}));
    scene::Keybinding::images.push_back(playerImage);

    {
        ecs::Entity entity =
            createPushButton(worldManager, gui, new irr::core::rect<irr::s32>(1230, 350, 1230 + 75, 350 + 75), nullptr,
                GUI_SELECT_KB_UP, keybinding::button::key::NORMAL, keybinding::button::key::PRESSED);
        worldManager->getComponent<ecs::component::PushButton>(entity).setText(
            KEYBINDING_MAP[Keybinding::player->keys["up"]]);
    }
    {
        ecs::Entity entity =
            createPushButton(worldManager, gui, new irr::core::rect<irr::s32>(1230, 427, 1230 + 75, 427 + 75), nullptr,
                GUI_SELECT_KB_DOWN, keybinding::button::key::NORMAL, keybinding::button::key::PRESSED);
        worldManager->getComponent<ecs::component::PushButton>(entity).setText(
            KEYBINDING_MAP[Keybinding::player->keys["down"]]);
    }
    {
        ecs::Entity entity =
            createPushButton(worldManager, gui, new irr::core::rect<irr::s32>(1153, 427, 1153 + 75, 427 + 75), nullptr,
                GUI_SELECT_KB_LEFT, keybinding::button::key::NORMAL, keybinding::button::key::PRESSED);
        worldManager->getComponent<ecs::component::PushButton>(entity).setText(
            KEYBINDING_MAP[Keybinding::player->keys["left"]]);
    }
    {
        ecs::Entity entity =
            createPushButton(worldManager, gui, new irr::core::rect<irr::s32>(1307, 427, 1307 + 75, 427 + 75), nullptr,
                GUI_SELECT_KB_RIGHT, keybinding::button::key::NORMAL, keybinding::button::key::PRESSED);
        worldManager->getComponent<ecs::component::PushButton>(entity).setText(
            KEYBINDING_MAP[Keybinding::player->keys["right"]]);
    }
    {
        ecs::Entity entity =
            createPushButton(worldManager, gui, new irr::core::rect<irr::s32>(1230, 650, 1230 + 75, 650 + 75), nullptr,
                GUI_SELECT_KB_ACTION, keybinding::button::key::NORMAL, keybinding::button::key::PRESSED);
        worldManager->getComponent<ecs::component::PushButton>(entity).setText(
            KEYBINDING_MAP[Keybinding::player->keys["bomb"]]);
    }
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 905, 835 + 250, 905 + 100), nullptr,
        GUI_SELECT_KB_BACK, button::back::NORMAL, button::back::HOVER, button::back::PRESSED);
}

void scene::Keybinding::destroy(ecs::Universe* universe)
{
    for (const auto& entity : scene::Keybinding::images) {
        auto& img = universe->getWorldManager("Keybinding")->getComponent<ecs::component::Image>(entity);
        img.image->remove();
    }
    for (const auto& entity : scene::Keybinding::buttons) {
        auto& btn = universe->getWorldManager("Keybinding")->getComponent<ecs::component::Button>(entity);
        btn.button->remove();
    }
    for (const auto& entity : scene::Keybinding::pushButtons) {
        auto& btn = universe->getWorldManager("Keybinding")->getComponent<ecs::component::PushButton>(entity);
        btn.button->remove();
    }
    universe->deleteWorldManager("Keybinding");

    scene::Keybinding::images.clear();
    scene::Keybinding::buttons.clear();
    scene::Keybinding::pushButtons.clear();
}
