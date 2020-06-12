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

namespace ecs::component {

class Music {
  public:
    Music(const std::string& musicPath = "", const sf::Time offset = sf::Time::Zero);
    Music(const Music& music);
    virtual ~Music();

  public:
    std::shared_ptr<sf::Music> music;
    sf::Time offset;
    std::string musicPath;
};

} // namespace ecs::component

#endif /* !MUSIC_HPP_ */
