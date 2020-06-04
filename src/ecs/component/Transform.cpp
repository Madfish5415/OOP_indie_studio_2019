/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Transform
*/

#include "Transform.hpp"

using namespace ecs::component;

Transform::Transform(const irr::core::vector3df &position) : position(position)
{
}

Transform::~Transform() = default;