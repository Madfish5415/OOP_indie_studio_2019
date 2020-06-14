/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** GameHud.hpp
*/

#ifndef INDIESTUDIO_GAMEHUD_HPP
#define INDIESTUDIO_GAMEHUD_HPP

#include <irrlicht.h>

#include "../ecs/Universe.hpp"
#include "Bomberman.hpp"

/**
 * @file GameHud.hpp
 * @brief GameHud Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class GameHud
 * @brief Handle the GameHud scene.
 */
class GameHud {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    GameHud() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~GameHud() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole GameHud scene.
     * @param universe : A pointer on the universe.
     * @param paths : List of players skins.
     */
    static void init(ecs::Universe* universe, const std::vector<std::string>& paths);
    /**
     * @brief destroy method
     * This method destroy the whole GameHud scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe* universe);
};

namespace gamehud {

namespace boost {
static const std::string BOMB_RADIUS = "assets/img/game-hud/boost/boost-flame.png";
static const std::string MAX_BOMB = "assets/img/game-hud/boost/boost-bomb.png";
static const std::string MOVE_SPEED = "assets/img/game-hud/boost/boost-speed.png";
} // namespace boost

namespace icon {
static const std::string AQUA = "assets/img/game-hud/icon/icon-aqua.png";
static const std::string BLACK = "assets/img/game-hud/icon/icon-black.png";
static const std::string BLUE = "assets/img/game-hud/icon/icon-blue.png";
static const std::string GREEN = "assets/img/game-hud/icon/icon-green.png";
static const std::string PINK = "assets/img/game-hud/icon/icon-pink.png";
static const std::string RED = "assets/img/game-hud/icon/icon-red.png";
static const std::string WHITE = "assets/img/game-hud/icon/icon-white.png";
static const std::string YELLOW = "assets/img/game-hud/icon/icon-yellow.png";

static const std::map<std::string, std::string> MODEL_TO_ICON = {{scene::bomberman::ninja::AQUA, AQUA},
    {scene::bomberman::ninja::BLACK, BLACK}, {scene::bomberman::ninja::BLUE, BLUE},
    {scene::bomberman::ninja::GREEN, GREEN}, {scene::bomberman::ninja::PINK, PINK}, {scene::bomberman::ninja::RED, RED},
    {scene::bomberman::ninja::WHITE, WHITE}, {scene::bomberman::ninja::YELLOW, YELLOW}};
} // namespace icon

namespace number {
static const std::string NUMBER0 = "assets/img/game-hud/number/number0.png";
static const std::string NUMBER1 = "assets/img/game-hud/number/number1.png";
static const std::string NUMBER2 = "assets/img/game-hud/number/number2.png";
static const std::string NUMBER3 = "assets/img/game-hud/number/number3.png";
static const std::string NUMBER4 = "assets/img/game-hud/number/number4.png";
static const std::string NUMBER5 = "assets/img/game-hud/number/number5.png";
static const std::string NUMBER6 = "assets/img/game-hud/number/number6.png";
static const std::string NUMBER7 = "assets/img/game-hud/number/number7.png";
static const std::string NUMBER8 = "assets/img/game-hud/number/number8.png";
static const std::string NUMBER9 = "assets/img/game-hud/number/number9.png";

static const std::map<int, std::string> INT_TO_IMG = {{0, NUMBER0}, {1, NUMBER1}, {2, NUMBER2}, {3, NUMBER3},
    {4, NUMBER4}, {5, NUMBER5}, {6, NUMBER6}, {7, NUMBER7}, {8, NUMBER8}, {9, NUMBER9}};
} // namespace number

namespace button {

namespace settings {
const std::string NORMAL = "assets/img/game-hud/button/button-settings-normal.png";
const std::string HOVER = "assets/img/game-hud/button/button-settings-hover.png";
const std::string PRESSED = "assets/img/game-hud/button/button-settings-pressed.png";
} // namespace settings

} // namespace button

static const std::string BACKGROUND = "assets/img/game-hud/background.png";
static const std::string DOUBLE_DOT = "assets/img/game-hud/double-dot.png";
static const std::string TIMER_FRAME = "assets/img/game-hud/timer-frame.png";
} // namespace gamehud

} // namespace scene

#endif // INDIESTUDIO_GAMEHUD_HPP
