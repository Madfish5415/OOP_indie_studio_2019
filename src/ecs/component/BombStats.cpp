/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStats
*/

#include "BombStats.hpp"

BombStats::BombStats(const size_t &bombRadius, const bool &wallPass)
{
    _bombRadius = bombRadius;
    _wallPass = wallPass;
}

BombStats::~BombStats()
{
}
