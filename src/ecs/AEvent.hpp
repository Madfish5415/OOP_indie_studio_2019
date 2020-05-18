/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_AEVENT_HPP
#define OOP_INDIE_STUDIO_2019_AEVENT_HPP

#include <unordered_map>
#include <utility>

namespace ecs {
class AEvent {
  public:
    AEvent() = delete;
    virtual ~AEvent() = default;
};
} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_AEVENT_HPP
