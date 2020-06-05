/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Stats
*/

#ifndef STATS_HPP_
#define STATS_HPP_

#include <cstddef>

namespace ecs::component {

class Stats {
  public:
    Stats(const size_t &moveSpeed = 0, const size_t &bombRadius = 0, const size_t &maxBomb = 0, const bool &wallPass = 0);
    Stats(const Stats& stats);
    ~Stats();

  public:
    size_t moveSpeed;
    size_t bombRadius;
    size_t maxBomb;
    size_t wallPass;
};

} // namespace ecs::component

#endif /* !STATS_HPP_ */
