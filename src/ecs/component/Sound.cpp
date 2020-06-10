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
        sounds[i.first].reset(new sf::Music());
        sounds[i.first]->openFromFile(i.second);
    }
}

Sound::Sound(const Sound &sound) : sounds(sound.sounds), soundsToPlay(sound.soundsToPlay)
{
}

Sound::~Sound() = default;