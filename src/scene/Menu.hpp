/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Menu.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MENU_HPP
#define OOP_INDIE_STUDIO_2019_MENU_HPP

#include <irrlicht.h>

#include <SFML/Audio.hpp>

#include "../ecs/WorldManager.hpp"

/**
 * @file Menu.hpp
 * @brief Menu Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class Menu
 * @brief Handle the Menu scene.
 */
class Menu {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    Menu() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~Menu() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole Menu scene.
     * @param universe : A pointer on the universe.
     * @param musicTimer : Playback time of current music.
     */
    static void init(ecs::Universe* universe, sf::Time musicTimer);
    /**
     * @brief destroy method
     * This method destroy the whole Menu scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe* universe);
};

namespace menu {

namespace button {

namespace play {
static const std::string NORMAL = "assets/img/menu/button/button-play-normal.png";
static const std::string HOVER = "assets/img/menu/button/button-play-hover.png";
static const std::string PRESSED = "assets/img/menu/button/button-play-pressed.png";
} // namespace play

namespace htp {
static const std::string NORMAL = "assets/img/menu/button/button-htp-normal.png";
static const std::string HOVER = "assets/img/menu/button/button-htp-hover.png";
static const std::string PRESSED = "assets/img/menu/button/button-htp-pressed.png";
} // namespace htp

namespace settings {
const std::string NORMAL = "assets/img/menu/button/button-settings-normal.png";
const std::string HOVER = "assets/img/menu/button/button-settings-hover.png";
const std::string PRESSED = "assets/img/menu/button/button-settings-pressed.png";
} // namespace settings

namespace quit {
static const std::string NORMAL = "assets/img/menu/button/button-quit-normal.png";
static const std::string HOVER = "assets/img/menu/button/button-quit-hover.png";
static const std::string PRESSED = "assets/img/menu/button/button-quit-pressed.png";
} // namespace quit

} // namespace button

static const std::string BACKGROUND = "assets/img/menu/background.jpg";
static const std::string BOMBERMAN_LOGO = "assets/img/menu/bomberman_logo.png";
static const std::string MUSIC = "assets/music/menu/background.ogg";
} // namespace menu

} // namespace scene

#endif // OOP_INDIE_STUDIO_2019_MENU_HPP
