/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Blink.cpp
*/

#include "Blink.hpp"

using namespace ecs::component;

Blink::Blink(irr::u32 millisecond) : millisecond(millisecond), lastUpdate(0)
{
}

Blink::Blink(const Blink& blink) = default;

Blink::~Blink() = default;