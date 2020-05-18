/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ComponentManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP

#include <memory>
#include <string>

#include "ComponentArray.hpp"
#include "Def.hpp"

namespace ecs {

class ComponentManager {
  public:
    ComponentManager() = default;
    ~ComponentManager() = default;

  public:
    template<typename T>
    void registerComponent()
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
    std::shared_ptr<ComponentArray<T>> getComponentArray()
    {
        std::string componentName = typeid(T).name();

        if (_componentArrays.find(componentName) == _componentArrays.end())
            throw std::runtime_error("Register the component before using it.");

        return std::static_pointer_cast<ComponentArray<T>>(_componentArrays[componentName]);
    }

  public:
    template<typename T>
    ComponentType getComponentType()
    {
        std::string componentName = typeid(T).name();

        if (_componentArrays.find(componentName) == _componentArrays.end())
            throw std::runtime_error("Register the component before using it.");

        return _componentTypes[componentName];
    }

    template<typename T>
    void addComponent(Entity entity, T component)
    {
        try {
            getComponentArray<T>()->insert(entity, component);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    template<typename T>
    void removeComponent(Entity entity)
    {
        try {
            getComponentArray<T>()->remove(entity);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    template<typename T>
    T &getComponent(Entity entity)
    {
        try {
            return getComponentArray<T>()->get(entity);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

  public:
    void entityDestroyed(Entity entity)
    {
        for (auto const &pair : _componentArrays) {
            auto const &componentArray = pair.second;

            componentArray->entityDestroyed(entity);
        }
    }

  private:
    std::unordered_map<std::string, ComponentType> _componentTypes {};
    std::unordered_map<std::string, std::shared_ptr<IComponentArray>> _componentArrays {};
    ComponentType _componentType = 0;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_COMPONENTMANAGER_HPP
