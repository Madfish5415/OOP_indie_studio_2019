/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include "Music.hpp"

using namespace ecs::component;

Music::Music(const std::string &musicPath) : music(std::shared_ptr<sf::Music>())
{
    if (!musicPath.empty()) {

        music.reset(new sf::Music());
        music->openFromFile(musicPath);
        this->musicPath = musicPath;
    }
}

Music::Music(const Music& music) : musicPath(music.musicPath)
{
    if (!musicPath.empty()) {
        this->music.reset(new sf::Music());
        this->music->openFromFile(musicPath);
    }
}

Music::~Music() {
}