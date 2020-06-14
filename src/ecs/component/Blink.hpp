/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Blink.hpp
*/

#ifndef INDIESTUDIO_BLINK_COMP_HPP
#define INDIESTUDIO_BLINK_COMP_HPP

#include <irrlicht.h>

/**
 * @file Blink.hpp
 * @brief Blink Class
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
 * @class Blink
 * @brief Allow entity to blink.
 */
class Blink {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param millisecond : Blink delay.
     */
    Blink(irr::u32 millisecond = 2000);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param blink : Element to be copied.
     */
    Blink(const Blink& blink);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Blink();

  public:
    size_t millisecond; /** < Blink delay. */
    irr::u32 lastUpdate; /** < Last time where the entity blink. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_BLINK_COMP_HPP
