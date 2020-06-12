/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../event/Key.hpp"

namespace ecs::system {

class Player : public System {
  public:
    Player(ecs::WorldManager *worldManager);
    ~Player();

  public:
    void receiveKeyEvent(event::Key& key);

  private:
    bool alreadyExist(const irr::core::vector3d<irr::f32>& pos);
};

}

#endif /* !PLAYER_HPP_ */
