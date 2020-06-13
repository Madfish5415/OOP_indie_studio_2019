/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStats
*/

#include "BombStats.hpp"

using namespace ecs::component;

BombStats::BombStats(const size_t &bombRadius, const bool &wallPass)
    : bombRadius(bombRadius), wallPass(wallPass), explode(false)
{
}

BombStats::BombStats(const BombStats &bombstat) = default;

BombStats::~BombStats() = default;
