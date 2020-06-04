/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

#include "../component/Sound.hpp"

using namespace ecs::system;

Sound::Sound(ecs::WorldManager *worldManager) : System(worldManager)
{
}

Sound::~Sound() = default;

void Sound::update()
{
    for (const auto& entity: entities) {
        auto& sounds = worldManager->getComponent<ecs::component::Sound>(entity);
        for (size_t i = 0; i < sounds.soundsToPlay.size(); i++) {
            sounds.sounds[sounds.soundsToPlay[i]]->play();
            sounds.soundsToPlay.erase(sounds.soundsToPlay.begin() + i);
        }
    }
}
