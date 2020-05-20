/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WorldManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP

#include <memory>

#include "ecs/ComponentManager.hpp"
#include "ecs/EntityManager.hpp"
#include "ecs/SystemManager.hpp"
#include "ecs/EventManager.hpp"

namespace ecs {

class WorldManager {
  public:
    WorldManager()
    {
        _entityManager = std::make_unique<EntityManager>();
        _componentManager = std::make_unique<ComponentManager>();
        _systemManager = std::make_unique<SystemManager>();
        _eventManager = std::make_unique<EventManager>();
    }
    ~WorldManager() = default;

  public:
    Entity createEntity()
    {
        return _entityManager->createEntity();
    }

    void destroyEntity(Entity entity)
    {
        _entityManager->destroyEntity(entity);

        _componentManager->entityDestroyed(entity);

        _systemManager->entityDestroyed(entity);
    }

  public:
    template<typename T>
    void registerComponent()
    {
        _componentManager->registerComponent<T>();
    }

    template<typename T>
    void addComponent(Entity entity, T component)
    {
        _componentManager->addComponent<T>(entity, component);

        auto sig = _entityManager->getSignature(entity);
        sig.set(_componentManager->getComponentType<T>(), true);

        _systemManager->entitySignatureChanged(entity, sig);
    }

    template<typename T>
    void removeComponent(Entity entity)
    {
        _componentManager->removeComponent<T>(entity);

        auto sig = _entityManager->getSignature(entity);
        sig.set(_componentManager->getComponentType<T>(), false);

        _systemManager->entitySignatureChanged(entity, sig);
    }

    template<typename T>
    T& getComponent(Entity entity)
    {
        return _componentManager->getComponent<T>(entity);
    }

    template<typename T>
    ComponentType getComponentType()
    {
        return _componentManager->getComponentType<T>();
    }

  public:
    template<typename T>
    std::shared_ptr<T> registerSystem()
    {
        return _systemManager->registerSystem<T>();
    }

    template<typename T>
    void setSystemSignature(Signature signature)
    {
        _systemManager->setSignature<T>(signature);
    }

  public:
    template<typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback)
    {
        _eventManager->subscribe<T, E>(subscriber, callback);
    }

    void unsubscribe()
    {
        _eventManager->unsubscribe();
    }

    template<typename E>
    void publish(E& event)
    {
        _eventManager->publish<E>(event);
    }

  private:
    std::unique_ptr<EntityManager> _entityManager;
    std::unique_ptr<ComponentManager> _componentManager;
    std::unique_ptr<SystemManager> _systemManager;
    std::unique_ptr<EventManager> _eventManager;
};

}

#endif // OOP_INDIE_STUDIO_2019_WORLDMANAGER_HPP
