/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EntityManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_ENTITYMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_ENTITYMANAGER_HPP

#include <array>
#include <queue>

#ifdef _WIN32
#include <stdexcept>
#endif

#include "Def.hpp"

/**
 * @file EntityManager.hpp
 * @brief EntityManager Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class EntityManager
 * @brief Class that manages entities.
 */
class EntityManager {
  public:
    /**
     * @brief Constructor
     * Constructor of EntityManager
     */
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
            _availableEntities.push(entity);
        }
    }
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~EntityManager() = default;

  public:
    /**
     * @brief createEntity method
     * This method creates an entity and returns it.
     * @return The entity that was created.
     */
    Entity createEntity()
    {
        if (_entitiesCount >= MAX_ENTITIES)
            throw std::runtime_error("Too many entities exist.");

        Entity entity = _availableEntities.front();
        _availableEntities.pop();
        _entitiesCount++;

        return entity;
    }

    /**
     * @brief destroyEntity method
     * This method destroys an entity.
     * @param entity : The entity to be destroyed.
     */
    void destroyEntity(Entity entity)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        _signatures[entity].reset();
        _availableEntities.push(entity);
        _entitiesCount--;
    }

  public:
    /**
     * @brief setSystemSignature method
     * This method makes it possible to define the signature of an existing entity.
     * @param entity : Entity to be retrieved.
     * @param signature : The signature to be defined to the entity.
     */
    void setSignature(Entity entity, Signature signature)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        _signatures[entity] = signature;
    }

    /**
     * @brief getSignature method
     * This method will return a reference to the signature defined to the entity past in parameter.
     * @param entity : The entity you want to retrieve the signature.
     * @return A reference to the signature defined to the entity past in parameter.
     */
    Signature& getSignature(Entity entity)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        return _signatures[entity];
    }

  private:
    std::queue<Entity> _availableEntities {}; /** < Queue of available entities. */
    std::array<Signature, MAX_ENTITIES> _signatures {}; /** < Array of singatures*/
    unsigned int _entitiesCount = 0; /** < Entity counter*/
};
} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_ENTITYMANAGER_HPP