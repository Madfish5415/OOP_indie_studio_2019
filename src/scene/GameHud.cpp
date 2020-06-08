/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** GameHud.cpp
*/

#include "GameHud.hpp"

#include "../ecs/component/Blink.hpp"
#include "../ecs/component/Button.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/Player.hpp"
#include "../ecs/component/StatRender.hpp"
#include "../ecs/component/Stats.hpp"
#include "../ecs/component/Timer.hpp"
#include "../ecs/component/TimerRender.hpp"
#include "../ecs/system/Blink.hpp"
#include "../ecs/system/Button.hpp"
#include "../ecs/system/StatRender.hpp"
#include "../ecs/system/Timer.hpp"
#include "../ecs/system/TimerRender.hpp"

using namespace scene;

static std::string getIcon(const std::string &path)
{
    if (gamehud::icon::MODEL_TO_ICON.count(path) == 0)
        return gamehud::icon::WHITE;
    else
        return gamehud::icon::MODEL_TO_ICON.at(path);
}

static void createIcon(ecs::WorldManager *worldManager, irr::gui::IGUIEnvironment *gui,
    irr::video::IVideoDriver *driver, const std::string &path, int x, int y)
{
    ecs::Entity icon = worldManager->createEntity();

    worldManager->addComponent(
        icon, ecs::component::Image(gui, driver, getIcon(path), new irr::core::position2d<irr::s32> {x, y}));
}

static void createBoost(ecs::WorldManager *worldManager, irr::gui::IGUIEnvironment *gui,
    irr::video::IVideoDriver *driver, const std::string &path, int x, int y)
{
    ecs::Entity boost = worldManager->createEntity();

    worldManager->addComponent(
        boost, ecs::component::Image(gui, driver, path, new irr::core::position2d<irr::s32> {x, y}));
}

static void createNumber(ecs::WorldManager *worldManager, irr::gui::IGUIEnvironment *gui,
    irr::video::IVideoDriver *driver, ecs::Entity owner, const std::string &type, int x, int y)
{
    ecs::Entity number = worldManager->createEntity();

    worldManager->addComponent(number,
        ecs::component::Image(gui, driver, gamehud::number::NUMBER9, new irr::core::position2d<irr::s32> {x, y}));
    worldManager->addComponent(number, ecs::component::StatRender(owner, type));
}

static void createIcons(ecs::WorldManager *worldManager, irr::gui::IGUIEnvironment *gui,
    irr::video::IVideoDriver *driver, const std::vector<std::string> &paths)
{
    auto players = worldManager->getEntities<ecs::component::Stats>();

    int idx = 0;
    for (const auto &path : paths) {
        if (idx == 0) {
            createIcon(worldManager, gui, driver, path, 150, 180);

            createBoost(worldManager, gui, driver, gamehud::boost::BOMB_RADIUS, 125, 440);
            createBoost(worldManager, gui, driver, gamehud::boost::MAX_BOMB, 225, 440);
            createBoost(worldManager, gui, driver, gamehud::boost::MOVE_SPEED, 325, 440);

            createNumber(worldManager, gui, driver, players[idx], "bombRadius", 125 + 20, 440 + 75);
            createNumber(worldManager, gui, driver, players[idx], "maxBomb", 225 + 20, 440 + 75);
            createNumber(worldManager, gui, driver, players[idx], "moveSpeed", 325 + 20, 440 + 75);
        } else if (idx == 1) {
            createIcon(worldManager, gui, driver, path, 1920 - 150 - 250, 180);

            createBoost(worldManager, gui, driver, gamehud::boost::BOMB_RADIUS, 1920 - 325 - 100, 440);
            createBoost(worldManager, gui, driver, gamehud::boost::MAX_BOMB, 1920 - 225 - 100, 440);
            createBoost(worldManager, gui, driver, gamehud::boost::MOVE_SPEED, 1920 - 125 - 100, 440);

            createNumber(worldManager, gui, driver, players[idx], "bombRadius", 1920 - 325 - 100 + 20, 440 + 75);
            createNumber(worldManager, gui, driver, players[idx], "maxBomb", 1920 - 225 - 100 + 20, 440 + 75);
            createNumber(worldManager, gui, driver, players[idx], "moveSpeed", 1920 - 125 - 100 + 20, 440 + 75);
        } else if (idx == 2) {
            createIcon(worldManager, gui, driver, path, 150, 760);

            createBoost(worldManager, gui, driver, gamehud::boost::BOMB_RADIUS, 410, 810);
            createBoost(worldManager, gui, driver, gamehud::boost::MAX_BOMB, 510, 810);
            createBoost(worldManager, gui, driver, gamehud::boost::MOVE_SPEED, 610, 810);

            createNumber(worldManager, gui, driver, players[idx], "bombRadius", 410 + 20, 810 + 75);
            createNumber(worldManager, gui, driver, players[idx], "maxBomb", 510 + 20, 810 + 75);
            createNumber(worldManager, gui, driver, players[idx], "moveSpeed", 610 + 20, 810 + 75);
        } else if (idx == 3) {
            createIcon(worldManager, gui, driver, path, 1920 - 150 - 250, 760);

            createBoost(worldManager, gui, driver, gamehud::boost::BOMB_RADIUS, 1920 - 610 - 100, 810);
            createBoost(worldManager, gui, driver, gamehud::boost::MAX_BOMB, 1920 - 510 - 100, 810);
            createBoost(worldManager, gui, driver, gamehud::boost::MOVE_SPEED, 1920 - 410 - 100, 810);

            createNumber(worldManager, gui, driver, players[idx], "bombRadius", 1920 - 610 - 100 + 20, 810 + 75);
            createNumber(worldManager, gui, driver, players[idx], "maxBomb", 1920 - 510 - 100 + 20, 810 + 75);
            createNumber(worldManager, gui, driver, players[idx], "moveSpeed", 1920 - 410 - 100 + 20, 810 + 75);
        }
        idx++;
    }
}

