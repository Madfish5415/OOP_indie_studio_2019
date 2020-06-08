/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#include "BombTimer.hpp"

#include <ctime>

using namespace ecs::component;

BombTimer::BombTimer(const irr::u32 &delay) : delay(delay), elapsed(0), lastUpdate(0)
{
}

BombTimer::BombTimer(const BombTimer &bombTimer)
    : delay(bombTimer.delay), elapsed(bombTimer.elapsed), lastUpdate(bombTimer.lastUpdate)
{
}

BombTimer::~BombTimer() = default;
