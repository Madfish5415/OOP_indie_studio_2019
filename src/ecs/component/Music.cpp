/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include "Music.hpp"

using namespace ecs::component;

Music::Music(const std::string &musicPath) : music(new sf::Music())
{
    music->openFromFile(musicPath);
}

Music::Music(const Music& music) : music(music.music)
{
}

Music::~Music() = default;