/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IComponentArray.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP
#define OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP

#include "Def.hpp"

namespace ecs {

class IComponentArray {
  public:
    virtual ~IComponentArray() = default;

  public:
    virtual void EntityDestroyed(Entity entity) = 0;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP
