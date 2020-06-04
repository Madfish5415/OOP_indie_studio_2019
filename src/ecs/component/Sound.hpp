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
#include <unordered_map>

namespace ecs::component {

class Sound {
  public:
    explicit Sound(const std::unordered_map<std::string, std::string>& paths);
    ~Sound();

  public:
    std::unordered_map<std::string, sf::Music *> sounds;
    std::vector<std::string> soundsToPlay;
};

} // namespace ecs::component

#endif /* !SOUND_HPP_ */
