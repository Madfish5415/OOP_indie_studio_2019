/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include <irrlicht.h>

class Transform {
  public:
    explicit Transform(const irr::core::vector3df &position);
    ~Transform();

  public:
    irr::core::vector3df position;
};

#endif /* !TRANSFORM_HPP_ */
