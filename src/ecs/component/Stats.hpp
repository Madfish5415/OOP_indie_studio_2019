/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Stats
*/

#ifndef STATS_HPP_
#define STATS_HPP_

#include <cstddef>

class Stats {
    public:
        Stats(const size_t &moveSpeed, const size_t &bombRadius, const size_t &maxBomb, const bool &wallPass);
        ~Stats();

    public:
        size_t _moveSpeed;
        size_t _bombRadius;
        size_t _maxBomb;
        size_t _wallPass;
};

#endif /* !STATS_HPP_ */
