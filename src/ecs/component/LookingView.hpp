/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LookingView
*/

#ifndef LOOKINGVIEW_HPP_
#define LOOKINGVIEW_HPP_

#include <irrlicht.h>

/**
 * @file LookingView.hpp
 * @brief LookingView Class
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
 * @class LookingView
 * @brief Define where an entity is looking.
 */
class LookingView {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param direction : The direction.
     */
    LookingView(const irr::core::vector3df &direction = irr::core::vector3df(0.0));
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param lookingView : Element to be copied.
     */
    LookingView(const LookingView &lookingView);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~LookingView();

  public:
    irr::core::vector3df direction; /** < The direction. */
};

} // namespace ecs::component

#endif /* !LOOKINGVIEW_HPP_ */
