/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sliding
*/

#include "Sliding.hpp"

using namespace ecs::component;

Sliding::Sliding(
    irr::u32 delay, const irr::core::vector2d<irr::s32>& endPosition, const irr::core::vector2d<irr::s32>& addPosition)
    : delay(delay), lastUpdate(0), endPosition(endPosition), addPosition(addPosition)
{
}

Sliding::Sliding(const Sliding& sliding) = default;

Sliding::~Sliding() = default;
