/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <memory>
#include <string>

/**
 * @file Music.hpp
 * @brief Music Class
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
 * @class Music
 * @brief Add music.
 */
class Music {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param musicPath : The path to the music.
     * @param offset : The time when the music must begin.
     */
    Music(const std::string& musicPath = "", const sf::Time offset = sf::Time::Zero);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param music : Element to be copied.
     */
    Music(const Music& music);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Music();

  public:
    std::shared_ptr<sf::Music> music; /** < The music element. */
    sf::Time offset; /** < The time when the music must begin. */
    std::string musicPath; /** < The path to the music. */
};

} // namespace ecs::component

#endif /* !MUSIC_HPP_ */
