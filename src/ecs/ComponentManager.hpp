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

/**
 * @file WorldManager.hpp
 * @brief WorldManager Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class ComponentManager
 * @brief Class that manages components.
 */
class ComponentManager {
  public:
    /**
     * @brief Constructor
     * Default constructor of ComponentManager Class.
     */
    ComponentManager() = default;
    /**
     * @brief Destructor
     * Default destructor of ComponentManager Class.
     */
    ~ComponentManager() = default;

  public:
    /**
     * @brief registerComponent method
     * Register a component so that it is known by the ecs.
     * @tparam T : Type of the component to be registered.
     */
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
    /**
     * @brief getComponentArray method
     * This method makes it possible to retrieve a ComponentArray depending on the type of component.
     * @tparam T : The type of the component
     * @return A shared pointer on a ComponentArray of type T
     */
    template<typename T>
    std::shared_ptr<ComponentArray<T>> getComponentArray()
    {
        std::string componentName = typeid(T).name();

        if (_componentArrays.find(componentName) == _componentArrays.end())
            throw std::runtime_error("Register the component before using it.");

        return std::static_pointer_cast<ComponentArray<T>>(_componentArrays[componentName]);
    }

  public:
    /**
     * @brief getComponentType method
     * This method makes it possible to recover a unique identifier of a component of the ecs.
     * @tparam T : Type of the component to be retrieved.
     * @return A string that represents the signature of the component.
     */
    template<typename T>
    ComponentType getComponentType()
    {
        std::string componentName = typeid(T).name();

        if (_componentArrays.find(componentName) == _componentArrays.end())
            throw std::runtime_error("Register the component before using it.");

        return _componentTypes[componentName];
    }

    /**
     * @brief addComponent method
     * This method makes it possible to add a previously registered component to an already existing entity.
     * This method also modifies the signature of the entity so that it is taken into account by the systems.
     * @tparam T : Type of the component to be added.
     * @param entity : The entity to which the component is to be added.
     * @param component : The component that will be added to the entity.
     */
    template<typename T>
    void addComponent(Entity entity, T component)
    {
        try {
            getComponentArray<T>()->insert(entity, component);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    /**
     * @brief removeComponent method
     * This method makes it possible to remove a previously added component of an already existing entity.
     * This method also modifies the signature of the entity so that it is taken into account by the systems.
     * @tparam T : Type of the component to be removed.
     * @param entity : The entity to which the component is to be removed.
     */
    template<typename T>
    void removeComponent(Entity entity)
    {
        try {
            getComponentArray<T>()->remove(entity);
        } catch (std::runtime_error &e) {
            throw e;
        }
    }

    /**
     * @brief getComponent method
     * This method makes it possible to retrieve a component that has previously been added to an entity.
     * @tparam T : Type of the component to be retrieved.
     * @param entity : The entity to which the component is to be retrieved.
     * @return A reference on the requested component.
     */
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
    /**
     * @brief entityDestroyed method
     * This method must be called when an entity is destroyed.
     * @param entity : The destroyed entity
     */
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
