/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Delay
*/

#ifndef DELAY_HPP_
#define DELAY_HPP_

#include <irrlicht.h>

/**
 * @file Delay.hpp
 * @brief Delay Class
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
 * @class Delay
 * @brief Add a delay to an entity.
 */
class Delay {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param value : The delay.
     */
    Delay(irr::u32 value = 2000);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param delay : Element to be copied.
     */
    Delay(const Delay& delay);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Delay();

  public:
    size_t value; /** < The delay. */
    irr::u32 lastUpdate; /** < The last time the component was updated. */
};

} // namespace ecs::component

#endif /* !DELAY_HPP_ */
