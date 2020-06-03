/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player.hpp
*/

#ifndef INDIESTUDIO_PLAYER_HPP
#define INDIESTUDIO_PLAYER_HPP

#include "../System.hpp"
#include "../event/Input.hpp"

namespace ecs::system {

class Player : public ecs::System {
  public:
    explicit Player(ecs::WorldManager *worldManager);
    ~Player() override;

  public:
    void receiveInput(ecs::event::Input& event);

  public:
    void update() override;
};

}

#endif // INDIESTUDIO_PLAYER_HPP
