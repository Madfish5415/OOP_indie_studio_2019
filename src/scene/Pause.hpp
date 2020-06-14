/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Pause.hpp
*/

#ifndef INDIESTUDIO_PAUSE_HPP
#define INDIESTUDIO_PAUSE_HPP

#include <irrlicht.h>

#include "../ecs/WorldManager.hpp"

/**
 * @file Pause.hpp
 * @brief Pause Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class Pause
 * @brief Handle the Pause scene.
 */
class Pause {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    Pause() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~Pause() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole Pause scene.
     * @param universe : A pointer on the universe.
     */
    static void init(ecs::Universe* universe);
    /**
     * @brief destroy method
     * This method destroy the whole Pause scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe* universe);

  public:
    static std::vector<ecs::Entity> buttons; /** < List of all used buttons on this scene. */
    static std::vector<ecs::Entity> images; /** < List of all used images on this scene. */
};

namespace pause {

namespace button {

namespace resume {
const std::string NORMAL = "assets/img/pause/button/button-resume-normal.png";
const std::string HOVER = "assets/img/pause/button/button-resume-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-resume-pressed.png";
} // namespace resume

namespace settings {
const std::string NORMAL = "assets/img/pause/button/button-settings-normal.png";
const std::string HOVER = "assets/img/pause/button/button-settings-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-settings-pressed.png";
} // namespace settings

namespace menu {
const std::string NORMAL = "assets/img/pause/button/button-menu-normal.png";
const std::string HOVER = "assets/img/pause/button/button-menu-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-menu-pressed.png";
} // namespace menu

} // namespace button

static const std::string BACKGROUND = "assets/img/pause/pause.png";
} // namespace pause

} // namespace scene

#endif // INDIESTUDIO_PAUSE_HPP
