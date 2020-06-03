/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Motion.hpp
*/

#ifndef INDIESTUDIO_MOTION_HPP
#define INDIESTUDIO_MOTION_HPP

#include "../System.hpp"

/**
 * @file Motion.hpp
 * @brief Motion Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::system
 */
namespace ecs::system {

/**
 * @class Motion
 * System that will update the movement of the entity.
 */
class Motion : public System {
  public:
    /**
     * @brief Constructor
     * Constructor of Motion Class.
     * @param worldManager : Manager of our World.
     */
    explicit Motion(ecs::WorldManager *worldManager);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Motion() override;

  public:
    /**
     * @brief update method
     * Method that update the entity. She's called every loop turn.
     */
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_MOTION_HPP
