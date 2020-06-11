/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinScreen
*/

#include "WinScreen.hpp"

#include "../ecs/Universe.hpp"
#include "../ecs/component/Blink.hpp"
#include "../ecs/component/Image.hpp"
#include "../ecs/component/Sliding.hpp"
#include "../ecs/component/Sound.hpp"
#include "../ecs/system/Blink.hpp"
#include "../ecs/system/Render.hpp"
#include "../ecs/system/Sliding.hpp"
#include "../ecs/system/Sound.hpp"
#include "Bomberman.hpp"
#include "LoadingMenu.hpp"

static void createSlidingScreen(ecs::WorldManager* worldManager, const std::string& playerPath,
    const std::string& textPath, const std::string& wonPath, const std::string& musicPath)
{
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    ecs::Entity back = worldManager->createEntity();
    worldManager->addComponent(back,
        ecs::component::Image(
            gui, driver, scene::winscreen::slide::BACK, new irr::core::position2d<irr::s32>(1920, 0)));
    worldManager->addComponent(back,
        ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(-680, 0), irr::core::vector2d<irr::s32>(-2000, 0)));

    ecs::Entity middle = worldManager->createEntity();
    worldManager->addComponent(middle,
        ecs::component::Image(
            gui, driver, scene::winscreen::slide::MIDDLE, new irr::core::position2d<irr::s32>(1920, 0)));
    worldManager->addComponent(middle,
        ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(-680, 0), irr::core::vector2d<irr::s32>(-2000, 0)));

    ecs::Entity front = worldManager->createEntity();
    worldManager->addComponent(front,
        ecs::component::Image(
            gui, driver, scene::winscreen::slide::FRONT, new irr::core::position2d<irr::s32>(3840, 0)));
    worldManager->addComponent(front,
        ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(-660, 0), irr::core::vector2d<irr::s32>(-3000, 0)));

    if (playerPath != "draw") {
        ecs::Entity player = worldManager->createEntity();
        worldManager->addComponent(
            player, ecs::component::Image(gui, driver, playerPath, new irr::core::position2d<irr::s32>(2600, -150)));
        worldManager->addComponent(player,
            ecs::component::Sliding(
                1, irr::core::vector2d<irr::s32>(0, -150), irr::core::vector2d<irr::s32>(-2000, 0)));

        ecs::Entity music = worldManager->createEntity();
        auto map = std::unordered_map<std::string, std::string>();
        map.emplace("win", musicPath);
        worldManager->addComponent<ecs::component::Sound>(music, ecs::component::Sound(map));
        worldManager->getComponent<ecs::component::Sound>(music).soundsToPlay.emplace_back("win");
    } else {
        ecs::Entity left = worldManager->createEntity();
        worldManager->addComponent(left,
            ecs::component::Image(gui, driver, scene::winscreen::win::draw::PLAYERS_LEFT,
                new irr::core::position2d<irr::s32>(2600, -150)));
        worldManager->addComponent(left,
            ecs::component::Sliding(
                1, irr::core::vector2d<irr::s32>(0, -150), irr::core::vector2d<irr::s32>(-2000, 0)));

        ecs::Entity right = worldManager->createEntity();
        worldManager->addComponent(right,
            ecs::component::Image(gui, driver, scene::winscreen::win::draw::PLAYERS_RIGHT,
                new irr::core::position2d<irr::s32>(2600, -150)));
        worldManager->addComponent(right,
            ecs::component::Sliding(
                1, irr::core::vector2d<irr::s32>(0, -150), irr::core::vector2d<irr::s32>(-2000, 0)));
    }

    ecs::Entity text = worldManager->createEntity();
    worldManager->addComponent(
        text, ecs::component::Image(gui, driver, textPath, new irr::core::position2d<irr::s32>(3900, 0)));
    worldManager->addComponent(
        text, ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(0, 0), irr::core::vector2d<irr::s32>(-3000, 0)));

    ecs::Entity won = worldManager->createEntity();
    worldManager->addComponent(
        won, ecs::component::Image(gui, driver, wonPath, new irr::core::position2d<irr::s32>(3840, 0)));
    worldManager->addComponent(
        won, ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(0, 0), irr::core::vector2d<irr::s32>(-2000, 0)));

    auto blinkingText = worldManager->createEntity();
    worldManager->addComponent(blinkingText,
        ecs::component::Image(gui, driver, scene::loadingmenu::TEXT, new irr::core::position2d<irr::s32> {4250, 960}));
    worldManager->addComponent(blinkingText, ecs::component::Blink(600));
    worldManager->addComponent(blinkingText,
        ecs::component::Sliding(1, irr::core::vector2d<irr::s32>(410, 960), irr::core::vector2d<irr::s32>(-2000, 0)));
}

