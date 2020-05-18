/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ComponentManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP

#include "Def.hpp"
#include "ComponentArray.hpp"

#include <string>
#include <memory>

namespace ecs {

class ComponentManager {
  public:
    ComponentManager() = default;
    ~ComponentManager() = default;

  public:
    template<typename T>
    void RegisterComponent()
    {
        std::string componentName = typeid(T).name();

        if (_componentTypes.find(componentName) != _componentTypes.end())
            throw std::runtime_error("Component is already register.");

        _componentTypes.emplace(componentName, _componentType);
        _componentArrays.emplace(componentName, std::make_shared<ComponentArray<T>>());

        _componentType++;
    }

  private:
    template<typename T>
    std::shared_ptr<ComponentArray<T>> GetComponentArray()
    {
        std::string componentName = typeid(T).name();

        if (_componentArrays.find(componentName) == _componentArrays.end())
            throw std::runtime_error("Register the component before using it.");

        return std::static_pointer_cast<ComponentArray<T>>(_componentArrays[componentName]);
    }

  public:
    template<typename T>
    void AddComponent(Entity entity, T component)
    {
        try {
            GetComponentArray<T>()->Insert(entity, component);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    template<typename T>
    void RemoveComponent(Entity entity)
    {
        try {
            GetComponentArray<T>()->Remove(entity);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        try {
            return GetComponentArray<T>()->Get(entity);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

  public:
    void EntityDestroyed(Entity entity)
    {
        for (auto const &pair : _componentArrays) {
            auto const &componentArray = pair.second;

            componentArray->EntityDestroyed(entity);
        }
    }

  private:
    std::unordered_map<std::string, ComponentType> _componentTypes {};
    std::unordered_map<std::string, std::shared_ptr<IComponentArray>> _componentArrays {};
    ComponentType _componentType = 0;
};

}

#endif // OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP
