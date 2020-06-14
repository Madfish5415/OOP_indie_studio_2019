/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Motion
*/

#ifndef MOTION_HPP_
#define MOTION_HPP_

#include <irrlicht.h>

/**
 * @file Motion.hpp
 * @brief Motion Class
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
 * @class Motion
 * @brief Allow entity to move.
 */
class Motion {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param movementSpeed : The movement speed of the entity.
     * @param direction : The direction of the entity.
     */
    Motion(const irr::f32 &movementSpeed = 0.0, const irr::core::vector3df &direction = irr::core::vector3df(0.0));
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param motion : Element to be copied.
     */
    Motion(const Motion &motion);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Motion();

  public:
    irr::f32 movementSpeed; /** < The movement speed of the entity. */
    irr::core::vector3df direction; /** < The direction of the entity. */
};

} // namespace ecs::component

#endif /* !MOTION_HPP_ */
