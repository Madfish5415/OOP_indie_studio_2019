/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Velocity.hpp
*/

#ifndef INDIESTUDIO_VELOCITY_HPP
#define INDIESTUDIO_VELOCITY_HPP

/**
 * @file Velocity.hpp
 * @brief Velocity Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::component
 */

namespace ecs::component {
/**
 * @class Velocity
 * @brief Description of the entity that allows the entity to move.
 */

class Velocity {
  public:
    /**
     * @brief Constructor
     * Constructor of Velocity Class.
     * @param x : Position in horizontal axis.
     * @param y : Position in vertical axis.
     */
    Velocity(int x = 0, int y = 0);
    /**
     * @brief Copy Constructor
     * Copy Constructor of Velocity Class.
     */
    Velocity(const Velocity& velocity);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Velocity();

  public:
    int x; /**< Position in horizontal axis. */
    int y; /**< Position in vertical axis. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_VELOCITY_HPP
