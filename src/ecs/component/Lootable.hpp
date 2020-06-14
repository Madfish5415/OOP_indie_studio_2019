/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Lootable
*/

#ifndef LOOTABLE_HPP_
#define LOOTABLE_HPP_

/**
 * @file Lootable.hpp
 * @brief Lootable Class
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
 * @class Lootable
 * @brief Define if an entity is lootable.
 */
class Lootable {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    Lootable();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param lootable : Element to be copied.
     */
    Lootable(const Lootable& lootable);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Lootable();
};

} // namespace ecs::component

#endif /* !LOOTABLE_HPP_ */
