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

class Music {
  public:
    explicit Music(const std::string &musicPath);
    ~Music();

  public:
    sf::Music *music;
};

#endif /* !MUSIC_HPP_ */
