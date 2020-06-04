/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LookingView
*/

#ifndef LOOKINGVIEW_HPP_
#define LOOKINGVIEW_HPP_

#include <irrlicht.h>

namespace ecs::component {

class LookingView {
  public:
    explicit LookingView(const irr::core::vector3df &direction);
    ~LookingView();

  public:
    irr::core::vector3df direction;
};

} // namespace ecs::component

#endif /* !LOOKINGVIEW_HPP_ */
