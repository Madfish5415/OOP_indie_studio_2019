/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Transform {
  public:
    Transform(const irr::core::vector3df& position = irr::core::vector3df(0.0));
    Transform(const Transform& transform);
    virtual ~Transform();

  public:
    irr::core::vector3df position;
};

} // namespace ecs::component

#endif /* !TRANSFORM_HPP_ */
