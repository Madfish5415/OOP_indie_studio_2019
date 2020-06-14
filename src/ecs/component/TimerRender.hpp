/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerRender.hpp
*/

#ifndef INDIESTUDIO_TIMERRENDER_COMP_HPP
#define INDIESTUDIO_TIMERRENDER_COMP_HPP

#include "../Def.hpp"

/**
 * @file TimerRender.hpp
 * @brief TimerRender Class
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
 * @class TimerRender
 * @brief A render for a timer.
 */
class TimerRender {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param owner : The timer entity.
     * @param position : The position number to be displayed (mm:ss).
     */
    TimerRender(Entity owner = 0, size_t position = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param timerRender : Element to be copied.
     */
    TimerRender(const TimerRender& timerRender);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~TimerRender();

  public:
    ecs::Entity owner; /** < The timer entity. */
    size_t position; /** < The position number to be displayed (mm:ss). */
};

} // namespace ecs::component

#endif // INDIESTUDIO_TIMERRENDER_COMP_HPP
