/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef OOP_INDIE_STUDIO_2019_COMP_PLAYER_HPP
#define OOP_INDIE_STUDIO_2019_COMP_PLAYER_HPP

#include <irrlicht.h>

#include <map>
#include <unordered_map>

namespace ecs::component {

class Player {
  public:
    Player(std::unordered_map<std::string, irr::EKEY_CODE> keys = {{"up", irr::EKEY_CODE::KEY_KEY_Z},
               {"down", irr::EKEY_CODE::KEY_KEY_S}, {"left", irr::EKEY_CODE::KEY_KEY_Q},
               {"right", irr::EKEY_CODE::KEY_KEY_D}, {"bomb", irr::EKEY_CODE::KEY_SPACE}});
    Player(const Player& player);
    ~Player();


  public:
    std::unordered_map<std::string, irr::EKEY_CODE> keys;
    std::string lastKey;
};

} // namespace ecs::component

#endif /* !PLAYER_HPP_ */
