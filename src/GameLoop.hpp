/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** GameLoop.hpp
*/

#ifndef HELLOIRR_GAMELOOP_HPP
#define HELLOIRR_GAMELOOP_HPP

#include <memory>
#include <array>

#include "ecs/WorldManager.hpp"

class GameLoop {
  public:
    GameLoop();
    ~GameLoop();

    void init();
    void run();

  private:
    std::unique_ptr<ecs::WorldManager> _worldManager;
};

#endif // HELLOIRR_GAMELOOP_HPP
