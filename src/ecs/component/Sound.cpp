/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#include "Sound.hpp"

using namespace ecs::component;

Sound::Sound(const std::string &soundPath) : sound(new sf::Music())
{
    sound->openFromFile(soundPath);
}

Sound::~Sound() = default;