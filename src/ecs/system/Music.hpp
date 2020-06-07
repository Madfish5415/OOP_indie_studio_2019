/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Music.hpp
*/

#ifndef INDIESTUDIO_MUSIC_HPP
#define INDIESTUDIO_MUSIC_HPP

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Music : public ecs::System {
  public:
    explicit Music(ecs::WorldManager *worldManager);
    ~Music() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_MUSIC_HPP
