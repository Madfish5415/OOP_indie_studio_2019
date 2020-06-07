/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Sound.hpp
*/

#ifndef INDIESTUDIO_SOUND_HPP
#define INDIESTUDIO_SOUND_HPP

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Sound : public ecs::System {
  public:
    explicit Sound(ecs::WorldManager *worldManager);
    ~Sound() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_SOUND_HPP
