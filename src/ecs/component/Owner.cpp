/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Owner
*/

#include "Owner.hpp"

using namespace ecs::component;

Owner::Owner(const ecs::Entity &ID) : entity(ID)
{
}

Owner::Owner(const Owner &owner) = default;

Owner::~Owner() = default;