static void createTimer(
    ecs::WorldManager *worldManager, irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver)
{
    ecs::Entity frame = worldManager->createEntity();
    worldManager->addComponent(
        frame, ecs::component::Image(gui, driver, gamehud::TIMER_FRAME, new irr::core::position2d<irr::s32>(835, 905)));

    ecs::Entity dot = worldManager->createEntity();
    worldManager->addComponent(dot, ecs::component::Image(gui, driver, gamehud::DOUBLE_DOT, new irr::core::position2d<irr::s32>(930, 905)));
    worldManager->addComponent(dot, ecs::component::Blink(1000));

    ecs::Entity timer = worldManager->createEntity();
    worldManager->addComponent(timer, ecs::component::Timer(30000));

    ecs::Entity numberOne = worldManager->createEntity();
    worldManager->addComponent(numberOne, ecs::component::Image(gui, driver, gamehud::number::NUMBER9, new irr::core::position2d<irr::s32>(848, 905)));
    worldManager->addComponent(numberOne, ecs::component::TimerRender(timer, 0));

    ecs::Entity numberTwo = worldManager->createEntity();
    worldManager->addComponent(numberTwo, ecs::component::Image(gui, driver, gamehud::number::NUMBER9, new irr::core::position2d<irr::s32>(897, 905)));
    worldManager->addComponent(numberTwo, ecs::component::TimerRender(timer, 1));

    ecs::Entity numberThree = worldManager->createEntity();
    worldManager->addComponent(numberThree, ecs::component::Image(gui, driver, gamehud::number::NUMBER9, new irr::core::position2d<irr::s32>(966, 905)));
    worldManager->addComponent(numberThree, ecs::component::TimerRender(timer, 2));

    ecs::Entity numberFour = worldManager->createEntity();
    worldManager->addComponent(numberFour, ecs::component::Image(gui, driver, gamehud::number::NUMBER9, new irr::core::position2d<irr::s32>(1015, 905)));
    worldManager->addComponent(numberFour, ecs::component::TimerRender(timer, 3));
}

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

void GameHud::init(ecs::Universe *universe, const std::vector<std::string> &paths)
{
    auto worldManager = universe->getWorldManager("Bomberman");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::StatRender>();
    worldManager->registerComponent<ecs::component::Timer>();
    worldManager->registerComponent<ecs::component::TimerRender>();
    worldManager->registerComponent<ecs::component::Blink>();
    worldManager->registerComponent<ecs::component::Button>();

    worldManager->registerSystem<ecs::system::StatRender>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Image>(), true);
        signature.set(worldManager->getComponentType<ecs::component::StatRender>(), true);
        worldManager->setSystemSignature<ecs::system::StatRender>(signature);
    }
    worldManager->registerSystem<ecs::system::Timer>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Timer>(), true);
        worldManager->setSystemSignature<ecs::system::Timer>(signature);
    }
    worldManager->registerSystem<ecs::system::TimerRender>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Image>(), true);
        signature.set(worldManager->getComponentType<ecs::component::TimerRender>(), true);
        worldManager->setSystemSignature<ecs::system::TimerRender>(signature);
    }
    worldManager->registerSystem<ecs::system::Blink>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Image>(), true);
        signature.set(worldManager->getComponentType<ecs::component::Blink>(), true);
        worldManager->setSystemSignature<ecs::system::Blink>(signature);
    }
    worldManager->registerSystem<ecs::system::Button>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Button>());
        worldManager->setSystemSignature<ecs::system::Button>(signature);
    }

    ecs::Entity background = worldManager->createEntity();
    worldManager->addComponent(background,
        ecs::component::Image(gui, driver, gamehud::BACKGROUND, new irr::core::position2d<irr::s32> {0, 0}));

    createIcons(worldManager, gui, driver, paths);
    createTimer(worldManager, gui, driver);
    createButton(worldManager, gui, new irr::core::rect<irr::s32>(1785, 35, 1785 + 75, 35 + 75), nullptr, BUTTON_ID::GUI_GAME_PAUSE, gamehud::button::settings::NORMAL,
        gamehud::button::settings::HOVER, gamehud::button::settings::PRESSED);
}

void GameHud::destroy(ecs::Universe *universe)
{
    universe->getDevice()->getGUIEnvironment()->clear();
}
