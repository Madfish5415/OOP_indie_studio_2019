/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStats
*/

#ifndef BOMBSTATS_HPP_
#define BOMBSTATS_HPP_

#include <cstddef>

/**
 * @file BombStats.hpp
 * @brief BombStats Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace ecs
 * @namespace component
 */
namespace ecs::component {

/**
 * @class BombStats
 * @brief Allow entity to explode and have stats.
 */
class BombStats {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param bombRadius : Radius of the bomb.
     * @param wallPass : Say if the bomb can pass through boxes.
     */
    BombStats(const size_t &bombRadius = 0, const bool &wallPass = false);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param bombstat : Element to be copied.
     */
    BombStats(const BombStats &bombstat);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~BombStats();

  public:
    size_t bombRadius; /** < Radius of the bomb. */
    bool wallPass; /** < wall pass stat. */
    bool explode; /** < Tell if the bomb already explode. */
};

} // namespace ecs::component

#endif /* !BOMBSTATS_HPP_ */
