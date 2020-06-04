/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Motion
*/

#include "Motion.hpp"

using namespace ecs::component;

Motion::Motion(const irr::f32 &movementSpeed, const irr::core::vector3df &direction)
    : movementSpeed(movementSpeed), direction(direction)
{
}

Motion::~Motion() = default;