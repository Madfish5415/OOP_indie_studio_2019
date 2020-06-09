/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <string>

namespace ecs::component {

class Music {
  public:
    Music(const std::string &musicPath = "");
    Music(const Music& music);
    ~Music();

  public:
    sf::Music* music;
    std::string musicPath;
};

} // namespace ecs::component

#endif /* !MUSIC_HPP_ */
