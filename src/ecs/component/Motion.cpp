/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Motion
*/

#include "Motion.hpp"

Motion::Motion(const irr::f32 &movementSpeed, const irr::core::vector3df &direction)
{
    _movementSpeed = movementSpeed;
    _direction = direction;
}

Motion::~Motion()
{
}
