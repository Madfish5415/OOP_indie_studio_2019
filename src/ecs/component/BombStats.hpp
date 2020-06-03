/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStats
*/

#ifndef BOMBSTATS_HPP_
#define BOMBSTATS_HPP_

#include <cstddef>

class BombStats {
  public:
    BombStats(const size_t &bombRadius, const bool &wallPass);
    ~BombStats();

  public:
    size_t bombRadius;
    bool wallPass;
};

#endif /* !BOMBSTATS_HPP_ */
