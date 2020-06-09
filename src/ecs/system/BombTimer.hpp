/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef INDIESTUDIO_BOMBTIMER_HPP
#define INDIESTUDIO_BOMBTIMER_HPP

#include <irrlicht.h>

#include "../System.hpp"

namespace ecs::system {

class BombTimer : public System {
  public:
    BombTimer(WorldManager *worldManager);
    ~BombTimer() override;

  public:
    void update() override;

  private:
    irr::u32 time;
};

}

#endif // INDIESTUDIO_BOMBTIMER_HPP
