/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Size
*/

#ifndef SIZE_HPP_
#define SIZE_HPP_

#include <irrlicht.h>

/**
 * @file Size.hpp
 * @brief Size Class
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
 * @class Size
 * @brief Define the 3D Size of an entity.
 */
class Size {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param size : The 3D size of an element.
     */
    Size(const irr::core::vector3df &size = irr::core::vector3df(0.0));
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param size : Element to be copied.
     */
    Size(const Size &size);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Size();

  public:
    irr::core::vector3df size; /** < The size. */
};

} // namespace ecs::component

#endif /* !SIZE_HPP_ */
