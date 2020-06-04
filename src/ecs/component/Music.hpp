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
    explicit Music(const std::string &musicPath);
    ~Music();

  public:
    sf::Music *music;
};

} // namespace ecs::component

#endif /* !MUSIC_HPP_ */
