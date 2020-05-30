/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>
#include <SFML/Audio.hpp>

class Music {
    public:
        Music(const std::string &musicPath);
        ~Music();

    public:
        sf::Music *_music;
};

#endif /* !MUSIC_HPP_ */
