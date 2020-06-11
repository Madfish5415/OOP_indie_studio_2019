/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Shrink
*/

#ifndef INDIESTUDIO_SHRINK_HPP
#define INDIESTUDIO_SHRINK_HPP

#include <array>
#include <irrlicht.h>

#include "../System.hpp"
#include "../event/TimerEnd.hpp"

namespace ecs::system {

class Shrink : public System {
  public:
    Shrink(WorldManager* worldManager);
    ~Shrink() override;

  public:
    void update() override;
    void startShrinking(ecs::event::TimerEnd& event);

  private:
    bool shrink;
    std::array<int, 2> shrinkMaxSize;
    std::array<int, 2> shrinkSize;
    std::array<std::string, 2> shrinkDirection;
    std::array<irr::core::vector3d<irr::f32>, 2> shrinkPosition;
    irr::u32 delay;
    irr::u32 lastUpdate;
    irr::u32 time;
};

} // namespace ecs::system

#endif // INDIESTUDIO_SHRINK_HPP
