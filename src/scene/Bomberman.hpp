/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Bomberman.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
#define OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP

#include <vector>

#include "../ecs/WorldManager.hpp"
#include "../ecs/component/Player.hpp"

namespace scene {
class Bomberman {
  public:
    Bomberman() = delete;
    ~Bomberman() = delete;

  public:
    static void init(ecs::WorldManager *worldManager, std::vector<ecs::component::Player> players);
    static void reset();
};
}

#endif // OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
