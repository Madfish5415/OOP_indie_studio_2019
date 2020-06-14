/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Breakable
*/

#ifndef INDIESTUDIO_BREAKABLE_HPP
#define INDIESTUDIO_BREAKABLE_HPP

/**
 * @file Breakable.hpp
 * @brief Breakable Class
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
 * @class Breakable
 * @brief Tell if an entity is breakable.
 */
class Breakable {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    Breakable();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param breakable : Element to be copied.
     */
    Breakable(const Breakable& breakable);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Breakable();
};

} // namespace ecs::component

#endif // INDIESTUDIO_BREAKABLE_HPP
