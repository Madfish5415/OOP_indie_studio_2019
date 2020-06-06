/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Universe
*/

#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include <irrlicht.h>

#include <unordered_map>

#include "../EventReceiver.hpp"
#include "WorldManager.hpp"

/**
 * @file Universe.hpp
 * @brief Universe Class
 * @author Lucas.M
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class Universe
 * @brief The universe manages every world in our program.
 */
class Universe {
  public:
    /**
     * @brief Constructor
     * Initialize unordered_map to empty.
     * Set current to empty.
     * Initialize eventReceiver.
     * Initialize device.
     */
    Universe();
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Universe();

  public:
    /**
     * @brief createWorldManager method
     * This method creates a WorldManager and returns it.
     * @param name : Name of the WorldManager.
     * @return The WorldManager that was created.
     */
    WorldManager *createWorldManager(const std::string &name);
    /**
     * @brief createWorldManager method
     * This method checks whether a WorldManager exists for the given name.
     * @param name : Name of the WorldManager.
     * @return True if the WorldManager exists and False otherwise.
     */
    bool hasWorldManager(const std::string &name) const;
    /**
     * @brief getWorldManager method
     * This method returns the WorldManager associated with the given name.
     * @param name : Name of the WorldManager.
     * @return The WorldManager if it exists and nullptr otherwise.
     */
    WorldManager *getWorldManager(const std::string &name) const;
    /**
     * @brief getWorldManager method
     * This method returns the WorldManager that is currently in use.
     * @return The WorldManager if it exists and nullptr otherwise.
     */
    WorldManager *getCurrentWorldManager() const;
    /**
     * @brief setCurrentWorldManager method
     * This method defines the WorldManager to use.
     */
    void setCurrentWorldManager(const std::string &name);
    /**
     * @brief deleteWorldManager method
     * This method defines the WorldManager to use.
     * @param name : Name of the WorldManager.
     */
    void deleteWorldManager(const std::string &name);
    /**
     * @brief getDevice method
     * This method return the Irrlicth device.
     * @return The Irrlicht device.
     */
    irr::IrrlichtDevice *getDevice() const;

  private:
    std::unordered_map<std::string, std::unique_ptr<WorldManager>> _worldManagers {}; /** < List of all our WorldManager sorted by name */
    std::string _currentWorldManager; /** < Name of the current WorldManager */
    EventReceiver _eventReceiver; /** < The EventReceiver Class */
    irr::IrrlichtDevice *_device; /** < The Irrlicht device */
};
} // namespace ecs

#endif /* !UNIVERSE_HPP_ */
