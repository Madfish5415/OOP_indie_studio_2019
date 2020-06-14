/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Unbreakable
*/

#ifndef UNBREAKABLE_HPP_
#define UNBREAKABLE_HPP_

/**
 * @file Unbreakable.hpp
 * @brief Unbreakable Class
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
 * @class Unbreakable
 * @brief Define 3D position of an entity.
 */
class Unbreakable {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    Unbreakable();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param unbreakable : Element to be copied.
     */
    Unbreakable(const Unbreakable& unbreakable);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Unbreakable();
};

} // namespace ecs::component

#endif /* !UNBREAKABLE_HPP_ */
