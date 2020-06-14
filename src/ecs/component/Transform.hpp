/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include <irrlicht.h>

/**
 * @file Transform.hpp
 * @brief Transform Class
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
 * @class Transform
 * @brief Define 3D position of an entity.
 */
class Transform {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param position : The 3D position of an entity.
     */
    Transform(const irr::core::vector3df& position = irr::core::vector3df(0.0));
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param transform : Element to be copied.
     */
    Transform(const Transform& transform);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Transform();

  public:
    irr::core::vector3df position; /** < The 3D position of an entity. */
};

} // namespace ecs::component

#endif /* !TRANSFORM_HPP_ */
