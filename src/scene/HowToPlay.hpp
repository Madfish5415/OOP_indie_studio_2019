/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** HowToPlay.hpp
*/

#ifndef INDIESTUDIO_HOWTOPLAY_HPP
#define INDIESTUDIO_HOWTOPLAY_HPP

#include <SFML/Audio.hpp>

#include "../ecs/Universe.hpp"

/**
 * @file HowToPlay.hpp
 * @brief HowToPlay Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class HowToPlay
 * @brief Handle the HowToPlay scene.
 */
class HowToPlay {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    HowToPlay() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~HowToPlay() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole HowToPlay scene.
     * @param universe : A pointer on the universe.
     * @param musicTimer : Playback time of current music.
     */
    static void init(ecs::Universe *universe, sf::Time musicTimer);
    /**
     * @brief destroy method
     * This method destroy the whole HowToPlay scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe *universe);
};

namespace howtoplay {

namespace button::back {
static const std::string NORMAL = "assets/img/how-to-play/button/button-back-normal.png";
static const std::string HOVER = "assets/img/how-to-play/button/button-back-hover.png";
static const std::string PRESSED = "assets/img/how-to-play/button/button-back-pressed.png";
} // namespace button

static const std::string BACKGROUND = "assets/img/how-to-play/background.png";
} // namespace howtoplay

} // namespace scene

#endif // INDIESTUDIO_HOWTOPLAY_HPP
