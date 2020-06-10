/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStats
*/

#ifndef BOMBSTATS_HPP_
#define BOMBSTATS_HPP_

#include <cstddef>

namespace ecs::component {

class BombStats {
  public:
    BombStats(const size_t &bombRadius = 0, const bool &wallPass = false);
    BombStats(const BombStats &bombstat);
    ~BombStats();

  public:
    size_t bombRadius;
    bool wallPass;
    bool explode;
};

} // namespace ecs::component
#endif /* !BOMBSTATS_HPP_ */
