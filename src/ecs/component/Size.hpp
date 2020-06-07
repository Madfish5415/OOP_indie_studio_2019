/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Size
*/

#ifndef SIZE_HPP_
#define SIZE_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Size {
  public:
    Size(const irr::core::vector3df &size = irr::core::vector3df(0.0));
    Size(const Size &size);
    ~Size();

  public:
    irr::core::vector3df size;
};

} // namespace ecs::component

#endif /* !SIZE_HPP_ */
