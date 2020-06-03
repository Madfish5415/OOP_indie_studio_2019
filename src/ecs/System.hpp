/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** System.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_SYSTEM_HPP
#define OOP_INDIE_STUDIO_2019_SYSTEM_HPP

#include <set>

#include "ComponentManager.hpp"
#include "Def.hpp"

namespace ecs {
class System {
  public:
    explicit System(ComponentManager *componentManager)
    {
        this->componentManager = componentManager;
    }
    ~System() = default;

  public:
    std::set<Entity> entities {};
    ComponentManager *componentManager;
};
} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEM_HPP
