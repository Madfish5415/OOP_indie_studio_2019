/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>
#include <SFML/Audio.hpp>

class Sound {
    public:
        Sound();
        ~Sound();

    public:
        sf::Music *_sound;
};

#endif /* !SOUND_HPP_ */
