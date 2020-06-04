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

Stats::~Stats() = default;