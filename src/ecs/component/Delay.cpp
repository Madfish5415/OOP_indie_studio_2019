/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Delay
*/

#include "Delay.hpp"

using namespace ecs::component;

Delay::Delay(irr::u32 delay) : value(delay), lastUpdate(0)
{
}

Delay::Delay(const Delay& delay) = default;

Delay::~Delay() = default;