/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** PlayerSelector.cpp
*/

#include "PlayerSelector.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

#include "../ecs/Universe.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/MessageBox.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

std::vector<ecs::Entity> PlayerSelector::playerIds = {};
std::vector<ecs::Entity> PlayerSelector::playerKeysIds = {};
std::vector<ecs::Entity> PlayerSelector::playerSkinButtonLeftIds = {};
std::vector<ecs::Entity> PlayerSelector::playerSkinButtonRightIds = {};
std::vector<ecs::component::Player> PlayerSelector::playerComponent = {};

static const std::string getUnusedSkin()
{
    auto item = playerselector::player::PLAYER_SKINS.begin();

    std::srand(std::time(nullptr));
    while (true) {
        item = playerselector::player::PLAYER_SKINS.begin();
        std::advance(item, std::rand() % playerselector::player::PLAYER_SKINS.size());
        if (!item->second) {
            item->second = true;
            return item->first;
        }
    }
}

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

void PlayerSelector::init(ecs::Universe* universe)
{
    auto worldManager = universe->createWorldManager("PlayerSelector");
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
    worldManager->addComponent(background,
        ecs::component::Image(
            gui, driver, scene::playerselector::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    ecs::Entity frame = worldManager->createEntity();
    worldManager->addComponent(frame,
        ecs::component::Image(
            gui, driver, scene::playerselector::FRAME, new irr::core::position2d<irr::s32> {110, 215}));

    ecs::Entity defaultPlayer = worldManager->createEntity();
    worldManager->addComponent(defaultPlayer,
        ecs::component::Image(gui, driver, getUnusedSkin(), new irr::core::position2d<irr::s32> {960 - 150, 245}));
    playerIds.emplace_back(defaultPlayer);

    ecs::Entity defaultPlayerKeys =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 125, 725, 960 + 125, 725 + 100), nullptr,
            GUI_SELECT_KB_P1, playerselector::button::keys::NORMAL, playerselector::button::keys::HOVER,
            playerselector::button::keys::PRESSED);
    playerKeysIds.emplace_back(defaultPlayerKeys);

    ecs::Entity defaultPlayerSkinButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 600, 835 + 40, 600 + 40), nullptr,
            GUI_SELECT_SKIN_P1_LEFT, playerselector::button::skin::left::NORMAL,
            playerselector::button::skin::left::HOVER, playerselector::button::skin::left::PRESSED);
    playerSkinButtonLeftIds.emplace_back(defaultPlayerSkinButtonLeft);

    ecs::Entity defaultPlayerSkinButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 600, 1045 + 40, 600 + 40), nullptr,
            GUI_SELECT_SKIN_P1_RIGHT, playerselector::button::skin::right::NORMAL,
            playerselector::button::skin::right::HOVER, playerselector::button::skin::right::PRESSED);
    playerSkinButtonRightIds.emplace_back(defaultPlayerSkinButtonRight);

    PlayerSelector::playerComponent.push_back(ecs::component::Player());

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(175 - 125, 50, 175 + 125, 50 + 100), nullptr,
        GUI_SELECT_MENU, playerselector::button::back::NORMAL, playerselector::button::back::HOVER,
        playerselector::button::back::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1745 - 125, 50, 1745 + 125, 50 + 100), nullptr,
        GUI_SELECT_FIGHT, playerselector::button::fight::NORMAL, playerselector::button::fight::HOVER,
        playerselector::button::fight::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(785 - 125, 910, 785 + 125, 910 + 100), nullptr,
        GUI_SELECT_REMOVE_PLAYER, playerselector::button::remove::NORMAL, playerselector::button::remove::HOVER,
        playerselector::button::remove::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1135 - 125, 910, 1135 + 125, 910 + 100), nullptr,
        GUI_SELECT_ADD_PLAYER, playerselector::button::add::NORMAL, playerselector::button::add::HOVER,
        playerselector::button::add::PRESSED);
}

void PlayerSelector::reset()
{
}

void PlayerSelector::destroy(ecs::Universe* universe)
{
    universe->deleteWorldManager("PlayerSelector");
    universe->getDevice()->getGUIEnvironment()->clear();
    PlayerSelector::playerIds.clear();
    PlayerSelector::playerKeysIds.clear();
    PlayerSelector::playerSkinButtonLeftIds.clear();
    PlayerSelector::playerSkinButtonRightIds.clear();
    PlayerSelector::playerComponent.clear();
    for (auto& skin : playerselector::player::PLAYER_SKINS) {
        skin.second = false;
    }
}

