/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PlayerIndex.hpp
*/

#ifndef INDIESTUDIO_PLAYERINDEX_HPP
#define INDIESTUDIO_PLAYERINDEX_HPP

namespace ecs::component {

class PlayerIndex {
  public:
    PlayerIndex(int idx = 0);
    PlayerIndex(const PlayerIndex& playerIndex);
    virtual ~PlayerIndex();

  public:
    int idx;
};

} // namespace ecs::component

#endif // INDIESTUDIO_PLAYERINDEX_HPP
