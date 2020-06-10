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
#include <memory>

namespace ecs::component {

class Sound {
  public:
    Sound(const std::unordered_map<std::string, std::string>& paths = std::unordered_map<std::string, std::string>());
    Sound(const Sound &sound);
    ~Sound();

  public:
    std::unordered_map<std::string, std::shared_ptr<sf::Music>> sounds;
    std::vector<std::string> soundsToPlay;
};

} // namespace ecs::component

#endif /* !SOUND_HPP_ */
