/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sliding
*/

#ifndef INDIESTUDIO_SLIDING_COMP_HPP
#define INDIESTUDIO_SLIDING_COMP_HPP

#include <irrlicht.h>

/**
 * @file Sliding.hpp
 * @brief Sliding Class
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
 * @class Sliding
 * @brief Add sliding effect on the entity.
 */
class Sliding {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param delay : Sliding delay.
     * @param endPosition : The end position of the entity.
     * @param addPosition : The vector to be added each delay.
     */
    Sliding(irr::u32 delay = 1000,
        const irr::core::vector2d<irr::s32>& endPosition = irr::core::vector2d<irr::s32>(0, 0),
        const irr::core::vector2d<irr::s32>& addPosition = irr::core::vector2d<irr::s32>(0, 0));
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param sliding : Element to be copied.
     */
    Sliding(const Sliding& sliding);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Sliding();

  public:
    irr::u32 delay; /** < Sliding delay. */
    irr::u32 lastUpdate; /** < Last time where the entity blink. */
    irr::core::vector2d<irr::s32> endPosition; /** < The end position of the entity. */
    irr::core::vector2d<irr::s32> addPosition; /** < The vector to be added each delay. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_SLIDING_COMP_HPP