void scene::WinScreen::init(ecs::Universe* universe, const std::string& skinPath)
{
    auto worldManager = universe->createWorldManager("WinScreen");

    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Sliding>();
    worldManager->registerComponent<ecs::component::Blink>();
    worldManager->registerComponent<ecs::component::Sound>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::Sliding>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Sliding>());
        worldManager->setSystemSignature<ecs::system::Sliding>(signature);
    }
    worldManager->registerSystem<ecs::system::Blink>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Blink>());
        signature.set(worldManager->getComponentType<ecs::component::Image>());
        worldManager->setSystemSignature<ecs::system::Blink>(signature);
    }
    worldManager->registerSystem<ecs::system::Sound>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Sound>());
        worldManager->setSystemSignature<ecs::system::Sound>(signature);
    }

    if (skinPath == scene::bomberman::ninja::AQUA) {
        createSlidingScreen(worldManager, scene::winscreen::win::aqua::PLAYER, scene::winscreen::win::aqua::TEXT,
            scene::winscreen::win::aqua::WON, scene::winscreen::win::aqua::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::BLACK) {
        createSlidingScreen(worldManager, scene::winscreen::win::black::PLAYER, scene::winscreen::win::black::TEXT,
            scene::winscreen::win::black::WON, scene::winscreen::win::black::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::BLUE) {
        createSlidingScreen(worldManager, scene::winscreen::win::blue::PLAYER, scene::winscreen::win::blue::TEXT,
            scene::winscreen::win::blue::WON, scene::winscreen::win::blue::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::GREEN) {
        createSlidingScreen(worldManager, scene::winscreen::win::green::PLAYER, scene::winscreen::win::green::TEXT,
            scene::winscreen::win::green::WON, scene::winscreen::win::green::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::PINK) {
        createSlidingScreen(worldManager, scene::winscreen::win::pink::PLAYER, scene::winscreen::win::pink::TEXT,
            scene::winscreen::win::pink::WON, scene::winscreen::win::pink::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::RED) {
        createSlidingScreen(worldManager, scene::winscreen::win::red::PLAYER, scene::winscreen::win::red::TEXT,
            scene::winscreen::win::red::WON, scene::winscreen::win::red::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::WHITE) {
        createSlidingScreen(worldManager, scene::winscreen::win::white::PLAYER, scene::winscreen::win::white::TEXT,
            scene::winscreen::win::white::WON, scene::winscreen::win::white::MUSIC);
    } else if (skinPath == scene::bomberman::ninja::YELLOW) {
        createSlidingScreen(worldManager, scene::winscreen::win::yellow::PLAYER, scene::winscreen::win::yellow::TEXT,
            scene::winscreen::win::yellow::WON, scene::winscreen::win::yellow::MUSIC);
    } else if (skinPath == "draw") {
        createSlidingScreen(worldManager, "draw", scene::winscreen::win::draw::TEXT, scene::winscreen::win::draw::WON, "");
    }
}

void scene::WinScreen::destroy(ecs::Universe* universe)
{
    universe->deleteWorldManager("WinScreen");
}