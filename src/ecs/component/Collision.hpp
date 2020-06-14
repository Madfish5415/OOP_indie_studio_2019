/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collision
*/

#ifndef COLLISON_HPP_
#define COLLISON_HPP_

/**
 * @file Collision.hpp
 * @brief Collision Class
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
 * @class Collision
 * @brief Tell if an entity is breakable.
 */
class Collision {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    Collision();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param collision : Element to be copied.
     */
    Collision(const Collision& collision);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Collision();
};

} // namespace ecs::component

#endif /* !ANIMATION_HPP_ */
