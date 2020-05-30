/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound(const std::string &soundPath) : _sound(new sf::Music())
{
    _sound->openFromFile(soundPath);
}

Sound::~Sound()
{
    delete _sound;
}