void PlayerSelector::addPlayer(ecs::Universe* universe)
{
    if (PlayerSelector::playerIds.size() >= 4)
        return;

    auto worldManager = universe->getWorldManager("PlayerSelector");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    ecs::Entity player = worldManager->createEntity();
    worldManager->addComponent(player,
        ecs::component::Image(gui, driver, getUnusedSkin(), new irr::core::position2d<irr::s32> {960 - 150, 245}));
    playerIds.emplace_back(player);

    ecs::Entity playerKeys =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 125, 725, 960 + 125, 725 + 100), nullptr,
            GUI_SELECT_KB_P1 + (PlayerSelector::playerIds.size() - 1), playerselector::button::keys::NORMAL,
            playerselector::button::keys::HOVER, playerselector::button::keys::PRESSED);
    playerKeysIds.emplace_back(playerKeys);

    ecs::Entity playerSkinButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 600, 835 + 40, 600 + 40), nullptr,
            GUI_SELECT_SKIN_P1_LEFT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::left::NORMAL, playerselector::button::skin::left::HOVER,
            playerselector::button::skin::left::PRESSED);
    playerSkinButtonLeftIds.emplace_back(playerSkinButtonLeft);

    ecs::Entity playerSkinButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 600, 1045 + 40, 600 + 40), nullptr,
            GUI_SELECT_SKIN_P1_RIGHT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::right::NORMAL, playerselector::button::skin::right::HOVER,
            playerselector::button::skin::right::PRESSED);
    playerSkinButtonRightIds.emplace_back(playerSkinButtonRight);

    playerComponent.push_back(ecs::component::Player());

    int idx = 0;
    for (auto& id : PlayerSelector::playerIds) {
        auto& image = worldManager->getComponent<ecs::component::Image>(id);
        int total_player_size = (static_cast<int>(PlayerSelector::playerIds.size())) * 300 +
            (100 * (static_cast<int>(PlayerSelector::playerIds.size()) - 1));

        auto& left = worldManager->getComponent<ecs::component::Button>(playerSkinButtonLeftIds[idx]);
        auto& right = worldManager->getComponent<ecs::component::Button>(playerSkinButtonRightIds[idx]);

        image.position->X = (1920 / 2 - total_player_size / 2) + (idx * 400);
        image.image->setRelativePosition(*image.position);

        left.rect->UpperLeftCorner.X = image.position->X + 25;
        left.rect->LowerRightCorner.X = left.rect->UpperLeftCorner.X + 40;
        left.button->setRelativePosition(*left.rect);

        right.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        right.rect->LowerRightCorner.X = right.rect->UpperLeftCorner.X + 40;
        right.button->setRelativePosition(*right.rect);

        idx++;
    }

    idx = 0;
    for (auto& id : PlayerSelector::playerKeysIds) {
        auto& button = worldManager->getComponent<ecs::component::Button>(id);
        int total_button_size = (static_cast<int>(PlayerSelector::playerKeysIds.size())) * 250 +
            (150 * (static_cast<int>(PlayerSelector::playerKeysIds.size()) - 1));

        button.rect->UpperLeftCorner.X = (1920 / 2 - total_button_size / 2) + (idx * 400);
        button.rect->LowerRightCorner.X = button.rect->UpperLeftCorner.X + 250;
        button.button->setRelativePosition(*button.rect);
        idx++;
    }
}

void PlayerSelector::removePlayer(ecs::Universe* universe)
{
    if (PlayerSelector::playerIds.size() <= 1)
        return;
    auto worldManager = universe->getWorldManager("PlayerSelector");
    {
        auto& button = universe->getWorldManager("PlayerSelector")
                           ->getComponent<ecs::component::Button>(PlayerSelector::playerKeysIds.back());
        button.button->remove();
    }
    {
        auto& button = universe->getWorldManager("PlayerSelector")
                           ->getComponent<ecs::component::Button>(PlayerSelector::playerSkinButtonLeftIds.back());
        button.button->remove();
    }
    {
        auto& button = universe->getWorldManager("PlayerSelector")
                           ->getComponent<ecs::component::Button>(PlayerSelector::playerSkinButtonRightIds.back());
        button.button->remove();
    }

    auto image = universe->getWorldManager("PlayerSelector")
                     ->getComponent<ecs::component::Image>(PlayerSelector::playerIds.back());
    image.image->remove();
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerKeysIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerSkinButtonLeftIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerSkinButtonRightIds.back());

    PlayerSelector::playerIds.pop_back();
    PlayerSelector::playerKeysIds.pop_back();
    PlayerSelector::playerSkinButtonLeftIds.pop_back();
    PlayerSelector::playerSkinButtonRightIds.pop_back();

    for (auto& skin : playerselector::player::PLAYER_SKINS) {
        if (skin.first == image.pathTexture)
            skin.second = false;
    }

    int idx = 0;
    for (auto& id : PlayerSelector::playerIds) {
        auto& image = worldManager->getComponent<ecs::component::Image>(id);
        int total_player_size = (static_cast<int>(PlayerSelector::playerIds.size())) * 300 +
            (100 * (static_cast<int>(PlayerSelector::playerIds.size()) - 1));

        auto& left = worldManager->getComponent<ecs::component::Button>(playerSkinButtonLeftIds[idx]);
        auto& right = worldManager->getComponent<ecs::component::Button>(playerSkinButtonRightIds[idx]);

        image.position->X = (1920 / 2 - total_player_size / 2) + (idx * 400);
        image.image->setRelativePosition(*image.position);

        left.rect->UpperLeftCorner.X = image.position->X + 25;
        left.rect->LowerRightCorner.X = left.rect->UpperLeftCorner.X + 40;
        left.button->setRelativePosition(*left.rect);

        right.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        right.rect->LowerRightCorner.X = right.rect->UpperLeftCorner.X + 40;
        right.button->setRelativePosition(*right.rect);

        idx++;
    }

    idx = 0;
    for (auto& id : PlayerSelector::playerKeysIds) {
        auto& button = worldManager->getComponent<ecs::component::Button>(id);
        int total_button_size = (static_cast<int>(PlayerSelector::playerKeysIds.size())) * 250 +
            (150 * (static_cast<int>(PlayerSelector::playerKeysIds.size()) - 1));

        button.rect->UpperLeftCorner.X = (1920 / 2 - total_button_size / 2) + (idx * 400);
        button.rect->LowerRightCorner.X = button.rect->UpperLeftCorner.X + 250;
        button.button->setRelativePosition(*button.rect);
        idx++;
    }
}

