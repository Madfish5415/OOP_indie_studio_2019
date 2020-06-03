/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SystemManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP

#include <memory>
#include <unordered_map>

#include "System.hpp"

namespace ecs {

class SystemManager {
  public:
    explicit SystemManager(WorldManager *worldManager)
    {
        _worldManager = worldManager;
    }
    ~SystemManager() = default;

  public:
    template<typename T>
    std::shared_ptr<T> registerSystem()
    {
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) != _systems.end())
            throw std::runtime_error("System is already register.");

        auto system = std::make_shared<T>(_worldManager);

        _systems.emplace(systemName, system);
        return system;
    }

    template<typename T>
    std::shared_ptr<T> getSystem()
    {
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) == _systems.end())
            throw std::runtime_error("Register the system before using it.");

        return std::static_pointer_cast<T>(_systems[systemName]);
    }

    void update()
    {
        for (auto const &pair : _systems) {
            auto const &system = pair.second;
            system->update();
        }
    }

    template<typename T>
    void setSignature(Signature signature)
    {
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) == _systems.end())
            throw std::runtime_error("Register the system before using it.");

        _signatures.emplace(systemName, signature);
    }

  public:
    void entityDestroyed(Entity entity)
    {
        for (auto const &pair : _systems) {
            auto const &system = pair.second;

            system->entities.erase(entity);
        }
    }

  public:
    void entitySignatureChanged(Entity entity, Signature entSignature)
    {
        for (auto const &pair : _systems) {
            auto const &systemName = pair.first;
            auto const &system = pair.second;
            auto const &systemSignature = _signatures[systemName];

            if ((entSignature & systemSignature) == systemSignature) {
                system->entities.emplace(entity);
            } else {
                system->entities.erase(entity);
            }
        }
    }

  private:
    std::unordered_map<std::string, std::shared_ptr<System>> _systems {};
    std::unordered_map<std::string, Signature> _signatures {};
    WorldManager *_worldManager;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP
