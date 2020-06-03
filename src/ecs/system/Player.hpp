/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player.hpp
*/

#ifndef INDIESTUDIO_PLAYER_HPP
#define INDIESTUDIO_PLAYER_HPP

#include "../System.hpp"
#include "../event/Input.hpp"

/**
 * @file Player.hpp
 * @brief Player Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::system
 */
namespace ecs::system {

/**
 * @class Player
 * @brief System that get user entries and handles them.
 */
class Player : public ecs::System {
  public:
    /**
     * @brief Constructor
     * Constructor of Player Class.
     * @param worldManager : Manager of our World.
     */
    explicit Player(ecs::WorldManager *worldManager);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Player() override;

  public:
    /**
     * @brief receiveInput method
     * Method that get user entries and handle them.
     * @param event : Input event.
     */
    void receiveInput(ecs::event::Input& event);

  public:
    /**
     * @brief update method
     * Method that update the entity. She's called every loop turn.
     */
    void update() override;
};

}

#endif // INDIESTUDIO_PLAYER_HPP
