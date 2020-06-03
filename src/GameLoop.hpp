/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** GameLoop.hpp
*/

#ifndef HELLOIRR_GAMELOOP_HPP
#define HELLOIRR_GAMELOOP_HPP

#include <array>
#include <memory>

#include "ecs/WorldManager.hpp"

/**
 * @file GameLoop.hpp
 * @brief GameLoop Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @class GameLoop
 * @brief The class comes to initialize and manage all the elements of the world.
 */
class GameLoop {
  public:
    /**
     * @brief Constructor
     * Constructor of GameLoop Class.
     */
    GameLoop();
    /**
     * @brief Destructor
     * Destructor of GameLoop Class.
     */
    ~GameLoop();

  public:
    /**
     * @brief Init game
     * Method used to initialize our game.
     */
    void init();
    /**
     * @brief Run game
     * Method used to run our game.
     */
    void run();

  private:
    std::unique_ptr<ecs::WorldManager> _worldManager; /**< Manager of our world */
};

#endif // HELLOIRR_GAMELOOP_HPP
