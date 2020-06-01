/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Stats
*/

#include "Stats.hpp"

Stats::Stats(const size_t &moveSpeed, const size_t &bombRadius, const size_t &maxBomb, const bool &wallPass)
{
    _moveSpeed = moveSpeed;
    _bombRadius = bombRadius;
    _maxBomb = maxBomb;
    _wallPass = wallPass;
}

Stats::~Stats()
{
}
