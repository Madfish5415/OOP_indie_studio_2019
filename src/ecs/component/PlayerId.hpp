/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushButton.cpp
*/

#ifndef INDIESTUDIO_PLAYERID_HPP
#define INDIESTUDIO_PLAYERID_HPP

#include <cstddef>

namespace ecs::component {

class PlayerId {
  public:
    PlayerId(size_t id = 0);
    PlayerId(const PlayerId& playerId);
    virtual ~PlayerId();

  public:
    size_t id;
};

} // namespace ecs::component

#endif // INDIESTUDIO_PLAYERID_HPP
