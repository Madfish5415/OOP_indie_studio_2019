/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sliding
*/

#ifndef INDIESTUDIO_SLIDING_HPP
#define INDIESTUDIO_SLIDING_HPP

#include <irrlicht.h>

#include "../System.hpp"

namespace ecs::system {

class Sliding : public System {
  public:
    Sliding(WorldManager *worldManager);
    ~Sliding() override;

  public:
    void update() override;

  public:
    irr::u32 time;
  private:
    irr::u32 _then;
};

} // namespace ecs::system

#endif // INDIESTUDIO_SLIDING_HPP
