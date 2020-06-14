/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef INDIESTUDIO_BOMBTIMER_HPP
#define INDIESTUDIO_BOMBTIMER_HPP

#include <irrlicht.h>

#include <vector>

#include "../System.hpp"

namespace ecs::system {

class BombTimer : public System {
  public:
    explicit BombTimer(WorldManager* worldManager);
    ~BombTimer() override;

  public:
    void update() override;
    static void explode(ecs::WorldManager* worldManager, const ecs::Entity& entity);

  private:
    irr::u32 time;
};

} // namespace ecs::system

#endif // INDIESTUDIO_BOMBTIMER_HPP
