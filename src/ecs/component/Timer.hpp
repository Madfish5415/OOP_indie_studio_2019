/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Timer.hpp
*/

#ifndef INDIESTUDIO_TIMER_COMP_HPP
#define INDIESTUDIO_TIMER_COMP_HPP

#include <irrlicht.h>

/**
 * @file Timer.hpp
 * @brief Timer Class
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
 * @class Timer
 * @brief A timer.
 */
class Timer {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param delay : The delay.
     */
    Timer(irr::u32 delay = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param timer : Element to be copied.
     */
    Timer(const Timer& timer);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Timer();

  public:
    irr::u32 delay; /** < The delay. */
    irr::u32 elapsed; /** < Already elapsed time. */
    irr::u32 lastUpdate; /** < The last time the component was updated. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_TIMER_COMP_HPP
