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

class Sound {
  public:
    explicit Sound(const std::string &soundPath);
    ~Sound();

  public:
    sf::Music *sound;
};

#endif /* !SOUND_HPP_ */
