/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.hpp
*/

#ifndef INDIESTUDIO_RENDER_HPP
#define INDIESTUDIO_RENDER_HPP

#include "../System.hpp"

/**
 * @file Render.hpp
 * @brief Render Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::system
 */
namespace ecs::system {

/**
 * @class Render
 * @brief System that update and display entity.
 */
class Render : public System {
  public:
    /**
     * @brief Constructor
     * Constructor of Render Class.
     * @param worldManager : Manager of our World.
     */
    explicit Render(WorldManager *worldManager);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Render() override;

  public:
    /**
     * @brief update method
     * Method that update the entity. She's called every loop turn.
     */
    void update() override;
};

}

#endif // INDIESTUDIO_RENDER_HPP