static std::string getNextUnusedSkin(const std::string& currentSkin)
{
    auto item = playerselector::player::PLAYER_SKINS.begin();

    for (; item != playerselector::player::PLAYER_SKINS.end(); item++) {
        if (item->first == currentSkin) {
            item->second = false;
            item++;
            break;
        }
    }
    while (true) {
        item =
            (item == playerselector::player::PLAYER_SKINS.end()) ? playerselector::player::PLAYER_SKINS.begin() : item;
        if (!item->second) {
            item->second = true;
            return item->first;
        }
        item++;
    }
}

static std::string getPrevUnusedSkin(const std::string& currentSkin)
{
    auto item = playerselector::player::PLAYER_SKINS.begin();

    for (; item != playerselector::player::PLAYER_SKINS.end(); item++) {
        if (item->first == currentSkin) {
            item->second = false;
            item = (item == playerselector::player::PLAYER_SKINS.begin()) ? playerselector::player::PLAYER_SKINS.end() :
                                                                            item;
            item--;
            break;
        }
    }
    while (true) {
        if (!item->second) {
            item->second = true;
            return item->first;
        }
        item =
            (item == playerselector::player::PLAYER_SKINS.begin()) ? playerselector::player::PLAYER_SKINS.end() : item;
        item--;
    }
}

void PlayerSelector::changeSkin(ecs::Universe* universe, irr::s32 id)
{
    switch (id) {
        case BUTTON_ID::GUI_SELECT_SKIN_P1_LEFT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[0]);
            auto prevUnusedSkin = getPrevUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(prevUnusedSkin.c_str()));
            image.pathTexture = prevUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P1_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[0]);
            auto nextUnusedSkin = getNextUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(nextUnusedSkin.c_str()));
            image.pathTexture = nextUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P2_LEFT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[1]);
            auto prevUnusedSkin = getPrevUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(prevUnusedSkin.c_str()));
            image.pathTexture = prevUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P2_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[1]);
            auto nextUnusedSkin = getNextUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(nextUnusedSkin.c_str()));
            image.pathTexture = nextUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P3_LEFT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[2]);
            auto prevUnusedSkin = getPrevUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(prevUnusedSkin.c_str()));
            image.pathTexture = prevUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P3_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[2]);
            auto nextUnusedSkin = getNextUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(nextUnusedSkin.c_str()));
            image.pathTexture = nextUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P4_LEFT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[3]);
            auto prevUnusedSkin = getPrevUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(prevUnusedSkin.c_str()));
            image.pathTexture = prevUnusedSkin;
        } break;
        case BUTTON_ID::GUI_SELECT_SKIN_P4_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")
                              ->getComponent<ecs::component::Image>(PlayerSelector::playerIds[3]);
            auto nextUnusedSkin = getNextUnusedSkin(image.pathTexture);
            image.image->setImage(universe->getDevice()->getVideoDriver()->getTexture(nextUnusedSkin.c_str()));
            image.pathTexture = nextUnusedSkin;
        } break;
        default:
            return;
    }
}

bool PlayerSelector::checkKeybinding(ecs::Universe* universe)
{
    std::vector<irr::EKEY_CODE> keys = {};

    for (const auto& cmp : playerComponent) {
        for (const auto& key : cmp.keys) {
            if (std::find(keys.begin(), keys.end(), key.second) != keys.end())
                return false;
            keys.push_back(key.second);
        }
    }
    return true;
}

void PlayerSelector::invalidKeybinding(ecs::Universe* universe)
{
    auto worldManager = universe->getWorldManager("PlayerSelector");
    auto gui = universe->getDevice()->getGUIEnvironment();
    auto driver = universe->getDevice()->getVideoDriver();

    ecs::component::MessageBox(gui, L"WARNING", nullptr, true, irr::gui::EMBF_OK, nullptr, -1,
                               driver->getTexture(playerselector::WARNING.c_str()));
}
