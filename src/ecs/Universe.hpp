/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Universe
*/

#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include <unordered_map>
#include <irrlicht.h>

#include "WorldManager.hpp"
#include "EventReceiver.hpp"

namespace ecs {

class Universe {
    public:
        Universe() : _worldManagers(std::unordered_map<std::string, std::unique_ptr<WorldManager>>()),
                     _currentWorldManager(nullptr),
                     _eventReceiver(EventReceiver(this)),
                     _device(createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, &_eventReceiver))
        {
        }

        ~Universe();

        WorldManager *createWorldManager(const std::string &name)
        {
            _worldManagers.emplace(name, new WorldManager());
        }

        bool hasWorldManager(const std::string &name) const
        {
            return (_worldManagers.count(name));
        }

        WorldManager *getWorldManager(const std::string &name) const
        {
            if (_worldManagers.count(name) == 0) {
                return (nullptr);
            }
            return (_worldManagers.at(name).get());
        }

        WorldManager *getCurrentWorldManager() const
        {
            if (_worldManagers.count(_currentWorldManager) == 0)
                return (nullptr);
            if (_worldManagers.at(_currentWorldManager) == nullptr)
                return (nullptr);
            return _worldManagers.at(_currentWorldManager).get();
        }

        void setCurrentWorldManager(const std::string &name)
        {
            _currentWorldManager = name;
        }

        void deleteWorldManager(const std::string &name)
        {
            if (_worldManagers.count(name) != 0) {
                _worldManagers.erase(name);
            }
        }

    private:
        std::unordered_map<std::string, std::unique_ptr<WorldManager>> _worldManagers;
        std::string _currentWorldManager;
        EventReceiver _eventReceiver;
        irr::IrrlichtDevice *_device;
};
}

#endif /* !UNIVERSE_HPP_ */
