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

#include "Def.hpp"

namespace ecs {
class EntityManager {
  public:
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
            _availableEntities.push(entity);
        }
    }
    ~EntityManager() = default;

  public:
    Entity CreateEntity()
    {
        if (_entitiesCount >= MAX_ENTITIES)
            throw std::runtime_error("Too many entities exist.");

        Entity entity = _availableEntities.front();
        _availableEntities.pop();
        _entitiesCount++;

        return entity;
    }

    void DestroyEntity(Entity entity)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        _signatures[entity].reset();
        _availableEntities.push(entity);
        _entitiesCount--;
    }

  public:
    void SetSignature(Entity entity, Signature signature)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        _signatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        if (entity >= MAX_ENTITIES)
            throw std::runtime_error("The id of the entity is greater than MAX_ENTITIES.");

        return _signatures[entity];
    }

  private:
    std::queue<Entity> _availableEntities {};
    std::array<Signature, MAX_ENTITIES> _signatures {};
    unsigned int _entitiesCount = 0;
};
} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_ENTITYMANAGER_HPP
