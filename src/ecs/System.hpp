/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** System.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_SYSTEM_HPP
#define OOP_INDIE_STUDIO_2019_SYSTEM_HPP

#include <set>

#include "Def.hpp"

namespace ecs {
class System {
  public:
    System() = default;
    ~System() = default;

  public:
    std::set<Entity> entities {};
};
} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEM_HPP
