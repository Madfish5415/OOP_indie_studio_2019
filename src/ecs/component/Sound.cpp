/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sound
*/

#include "Sound.hpp"

using namespace ecs::component;

Sound::Sound(const std::unordered_map<std::string, std::string>& paths)
{
    for (const auto& i : paths) {
        sounds[i.first] = new sf::Music();
        sounds[i.first]->openFromFile(i.first);
    }
}

Sound::~Sound() = default;