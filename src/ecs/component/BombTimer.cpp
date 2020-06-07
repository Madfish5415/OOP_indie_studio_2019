/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#include "BombTimer.hpp"

#include <ctime>

using namespace ecs::component;

BombTimer::BombTimer(const irr::u32 &duration, irr::IrrlichtDevice *dev)
    : duration(duration)
{
    timerStart = (dev) ? dev->getTimer()->getTime() : 0;
}

BombTimer::BombTimer(const BombTimer &bombTimer) : timerStart(bombTimer.duration), duration(bombTimer.duration)
{
}

BombTimer::~BombTimer() = default;
