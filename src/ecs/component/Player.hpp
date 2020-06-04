/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <irrlicht.h>

#include <unordered_map>

namespace ecs::component {

class Player {
  public:
    Player(std::unordered_map<std::string, irr::EKEY_CODE> keys = {{"up", irr::EKEY_CODE::KEY_KEY_Z},
               {"down", irr::EKEY_CODE::KEY_KEY_S}, {"left", irr::EKEY_CODE::KEY_KEY_Q},
               {"right", irr::EKEY_CODE::KEY_KEY_D}, {"bomb", irr::EKEY_CODE::KEY_SPACE}},
        size_t id = 1);
    Player(const Player& player);
    ~Player();

  public:
    std::unordered_map<std::string, irr::EKEY_CODE> keys;
    size_t id;
};

} // namespace ecs::component

#endif /* !PLAYER_HPP_ */
