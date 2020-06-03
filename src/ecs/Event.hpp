/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_EVENT_HPP
#define OOP_INDIE_STUDIO_2019_EVENT_HPP

#include <unordered_map>
#include <utility>

namespace ecs {

class Event {
  public:
    Event() = default;
    virtual ~Event() = default;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_EVENT_HPP
