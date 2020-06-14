/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef BOMBTIMER_HPP_
#define BOMBTIMER_HPP_

#include <irrlicht.h>

/**
 * @file BombTimer.hpp
 * @brief BombTimer Class
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
 * @class BombTimer
 * @brief Delay before an explosion.
 */
class BombTimer {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param delay : Delay before the explosion.
     */
    BombTimer(irr::u32 delay = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param bombTimer : Element to be copied.
     */
    BombTimer(const BombTimer &bombTimer);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~BombTimer();

  public:
    irr::u32 delay; /** < Delay before the explosion. */
    irr::u32 elapsed; /** < Already elapsed time. */
    irr::u32 lastUpdate; /** < Last time where the entity was updated. */
};

} // namespace ecs::component

#endif /* !BOMBTIMER_HPP_ */
