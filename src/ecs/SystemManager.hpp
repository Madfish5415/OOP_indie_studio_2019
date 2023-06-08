/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SystemManager.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP
#define OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP

#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "System.hpp"

/**
 * @file SystemManager.hpp
 * @brief SystemManager Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class SystemManager
 * @brief Class that manage systems.
 */
class SystemManager {
  public:
    /**
     * @brief Constructor
     * Constructor of SystemManager.
     * @param worldManager : Manager of our World.
     */
    explicit SystemManager(WorldManager *worldManager)
    {
        _worldManager = worldManager;
    }
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~SystemManager() = default;

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
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) != _systems.end())
            throw std::runtime_error("System is already register.");

        auto system = std::make_shared<T>(_worldManager);

        _systems.emplace(systemName, system);
        _priority.push_back(systemName);
        return system;
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
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) == _systems.end())
            throw std::runtime_error("Register the system before using it.");

        return std::static_pointer_cast<T>(_systems[systemName]);
    }

    /**
     * @brief updateSystem method
     * This method calls the update method of each system of the ecs.
     */
    void update()
    {
        for (auto const &name : _priority) {
            auto const &system = _systems[name];
            system->update();
        }
    }

    /**
     * @brief setSignature method
     * This method makes it possible to define the signature of an existing system.
     * @tparam T : Type of the system to be retrieved.
     * @param signature : The signature to be defined in the system.
     */
    template<typename T>
    void setSignature(Signature signature)
    {
        std::string systemName = typeid(T).name();

        if (_systems.find(systemName) == _systems.end())
            throw std::runtime_error("Register the system before using it.");

        _signatures.emplace(systemName, signature);
    }

  public:
    /**
     * @brief entityDestroyed method
     * This method must be called when an entity is destroyed.
     * @param entity : The destroyed entity
     */
    void entityDestroyed(Entity entity)
    {
        for (auto const &pair : _systems) {
            auto const &system = pair.second;

            system->entities.erase(entity);
        }
    }

  public:
    /**
     * @brief entitySignatureChanged method
     * This method must be called when an entity's signature changed.
     * @param entity : The entity that changed its signature.
     * @param entSignature : The new signature of the entity.
     */
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
    std::unordered_map<std::string, std::shared_ptr<System>> _systems {}; /** < Unordered map of systems. */
    std::vector<std::string> _priority {}; /** < Keep registering order in memory. */
    std::unordered_map<std::string, Signature> _signatures {}; /** < Unordered map of signatures. */
    WorldManager *_worldManager; /** < Manager of our world. */
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_SYSTEMMANAGER_HPP