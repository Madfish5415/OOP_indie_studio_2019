/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Position.hpp
*/

#ifndef INDIESTUDIO_POSITION_HPP
#define INDIESTUDIO_POSITION_HPP

namespace ecs::component {

class Position {
  public:
    Position(int x = 1, int y = 1);
    Position(const Position& position);
    ~Position();

  public:
    int x;
    int y;
};

} // namespace ecs::component

#endif // INDIESTUDIO_POSITION_HPP
