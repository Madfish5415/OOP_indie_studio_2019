/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Timer.hpp
*/

#ifndef INDIESTUDIO_TIMER_HPP
#define INDIESTUDIO_TIMER_HPP

#include <irrlicht.h>

#include "../System.hpp"

namespace ecs::system {

class Timer : public System {
  public:
    Timer(WorldManager *worldManager);
    ~Timer() override;

  public:
    void update() override;

  private:
    irr::u32 time;
};

} // namespace ecs::system

#endif // INDIESTUDIO_TIMER_HPP
