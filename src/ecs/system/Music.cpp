/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Music.cpp
*/

#include "Music.hpp"

#include "../component/Music.hpp"

using namespace ecs::system;

Music::Music(ecs::WorldManager *worldManager) : System(worldManager)
{
}

Music::~Music() = default;

void Music::update()
{
    for (const auto& entity: entities) {
        auto& music = worldManager->getComponent<ecs::component::Music>(entity);
        if (music.music->getStatus() == sf::Music::Status::Stopped) {
            music.music->play();
        }
    }
}