/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Movement.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MOVEMENT_HPP
#define OOP_INDIE_STUDIO_2019_MOVEMENT_HPP

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Movement : public ecs::System {
  public:
    explicit Movement(WorldManager *worldManager);
    ~Movement() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // OOP_INDIE_STUDIO_2019_MOVEMENT_HPP
