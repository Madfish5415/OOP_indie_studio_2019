/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Universe.cpp
*/
#include "Universe.hpp"

using namespace ecs;

Universe::Universe()
    : _worldManagers(std::unordered_map<std::string, std::unique_ptr<WorldManager>>()),
      _currentWorldManager(""),
      _eventReceiver(EventReceiver(this)),
      _device(createDevice(
          irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, &_eventReceiver))
{
}

Universe::~Universe() = default;

WorldManager* Universe::createWorldManager(const std::string& name)
{
    WorldManager *worldManager = new WorldManager(this);

    _worldManagers.emplace(name, worldManager);
    return (worldManager);
}

bool Universe::hasWorldManager(const std::string& name) const
{
    return (_worldManagers.count(name));
}

WorldManager* Universe::getWorldManager(const std::string& name) const
{
    if (_worldManagers.count(name) == 0)
        return (nullptr);
    if (_worldManagers.at(name) == nullptr)
        return (nullptr);
    return (_worldManagers.at(name).get());
}

WorldManager* Universe::getCurrentWorldManager() const
{
    if (_worldManagers.count(_currentWorldManager) == 0)
        return (nullptr);
    if (_worldManagers.at(_currentWorldManager) == nullptr)
        return (nullptr);
    return _worldManagers.at(_currentWorldManager).get();
}

void Universe::setCurrentWorldManager(const std::string& name)
{
    _currentWorldManager = name;
}

void Universe::deleteWorldManager(const std::string& name)
{
    if (_worldManagers.count(name))
        _worldManagers.erase(name);
}

irr::IrrlichtDevice *Universe::getDevice() const
{
    return (_device);
}