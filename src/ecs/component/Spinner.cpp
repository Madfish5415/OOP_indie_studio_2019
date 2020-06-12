/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Spinner.cpp
*/

#include "Spinner.hpp"

using namespace ecs::component;

Spinner::Spinner(const irr::core::vector3d<irr::f32>& rotation, irr::u32 delay)
    : rotation(rotation), delay(delay), lastUpdate(0)
{
}
Spinner::Spinner(const Spinner& spinner) = default;

Spinner::~Spinner() = default;
