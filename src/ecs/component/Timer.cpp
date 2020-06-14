/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

using namespace ecs::component;

Timer::Timer(irr::u32 delay) : delay(delay), elapsed(0), lastUpdate(0)
{
}

Timer::Timer(const Timer& timer) = default;

Timer::~Timer() = default;
