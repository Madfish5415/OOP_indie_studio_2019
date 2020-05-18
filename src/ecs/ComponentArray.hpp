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

namespace ecs {

template<typename T>
class ComponentArray : public IComponentArray {
  public:
    ComponentArray() = default;
    ~ComponentArray() override = default;

  public:
    void insert(Entity entity, T component)
    {
        if (_entityToIndex.find(entity) != _entityToIndex.end())
            throw std::runtime_error("A component of this type already exists on this entity.");

        _entityToIndex[entity] = _size;
        _indexToEntity[_size] = entity;
        _componentArray[_size] = component;
        _size++;
    }

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

    T& get(Entity entity)
    {
        if (_entityToIndex.find(entity) == _entityToIndex.end())
            throw std::runtime_error("No such component exists for this entity.");

        return _componentArray[_entityToIndex[entity]];
    }

  public:
    void entityDestroyed(Entity entity) override
    {
        if (_entityToIndex.find(entity) != _entityToIndex.end()) {
            remove(entity);
        }
    }

  private:
    std::array<T, MAX_ENTITIES> _componentArray {};
    std::unordered_map<Entity, size_t> _entityToIndex {};
    std::unordered_map<size_t, Entity> _indexToEntity {};
    size_t _size = 0;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_COMPONENTARRAY_HPP
