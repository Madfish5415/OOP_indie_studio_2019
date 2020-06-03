/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#include "BombTimer.hpp"

#include <ctime>

BombTimer::BombTimer(const irr::u32 &duration, irr::IrrlichtDevice *device)
    : timerStart(device->getTimer()->getTime()), duration(duration)
{
}

BombTimer::~BombTimer() = default;
