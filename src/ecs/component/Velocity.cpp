/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Velocity.cpp
*/

#include "Velocity.hpp"

using namespace ecs::component;

Velocity::Velocity(int x, int y) : x(x), y(y)
{
}
Velocity::Velocity(const Velocity& velocity)
{
    x = velocity.x;
    y = velocity.y;
}

Velocity::~Velocity() = default;