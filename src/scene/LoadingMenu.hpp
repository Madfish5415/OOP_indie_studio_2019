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

/**
 * @file LoadingMenu.hpp
 * @brief LoadingMenu Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class LoadingMenu
 * @brief Handle the LoadingMenu scene.
 */
class LoadingMenu {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    LoadingMenu() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~LoadingMenu() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole LoadingMenu scene.
     * @param universe : A pointer on the universe.
     */
    static void init(ecs::Universe* universe);
    /**
     * @brief destroy method
     * This method destroy the whole LoadingMenu scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe* universe);
};

namespace loadingmenu {
static const std::string LOGO = "assets/img/loading-menu/logo.png";
static const std::string TEXT = "assets/img/loading-menu/press-key.png";
static const std::string MUSIC = "assets/music/loading-menu/background.ogg";
} // namespace loadingmenu

} // namespace scene

#endif // INDIESTUDIO_LOADINGMENU_HPP
