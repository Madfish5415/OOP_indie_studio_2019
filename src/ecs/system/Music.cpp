/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Music.cpp
*/

#include "Music.hpp"

#include "../../scene/Settings.hpp"
#include "../component/Music.hpp"

using namespace ecs::system;

Music::Music(ecs::WorldManager* worldManager) : System(worldManager)
{
}

Music::~Music() = default;

void Music::update()
{
    for (const auto& entity : entities) {
        auto& music = worldManager->getComponent<ecs::component::Music>(entity);
        if (music.music) {
            auto var = music.music->getPlayingOffset();
            if (music.music->getVolume() != scene::Settings::musicVolume)
                music.music->setVolume(scene::Settings::musicVolume);
            if (music.music->getStatus() == sf::Music::Status::Stopped) {
                music.music->setPlayingOffset(music.offset);
                music.music->play();
            }
        }
    }
}