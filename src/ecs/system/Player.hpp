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
    explicit Player(ecs::WorldManager* worldManager);
    ~Player() override;

  public:
    void receiveKeyEvent(event::Key& key);

  private:
    bool alreadyExist(const irr::core::vector3d<irr::f32>& pos);
};

} // namespace ecs::system

#endif /* !PLAYER_HPP_ */
