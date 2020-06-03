/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Position.cpp
*/

#include "Position.hpp"

using namespace ecs::component;

Position::Position(int x, int y) : x(x), y(y)
{
}
Position::Position(const Position& position)
{
    x = position.x;
    y = position.y;
}

Position::~Position() = default;