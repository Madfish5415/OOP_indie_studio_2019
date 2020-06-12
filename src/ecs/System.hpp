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

/**
 * @file System.hpp
 * @brief System Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class System
 * @brief Default system class
 */
class System {
  public:
    /**
     * @brief Constructor
     * Constructor of System Class.
     * @param worldManager : Manager of our World.
     */
    explicit System(WorldManager *worldManager)
    {
        this->worldManager = worldManager;
    }
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    virtual ~System() = default;

  public:
    /**
     * @brief update method
     * Method that update the entity. She's called every loop turn.
     */
    virtual void update()
    {
    }

  public:
    std::set<Entity> entities {}; /** < Entity set who match with the system signature.*/
    WorldManager *worldManager; /** < Manager of our World.*/
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEM_HPP