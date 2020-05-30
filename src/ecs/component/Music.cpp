/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include "Music.hpp"

Music::Music(const std::string &musicPath) : _music(new sf::Music())
{
    _music->openFromFile(musicPath);
}

Music::~Music()
{
    delete _music;
}
