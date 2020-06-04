/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include <string>

namespace ecs::component {

class Sound {
  public:
    explicit Sound(const std::string &soundPath);
    ~Sound();

  public:
    sf::Music *sound;
};

} // namespace ecs::component

#endif /* !SOUND_HPP_ */
