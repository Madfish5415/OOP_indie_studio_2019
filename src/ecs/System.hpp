/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** System.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_SYSTEM_HPP
#define OOP_INDIE_STUDIO_2019_SYSTEM_HPP


namespace ecs {
class WorldManager;
}

#include <set>
#include "Def.hpp"

namespace ecs {

class System {
  public:
    explicit System(WorldManager *worldManager)
    {
        this->worldManager = worldManager;
    }
    virtual ~System() = default;

  public:
    virtual void update()
    {
    }

  public:
    std::set<Entity> entities {};
    WorldManager *worldManager;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEM_HPP
