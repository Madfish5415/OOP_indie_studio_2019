/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** LoadingMenu.hpp
*/

#ifndef INDIESTUDIO_LOADINGMENU_HPP
#define INDIESTUDIO_LOADINGMENU_HPP

#include <irrlicht.h>

#include "../ecs/Universe.hpp"

namespace scene {

class LoadingMenu {
  public:
    LoadingMenu() = delete;
    ~LoadingMenu() = delete;

  public:
    static void init(ecs::Universe* universe);
    static void destroy(ecs::Universe* universe);
};

namespace loadingmenu {
static const std::string LOGO = "assets/img/loading-menu/logo.png";
static const std::string TEXT = "assets/img/loading-menu/press-key.png";
static const std::string MUSIC = "assets/music/loading-menu/background.ogg";
} // namespace loadingmenu

} // namespace scene

#endif // INDIESTUDIO_LOADINGMENU_HPP
