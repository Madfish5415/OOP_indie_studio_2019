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

namespace scene {

class Menu {
  public:
    Menu() = delete;
    ~Menu() = delete;

  public:
    static void init(ecs::Universe* universe, sf::Time musicTimer);
    static void reset();
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
