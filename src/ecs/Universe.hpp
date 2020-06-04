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

namespace ecs {

class Universe {
  public:
    Universe();
    ~Universe();

  public:
    WorldManager *createWorldManager(const std::string &name);
    bool hasWorldManager(const std::string &name) const;
    WorldManager *getWorldManager(const std::string &name) const;
    WorldManager *getCurrentWorldManager() const;
    void setCurrentWorldManager(const std::string &name);
    void deleteWorldManager(const std::string &name);

  private:
    std::unordered_map<std::string, std::unique_ptr<WorldManager>> _worldManagers;
    std::string _currentWorldManager;
    EventReceiver _eventReceiver;
    irr::IrrlichtDevice *_device;
};
} // namespace ecs

#endif /* !UNIVERSE_HPP_ */
