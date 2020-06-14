/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Stats
*/

#ifndef STATS_HPP_
#define STATS_HPP_

#include <cstddef>

/**
 * @file Stats.hpp
 * @brief Stats Class
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
 * @class Stats
 * @brief Render stats.
 */
class Stats {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param moveSpeed : move speed stat value.
     * @param bombRadius : bomb radius stat value.
     * @param maxBomb : max bomb stat value.
     * @param wallPass : wall pass stat value.
     */
    Stats(const size_t &moveSpeed = 1, const size_t &bombRadius = 2, const size_t &maxBomb = 1,
        const bool &wallPass = false);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param stats : Element to be copied.
     */
    Stats(const Stats &stats);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Stats();

  public:
    /**
     * @brief operator+ method
     * Overload the + operator.
     * @param right : element to add.
     * @return The result of the addition.
     */
    Stats operator+(const Stats &right);

  public:
    size_t moveSpeed; /** < The move speed stat value. */
    size_t bombRadius; /** < The bomb radius stat value. */
    size_t maxBomb; /** < The max bomb stat value. */
    size_t wallPass; /** < The wall pass stat value. */
};

} // namespace ecs::component

#endif /* !STATS_HPP_ */
