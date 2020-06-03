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
    size_t moveSpeed;
    size_t bombRadius;
    size_t maxBomb;
    size_t wallPass;
};

#endif /* !STATS_HPP_ */
