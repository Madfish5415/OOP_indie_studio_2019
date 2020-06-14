/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

/**
 * @file PowerUp.hpp
 * @brief PowerUp Class
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
 * @class PowerUp
 * @brief Define a power up.
 */
class PowerUp {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    PowerUp();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param powerUp : Element to be copied.
     */
    PowerUp(const PowerUp& powerUp);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~PowerUp();
};

} // namespace ecs::component

#endif /* !POWERUP_HPP_ */
