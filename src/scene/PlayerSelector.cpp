/*
** EPITECH PROJECT, 2020
** IndieStudio
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
#include "../ecs/component/Music.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/Music.hpp"
#include "../ecs/system/Render.hpp"

using namespace scene;

std::vector<ecs::Entity> PlayerSelector::playerIds = {};
std::vector<ecs::Entity> PlayerSelector::playerKeysIds = {};
std::vector<ecs::Entity> PlayerSelector::playerSkinButtonLeftIds = {};
std::vector<ecs::Entity> PlayerSelector::playerSkinButtonRightIds = {};
std::vector<ecs::Entity> PlayerSelector::playerTypeButtonLeftIds = {};
std::vector<ecs::Entity> PlayerSelector::playerTypeButtonRightIds = {};
std::vector<ecs::Entity> PlayerSelector::playerType = {};
std::vector<ecs::component::Player> PlayerSelector::playerComponent = {};
std::vector<bool> PlayerSelector::typeList = {};

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

void PlayerSelector::init(ecs::Universe* universe, sf::Time musicTimer)
{
    auto worldManager = universe->createWorldManager("PlayerSelector");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Button>();
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
        ecs::component::Image(
            gui, driver, scene::playerselector::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    ecs::Entity music = worldManager->createEntity();
    worldManager->addComponent(music, ecs::component::Music(playerselector::MUSIC, musicTimer));

    ecs::Entity frame = worldManager->createEntity();
    worldManager->addComponent(frame,
        ecs::component::Image(
            gui, driver, scene::playerselector::FRAME, new irr::core::position2d<irr::s32> {110, 160}));

    ecs::Entity defaultPlayer = worldManager->createEntity();
    worldManager->addComponent(defaultPlayer,
        ecs::component::Image(gui, driver, getUnusedSkin(), new irr::core::position2d<irr::s32> {960 - 150, 265}));
    playerIds.emplace_back(defaultPlayer);

    ecs::Entity defaultPlayerKeys =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 125, 745, 960 + 125, 745 + 100), nullptr,
            GUI_SELECT_KB_P1, playerselector::button::keys::NORMAL, playerselector::button::keys::HOVER,
            playerselector::button::keys::PRESSED);
    playerKeysIds.emplace_back(defaultPlayerKeys);

    ecs::Entity defaultPlayerSkinButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 620, 835 + 40, 620 + 40), nullptr,
            GUI_SELECT_SKIN_P1_LEFT, playerselector::button::skin::left::NORMAL,
            playerselector::button::skin::left::HOVER, playerselector::button::skin::left::PRESSED);
    playerSkinButtonLeftIds.emplace_back(defaultPlayerSkinButtonLeft);

    ecs::Entity defaultPlayerSkinButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 620, 1045 + 40, 620 + 40), nullptr,
            GUI_SELECT_SKIN_P1_RIGHT, playerselector::button::skin::right::NORMAL,
            playerselector::button::skin::right::HOVER, playerselector::button::skin::right::PRESSED);
    playerSkinButtonRightIds.emplace_back(defaultPlayerSkinButtonRight);

    ecs::Entity defaultPlayerTypeButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 220, 835 + 40, 220 + 40), nullptr,
            GUI_SELECT_TYPE_P1_LEFT, playerselector::button::skin::left::NORMAL,
            playerselector::button::skin::left::HOVER, playerselector::button::skin::left::PRESSED);
    playerTypeButtonLeftIds.emplace_back(defaultPlayerTypeButtonLeft);

    ecs::Entity defaultPlayerTypeButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 220, 1045 + 40, 220 + 40), nullptr,
            GUI_SELECT_TYPE_P1_RIGHT, playerselector::button::skin::right::NORMAL,
            playerselector::button::skin::right::HOVER, playerselector::button::skin::right::PRESSED);
    playerTypeButtonRightIds.emplace_back(defaultPlayerTypeButtonRight);

    ecs::Entity type = worldManager->createEntity();
    worldManager->addComponent(type,
        ecs::component::Image(
            gui, driver, playerselector::SELECT_PLAYER, new irr::core::position2d<irr::s32> {960 - 75, 215}));
    playerType.emplace_back(type);

    PlayerSelector::playerComponent.emplace_back();
    PlayerSelector::typeList.emplace_back(false);

    createButton(worldManager, gui, new irr::core::rect<irr::s32>(175 - 125, 40, 175 + 125, 40 + 100), nullptr,
        GUI_SELECT_MENU, playerselector::button::back::NORMAL, playerselector::button::back::HOVER,
        playerselector::button::back::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1745 - 125, 40, 1745 + 125, 40 + 100), nullptr,
        GUI_SELECT_FIGHT, playerselector::button::fight::NORMAL, playerselector::button::fight::HOVER,
        playerselector::button::fight::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(785 - 125, 930, 785 + 125, 930 + 100), nullptr,
        GUI_SELECT_REMOVE_PLAYER, playerselector::button::remove::NORMAL, playerselector::button::remove::HOVER,
        playerselector::button::remove::PRESSED);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1135 - 125, 930, 1135 + 125, 930 + 100), nullptr,
        GUI_SELECT_ADD_PLAYER, playerselector::button::add::NORMAL, playerselector::button::add::HOVER,
        playerselector::button::add::PRESSED);

    addPlayer(universe);
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
    PlayerSelector::playerTypeButtonLeftIds.clear();
    PlayerSelector::playerTypeButtonRightIds.clear();
    PlayerSelector::playerType.clear();
    PlayerSelector::playerComponent.clear();
    PlayerSelector::typeList.clear();
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
        ecs::component::Image(gui, driver, getUnusedSkin(), new irr::core::position2d<irr::s32> {960 - 150, 265}));
    playerIds.emplace_back(player);

    ecs::Entity playerKeys =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(960 - 125, 745, 960 + 125, 745 + 100), nullptr,
            GUI_SELECT_KB_P1 + (PlayerSelector::playerIds.size() - 1), playerselector::button::keys::NORMAL,
            playerselector::button::keys::HOVER, playerselector::button::keys::PRESSED);
    playerKeysIds.emplace_back(playerKeys);

    ecs::Entity playerSkinButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 620, 835 + 40, 620 + 40), nullptr,
            GUI_SELECT_SKIN_P1_LEFT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::left::NORMAL, playerselector::button::skin::left::HOVER,
            playerselector::button::skin::left::PRESSED);
    playerSkinButtonLeftIds.emplace_back(playerSkinButtonLeft);

    ecs::Entity playerSkinButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 620, 1045 + 40, 620 + 40), nullptr,
            GUI_SELECT_SKIN_P1_RIGHT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::right::NORMAL, playerselector::button::skin::right::HOVER,
            playerselector::button::skin::right::PRESSED);
    playerSkinButtonRightIds.emplace_back(playerSkinButtonRight);

    ecs::Entity playerTypeButtonLeft =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(835, 220, 835 + 40, 220 + 40), nullptr,
            GUI_SELECT_TYPE_P1_LEFT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::left::NORMAL, playerselector::button::skin::left::HOVER,
            playerselector::button::skin::left::PRESSED);
    playerTypeButtonLeftIds.emplace_back(playerTypeButtonLeft);

    ecs::Entity playerTypeButtonRight =
        createButton(worldManager, gui, new irr::core::rect<irr::s32>(1045, 220, 1045 + 40, 220 + 40), nullptr,
            GUI_SELECT_TYPE_P1_RIGHT + (PlayerSelector::playerIds.size() - 1) * 2,
            playerselector::button::skin::right::NORMAL, playerselector::button::skin::right::HOVER,
            playerselector::button::skin::right::PRESSED);
    playerTypeButtonRightIds.emplace_back(playerTypeButtonRight);

    ecs::Entity type = worldManager->createEntity();
    worldManager->addComponent(type,
        ecs::component::Image(
            gui, driver, playerselector::SELECT_PLAYER, new irr::core::position2d<irr::s32> {960 - 75, 215}));
    playerType.emplace_back(type);

    playerComponent.emplace_back();
    PlayerSelector::typeList.emplace_back(false);

    int idx = 0;
    for (auto& id : PlayerSelector::playerIds) {
        auto& image = worldManager->getComponent<ecs::component::Image>(id);
        int total_player_size = (static_cast<int>(PlayerSelector::playerIds.size())) * 300 +
            (100 * (static_cast<int>(PlayerSelector::playerIds.size()) - 1));

        auto& leftSkin = worldManager->getComponent<ecs::component::Button>(playerSkinButtonLeftIds[idx]);
        auto& rightSkin = worldManager->getComponent<ecs::component::Button>(playerSkinButtonRightIds[idx]);

        image.position->X = (1920 / 2 - total_player_size / 2) + (idx * 400);
        image.image->setRelativePosition(*image.position);

        leftSkin.rect->UpperLeftCorner.X = image.position->X + 25;
        leftSkin.rect->LowerRightCorner.X = leftSkin.rect->UpperLeftCorner.X + 40;
        leftSkin.button->setRelativePosition(*leftSkin.rect);

        rightSkin.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        rightSkin.rect->LowerRightCorner.X = rightSkin.rect->UpperLeftCorner.X + 40;
        rightSkin.button->setRelativePosition(*rightSkin.rect);

        auto& leftType = worldManager->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[idx]);
        auto& rightType = worldManager->getComponent<ecs::component::Button>(playerTypeButtonRightIds[idx]);

        leftType.rect->UpperLeftCorner.X = image.position->X + 25;
        leftType.rect->LowerRightCorner.X = leftType.rect->UpperLeftCorner.X + 40;
        leftType.button->setRelativePosition(*leftType.rect);

        rightType.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        rightType.rect->LowerRightCorner.X = rightType.rect->UpperLeftCorner.X + 40;
        rightType.button->setRelativePosition(*rightType.rect);

        auto& typeImage = worldManager->getComponent<ecs::component::Image>(playerType[idx]);

        typeImage.position->X = image.position->X + 75;
        typeImage.image->setRelativePosition(*typeImage.position);

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

    PlayerSelector::changeType(universe, GUI_SELECT_TYPE_P1_RIGHT + (PlayerSelector::playerIds.size() - 1) * 2);
}

void PlayerSelector::removePlayer(ecs::Universe* universe)
{
    if (PlayerSelector::playerIds.size() <= 2)
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
    {
        auto& button = universe->getWorldManager("PlayerSelector")
                           ->getComponent<ecs::component::Button>(PlayerSelector::playerTypeButtonLeftIds.back());
        button.button->remove();
    }
    {
        auto& button = universe->getWorldManager("PlayerSelector")
                           ->getComponent<ecs::component::Button>(PlayerSelector::playerTypeButtonRightIds.back());
        button.button->remove();
    }
    {
        auto& image = universe->getWorldManager("PlayerSelector")
                          ->getComponent<ecs::component::Image>(PlayerSelector::playerType.back());
        image.image->remove();
    }
    auto& imageRemoved = universe->getWorldManager("PlayerSelector")
                             ->getComponent<ecs::component::Image>(PlayerSelector::playerIds.back());
    imageRemoved.image->remove();

    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerKeysIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerSkinButtonLeftIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerSkinButtonRightIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerTypeButtonLeftIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerTypeButtonRightIds.back());
    universe->getWorldManager("PlayerSelector")->destroyEntity(PlayerSelector::playerType.back());

    PlayerSelector::playerIds.pop_back();
    PlayerSelector::playerKeysIds.pop_back();
    PlayerSelector::playerSkinButtonLeftIds.pop_back();
    PlayerSelector::playerSkinButtonRightIds.pop_back();
    PlayerSelector::playerTypeButtonLeftIds.pop_back();
    PlayerSelector::playerTypeButtonRightIds.pop_back();
    PlayerSelector::playerType.pop_back();
    PlayerSelector::playerComponent.pop_back();
    PlayerSelector::typeList.pop_back();

    for (auto& skin : playerselector::player::PLAYER_SKINS) {
        if (skin.first == imageRemoved.pathTexture)
            skin.second = false;
    }

    int idx = 0;
    for (auto& id : PlayerSelector::playerIds) {
        auto& image = worldManager->getComponent<ecs::component::Image>(id);
        int total_player_size = (static_cast<int>(PlayerSelector::playerIds.size())) * 300 +
            (100 * (static_cast<int>(PlayerSelector::playerIds.size()) - 1));

        auto& leftSkin = worldManager->getComponent<ecs::component::Button>(playerSkinButtonLeftIds[idx]);
        auto& rightSkin = worldManager->getComponent<ecs::component::Button>(playerSkinButtonRightIds[idx]);

        image.position->X = (1920 / 2 - total_player_size / 2) + (idx * 400);
        image.image->setRelativePosition(*image.position);

        leftSkin.rect->UpperLeftCorner.X = image.position->X + 25;
        leftSkin.rect->LowerRightCorner.X = leftSkin.rect->UpperLeftCorner.X + 40;
        leftSkin.button->setRelativePosition(*leftSkin.rect);

        rightSkin.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        rightSkin.rect->LowerRightCorner.X = rightSkin.rect->UpperLeftCorner.X + 40;
        rightSkin.button->setRelativePosition(*rightSkin.rect);

        auto& leftType = worldManager->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[idx]);
        auto& rightType = worldManager->getComponent<ecs::component::Button>(playerTypeButtonRightIds[idx]);

        leftType.rect->UpperLeftCorner.X = image.position->X + 25;
        leftType.rect->LowerRightCorner.X = leftType.rect->UpperLeftCorner.X + 40;
        leftType.button->setRelativePosition(*leftType.rect);

        rightType.rect->UpperLeftCorner.X = image.position->X + 300 - 25 - 40;
        rightType.rect->LowerRightCorner.X = rightType.rect->UpperLeftCorner.X + 40;
        rightType.button->setRelativePosition(*rightType.rect);

        auto& typeImage = worldManager->getComponent<ecs::component::Image>(playerType[idx]);

        typeImage.position->X = image.position->X + 75;
        typeImage.image->setRelativePosition(*typeImage.position);

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

void PlayerSelector::changeType(ecs::Universe* universe, irr::s32 id)
{
    auto driver = universe->getDevice()->getVideoDriver();

    switch (id) {
        case GUI_SELECT_TYPE_P1_LEFT:
        case GUI_SELECT_TYPE_P1_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Image>(playerType[0]);
            auto& left = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[0]);
            auto& right = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonRightIds[0]);
            auto& keys = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerKeysIds[0]);

            if (image.pathTexture == playerselector::SELECT_PLAYER) {
                image.image->setImage(driver->getTexture(playerselector::SELECT_AI.c_str()));
                image.pathTexture = playerselector::SELECT_AI;

                left.setImage(driver->getTexture(playerselector::button::skin::left2::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left2::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left2::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right2::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right2::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right2::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));

                typeList[0] = true;
            } else {
                image.image->setImage(driver->getTexture(playerselector::SELECT_PLAYER.c_str()));
                image.pathTexture = playerselector::SELECT_PLAYER;

                left.setImage(driver->getTexture(playerselector::button::skin::left::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::NORMAL.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::HOVER.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::PRESSED.c_str()));

                typeList[0] = false;
            }
        } break;
        case GUI_SELECT_TYPE_P2_LEFT:
        case GUI_SELECT_TYPE_P2_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Image>(playerType[1]);
            auto& left = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[1]);
            auto& right = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonRightIds[1]);
            auto& keys = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerKeysIds[1]);

            if (image.pathTexture == playerselector::SELECT_PLAYER) {
                image.image->setImage(driver->getTexture(playerselector::SELECT_AI.c_str()));
                image.pathTexture = playerselector::SELECT_AI;

                left.setImage(driver->getTexture(playerselector::button::skin::left2::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left2::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left2::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right2::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right2::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right2::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));

                typeList[1] = true;
            } else {
                image.image->setImage(driver->getTexture(playerselector::SELECT_PLAYER.c_str()));
                image.pathTexture = playerselector::SELECT_PLAYER;

                left.setImage(driver->getTexture(playerselector::button::skin::left::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::NORMAL.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::HOVER.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::PRESSED.c_str()));

                typeList[1] = false;
            }
        } break;
        case GUI_SELECT_TYPE_P3_LEFT:
        case GUI_SELECT_TYPE_P3_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Image>(playerType[2]);
            auto& left = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[2]);
            auto& right = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonRightIds[2]);
            auto& keys = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerKeysIds[2]);

            if (image.pathTexture == playerselector::SELECT_PLAYER) {
                image.image->setImage(driver->getTexture(playerselector::SELECT_AI.c_str()));
                image.pathTexture = playerselector::SELECT_AI;

                left.setImage(driver->getTexture(playerselector::button::skin::left2::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left2::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left2::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right2::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right2::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right2::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));

                typeList[2] = true;
            } else {
                image.image->setImage(driver->getTexture(playerselector::SELECT_PLAYER.c_str()));
                image.pathTexture = playerselector::SELECT_PLAYER;

                left.setImage(driver->getTexture(playerselector::button::skin::left::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::NORMAL.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::HOVER.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::PRESSED.c_str()));

                typeList[2] = false;
            }
        } break;
        case GUI_SELECT_TYPE_P4_LEFT:
        case GUI_SELECT_TYPE_P4_RIGHT: {
            auto& image = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Image>(playerType[3]);
            auto& left = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonLeftIds[3]);
            auto& right = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerTypeButtonRightIds[3]);
            auto& keys = universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Button>(playerKeysIds[3]);

            if (image.pathTexture == playerselector::SELECT_PLAYER) {
                image.image->setImage(driver->getTexture(playerselector::SELECT_AI.c_str()));
                image.pathTexture = playerselector::SELECT_AI;

                left.setImage(driver->getTexture(playerselector::button::skin::left2::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left2::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left2::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right2::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right2::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right2::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::BLOCKED.c_str()));

                typeList[3] = true;
            } else {
                image.image->setImage(driver->getTexture(playerselector::SELECT_PLAYER.c_str()));
                image.pathTexture = playerselector::SELECT_PLAYER;

                left.setImage(driver->getTexture(playerselector::button::skin::left::NORMAL.c_str()));
                left.setHoverImage(driver->getTexture(playerselector::button::skin::left::HOVER.c_str()));
                left.setPressedImage(driver->getTexture(playerselector::button::skin::left::PRESSED.c_str()));

                right.setImage(driver->getTexture(playerselector::button::skin::right::NORMAL.c_str()));
                right.setHoverImage(driver->getTexture(playerselector::button::skin::right::HOVER.c_str()));
                right.setPressedImage(driver->getTexture(playerselector::button::skin::right::PRESSED.c_str()));

                keys.setImage(driver->getTexture(playerselector::button::keys::NORMAL.c_str()));
                keys.setHoverImage(driver->getTexture(playerselector::button::keys::HOVER.c_str()));
                keys.setPressedImage(driver->getTexture(playerselector::button::keys::PRESSED.c_str()));

                typeList[3] = false;
            }
        } break;
        default:
            return;
    }
}

bool PlayerSelector::checkKeybinding(ecs::Universe* universe)
{
    std::vector<irr::EKEY_CODE> keys = {};

    int idx = 0;
    for (const auto& cmp : playerComponent) {
        if (typeList[idx]) {
            idx++;
            continue;
        }
        for (const auto& key : cmp.keys) {
            if (std::find(keys.begin(), keys.end(), key.second) != keys.end())
                return false;
            keys.push_back(key.second);
        }
        idx++;
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
