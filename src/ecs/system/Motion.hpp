/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Motion.hpp
*/

#ifndef INDIESTUDIO_MOTION_HPP
#define INDIESTUDIO_MOTION_HPP

#include "../System.hpp"

namespace ecs::system {

class Motion : public System {
  public:
    explicit Motion(ecs::WorldManager *worldManager);
    ~Motion() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_MOTION_HPP
