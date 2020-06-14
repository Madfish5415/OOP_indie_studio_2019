/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Spinner.hpp
*/

#ifndef INDIESTUDIO_SPINNER_COMP_HPP
#define INDIESTUDIO_SPINNER_COMP_HPP

#include <irrlicht.h>

/**
 * @file Spinner.hpp
 * @brief Spinner Class
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
 * @class Spinner
 * @brief Add spinner effect to an entity.
 */
class Spinner {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param rotation : The rotation vector.
     * @param delay : Spinning delay.
     */
    Spinner(
        const irr::core::vector3d<irr::f32>& rotation = irr::core::vector3d<irr::f32>(0, 0, 0), irr::u32 delay = 2000);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param spinner : Element to be copied.
     */
    Spinner(const Spinner& spinner);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Spinner();

  public:
    irr::core::vector3d<irr::f32> rotation; /** < The rotation vector. */
    irr::u32 delay; /** < Sliding delay. */
    irr::u32 lastUpdate; /** < Last time where the entity spin. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_SPINNER_COMP_HPP
