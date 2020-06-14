/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** CountDown.hpp
*/

#ifndef INDIESTUDIO_COUNTDOWN_SCENE_HPP
#define INDIESTUDIO_COUNTDOWN_SCENE_HPP

#include "../ecs/Universe.hpp"

/**
 * @file CountDown.hpp
 * @brief CountDown Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class CountDown
 * @brief Handle the CountDown scene.
 */
class CountDown {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    CountDown() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~CountDown() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole CountDown scene.
     * @param universe : A pointer to the universe.
     */
    static void init(ecs::Universe *universe);
    /**
     * @brief destroy method
     * This method destroy the whole CountDown scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe *universe);

  public:
    static std::vector<ecs::Entity> images; /** < List of all images used in this scene. */
    static std::vector<irr::gui::IGUIInOutFader *> faders; /** < List of all faders used in this scene. */
};

namespace countdown {
static const std::string THREE = "assets/img/countdown/three.png";
static const std::string TWO = "assets/img/countdown/two.png";
static const std::string ONE = "assets/img/countdown/one.png";
static const std::string GO = "assets/img/countdown/go.png";
static const std::string MUSIC = "assets/music/countdown/countdown.wav";
} // namespace countdown

} // namespace scene
#endif // INDIESTUDIO_COUNTDOWN_HPP
