/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <unordered_map>

/**
 * @file Sound.hpp
 * @brief Sound Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace ecs
 * @namespace component
 */
namespace ecs::component {

/**
 * @class Sound
 * @brief Add sound list of an entity.
 */
class Sound {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param paths : List of sounds names with sounds paths.
     */
    Sound(const std::unordered_map<std::string, std::string>& paths = std::unordered_map<std::string, std::string>());
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param sound : Element to be copied.
     */
    Sound(const Sound& sound);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Sound();

  public:
    std::unordered_map<std::string, std::shared_ptr<sf::Music>> sounds; /** < List of sounds names with sounds. */
    std::vector<std::string> soundsToPlay; /** < List of sounds name to be played. */
};

} // namespace ecs::component

#endif /* !SOUND_HPP_ */
