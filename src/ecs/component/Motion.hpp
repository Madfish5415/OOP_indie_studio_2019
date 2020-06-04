/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Motion
*/

#ifndef MOTION_HPP_
#define MOTION_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Motion {
  public:
    Motion(const irr::f32 &movementSpeed, const irr::core::vector3df &direction);
    ~Motion();

  public:
    irr::f32 movementSpeed;
    irr::core::vector3df direction;
};

} // namespace ecs::component

#endif /* !MOTION_HPP_ */
