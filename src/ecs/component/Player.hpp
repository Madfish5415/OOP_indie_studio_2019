/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Player {
  public:
    Player(irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE up, irr::EKEY_CODE down, irr::EKEY_CODE bomb);
    ~Player();

  public:
    irr::EKEY_CODE left;
    irr::EKEY_CODE right;
    irr::EKEY_CODE up;
    irr::EKEY_CODE down;
    irr::EKEY_CODE bomb;
};

} // namespace ecs::component

#endif /* !PLAYER_HPP_ */
