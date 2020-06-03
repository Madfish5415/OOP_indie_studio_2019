/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Velocity.hpp
*/

#ifndef INDIESTUDIO_VELOCITY_HPP
#define INDIESTUDIO_VELOCITY_HPP

namespace ecs::component {

class Velocity {
  public:
    Velocity(int x = 0, int y = 0);
    Velocity(const Velocity& velocity);
    ~Velocity();

  public:
    int x;
    int y;
};

} // namespace ecs::component

#endif // INDIESTUDIO_VELOCITY_HPP
