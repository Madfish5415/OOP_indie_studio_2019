/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WorldManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP

namespace ecs {
    class Universe;
}

#include <memory>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "EventManager.hpp"
#include "SystemManager.hpp"

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
 * @class WorldManager
 * @brief Manager who manages all the other managers of the ecs.
 */
class WorldManager {
  public:
    /**
     * @brief Constructor
     * Initializes the four managers and the universe
     */
    WorldManager(Universe *universe)
    {
        _entityManager = std::make_unique<EntityManager>();
        _componentManager = std::make_unique<ComponentManager>();
        _systemManager = std::make_unique<SystemManager>(this);
        _eventManager = std::make_unique<EventManager>();
        _universe = universe;
    }
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~WorldManager() = default;

  public:
    /**
     * @brief createEntity method
     * This method creates an entity and returns it.
     * @return The entity that was created.
     */
    Entity createEntity()
    {
        return _entityManager->createEntity();
    }

    /**
     * @brief destroyEntity method
     * This method destroys an entity and informs other managers of the change.
     * @param entity : The entity to be destroyed.
     */
    void destroyEntity(Entity entity)
    {
        _entityManager->destroyEntity(entity);

        _componentManager->entityDestroyed(entity);

        _systemManager->entityDestroyed(entity);
    }

  private:
    /**
     * @brief createSignature method
     * Allow to generate a signature.
     * @tparam T : The first component.
     * @tparam TArgs : The others components.
     * @return A signature of the components.
     */
    template<typename T = void, typename... TArgs>
    Signature createSignature()
    {
        Signature has;

        if (typeid(T) != typeid(void))
            has.set(_componentManager->getComponentType<T>());

        if (sizeof...(TArgs))
            has |= this->createSignature<TArgs...>();

        return has;
    }

  public:
    /**
     * @brief getEntities method
     * This method return a list of entity based on the components passed in parameters.
     * @tparam TArgs : List of component you needs.
     * @return List of entity who have the list of components.
     */
    template<typename... TArgs>
    std::vector<ecs::Entity> getEntities()
    {
        std::vector<ecs::Entity> entities;
        auto allEntities = _entityManager->getEntities();

        Signature sig = createSignature<TArgs...>();

        for (const auto& entity : allEntities) {
            const auto& signature = _entityManager->getSignature(entity);
            if ((signature & sig) == sig)
                entities.push_back(entity);
        }
        return (entities);
    }

  public:
    /**
     * @brief registerComponent method
     * Register a component so that it is known by the ecs.
     * @tparam T : Type of the component to be registered.
     */
    template<typename T>
    void registerComponent()
    {
        _componentManager->registerComponent<T>();
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
        _componentManager->addComponent<T>(entity, component);

        auto& sig = _entityManager->getSignature(entity);
        sig.set(_componentManager->getComponentType<T>(), true);

        _systemManager->entitySignatureChanged(entity, sig);
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
        _componentManager->removeComponent<T>(entity);

        auto& sig = _entityManager->getSignature(entity);
        sig.set(_componentManager->getComponentType<T>(), false);

        _systemManager->entitySignatureChanged(entity, sig);
    }

    /**
     * @brief getComponent method
     * This method makes it possible to retrieve a component that has previously been added to an entity.
     * @tparam T : Type of the component to be retrieved.
     * @param entity : The entity to which the component is to be retrieved.
     * @return A reference on the requested component.
     */
    template<typename T>
    T& getComponent(Entity entity)
    {
        return _componentManager->getComponent<T>(entity);
    }

    /**
     * @brief getComponentType method
     * This method makes it possible to recover a unique identifier of a component of the ecs.
     * @tparam T : Type of the component to be retrieved.
     * @return A string that represents the signature of the component.
     */
    template<typename T>
    ComponentType getComponentType()
    {
        return _componentManager->getComponentType<T>();
    }

  public:
    /**
     * @brief registerSystem method
     * This method makes it possible to register a system so that it is known by the ecs.
     * This method also creates the requested system and returns it.
     * @tparam T : Type of the system to be registered.
     * @return The requested system.
     */
    template<typename T>
    std::shared_ptr<T> registerSystem()
    {
        return _systemManager->registerSystem<T>();
    }

    /**
     * @brief updateSystem method
     * This method calls the update method of each system of the ecs.
     */
    void updateSystem()
    {
        _systemManager->update();
    }

    /**
     * @brief getSystem method
     * This method makes it possible to recover a system according to its type.
     * @tparam T : Type of the system to be retrieved.
     * @return The requested system.
     */
    template<typename T>
    std::shared_ptr<T> getSystem()
    {
        return _systemManager->getSystem<T>();
    }

    /**
     * @brief setSystemSignature method
     * This method makes it possible to define the signature of an existing system.
     * @tparam T : Type of the system to be retrieved.
     * @param signature : The signature to be defined in the system.
     */
    template<typename T>
    void setSystemSignature(Signature signature)
    {
        _systemManager->setSignature<T>(signature);
    }

  public:
    /**
     * @brief subscribe method
     * This method allows a class to subscribe one of its methods to a specific event.
     * @tparam T : The Class.
     * @tparam E : Type of the Event.
     * @param subscriber : Reference on the subscribing class.
     * @param callback : Method of the subscribing class.
     */
    template<typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback)
    {
        _eventManager->subscribe<T, E>(subscriber, callback);
    }

    /**
     * @brief unsubscribe method
     * This method allows to unsubscribe all previously subscribed classes.
     */
    void unsubscribe()
    {
        _eventManager->unsubscribe();
    }

    /**
     * @brief publish method
     * This method allows to transmit an event to all previously subscribed methods.
     * @tparam E : The event type.
     * @param event : The event to be transmitted.
     */
    template<typename E>
    void publish(E& event)
    {
        _eventManager->publish<E>(event);
    }

    /**
     * @brief getUniverse method
     * This method get the universe of the world manager.
     * @return The universe.
     */
    Universe *getUniverse() const
    {
        return _universe;
    }

  private:
    std::unique_ptr<EntityManager> _entityManager; /** < The entity manager. */
    std::unique_ptr<ComponentManager> _componentManager; /** < The component manager. */
    std::unique_ptr<SystemManager> _systemManager; /** < The system manager. */
    std::unique_ptr<EventManager> _eventManager; /** < The event manager. */
    Universe *_universe; /** < The universe of the world manager. */
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP