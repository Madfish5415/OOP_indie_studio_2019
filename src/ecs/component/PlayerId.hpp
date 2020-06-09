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
    ~PlayerId();

  public:
    size_t id;
};

}

#endif // INDIESTUDIO_PLAYERID_HPP
