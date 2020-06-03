/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ComponentArray.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_COMPONENTARRAY_HPP
#define OOP_INDIE_STUDIO_2019_COMPONENTARRAY_HPP

#include <array>
#include <unordered_map>

#include "IComponentArray.hpp"

/**
 * @file ComponentArray.hpp
 * @brief ComponentArray Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class ComponentArray
 * @tparam T : Type of the component to be contained
 * @brief An array of components
 */
template<typename T>
class ComponentArray : public IComponentArray {
  public:
    /**
     * @brief Constructor
     * Default constructor of ComponentArray Class.
     */
    ComponentArray() = default;
    /**
     * @brief Constructor
     * Default destructor of ComponentArray Class.
     */
    ~ComponentArray() override = default;

  public:
    /**
     * @brief insert method
     * This method allows to insert a component for an entity in the array.
     * @param entity : The entity related to the component
     * @param component : The entity-related component
     */
    void insert(Entity entity, T component)
    {
        if (_entityToIndex.find(entity) != _entityToIndex.end())
            throw std::runtime_error("A component of this type already exists on this entity.");

        _entityToIndex[entity] = _size;
        _indexToEntity[_size] = entity;
        _componentArray[_size] = component;
        _size++;
    }

    /**
     * @brief remove method
     * This method allows to remove a component from an entity.
     * @param entity : The entity from whom the component is to be removed.
     */
    void remove(Entity entity)
    {
        if (_entityToIndex.find(entity) == _entityToIndex.end())
            throw std::runtime_error("No such component exists for this entity.");

        size_t entIndex = _entityToIndex[entity];

        _componentArray[entIndex] = _componentArray[_size - 1];

        Entity lastEnt = _indexToEntity[_size - 1];

        _entityToIndex[lastEnt] = entIndex;
        _indexToEntity[entIndex] = lastEnt;

        _entityToIndex.erase(entity);
        _indexToEntity.erase(_size - 1);

        _size--;
    }

    /**
     * @brief get method
     * This method makes it possible to recover the component of an entity.
     * @param entity : The entity from which to retrieve the component.
     * @return A reference to the component of the entity.
     */
    T& get(Entity entity)
    {
        if (_entityToIndex.find(entity) == _entityToIndex.end())
            throw std::runtime_error("No such component exists for this entity.");

        return _componentArray[_entityToIndex[entity]];
    }

  public:
    /**
     * @brief entityDestroyed method
     * This method must be called when an entity is destroyed.
     * @param entity : The destroyed entity
     */
    void entityDestroyed(Entity entity) override
    {
        if (_entityToIndex.find(entity) != _entityToIndex.end()) {
            remove(entity);
        }
    }

  private:
    std::array<T, MAX_ENTITIES> _componentArray {}; /**< An array of T component and of MAX_ENTITIES size. */
    std::unordered_map<Entity, size_t> _entityToIndex {}; /** < An unordered map which link entity to index. */
    std::unordered_map<size_t, Entity> _indexToEntity {}; /** < An unordered map which link index to entity. */
    size_t _size = 0; /** < Real length of the array. */
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_COMPONENTARRAY_HPP
