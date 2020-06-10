/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Stats
*/

#include "Stats.hpp"

using namespace ecs::component;

Stats::Stats(const size_t &moveSpeed, const size_t &bombRadius, const size_t &maxBomb, const bool &wallPass)
    : moveSpeed(moveSpeed), bombRadius(bombRadius), maxBomb(maxBomb), wallPass(wallPass)
{
}

Stats::Stats(const Stats &stat) = default;

Stats Stats::operator+(const Stats& right)
{
    Stats newStats(*this);

    newStats.moveSpeed += right.moveSpeed;
    if (newStats.moveSpeed > 9) {
        newStats.moveSpeed = 9;
    }
    newStats.bombRadius += right.bombRadius;
    if (newStats.bombRadius > 9) {
        newStats.bombRadius = 9;
    }
    newStats.maxBomb += right.maxBomb;
    if (newStats.maxBomb > 9) {
        newStats.maxBomb = 9;
    }
    newStats.wallPass = newStats.wallPass || right.wallPass;
    return newStats;
}

Stats::~Stats() = default;