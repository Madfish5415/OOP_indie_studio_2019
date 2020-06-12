/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Timer.hpp
*/

#ifndef INDIESTUDIO_TIMER_COMP_HPP
#define INDIESTUDIO_TIMER_COMP_HPP

#include <irrlicht.h>

namespace ecs::component {

class Timer {
  public:
    Timer(irr::u32 delay = 0);
    Timer(const Timer& timer);
    virtual ~Timer();

  public:
    irr::u32 delay;
    irr::u32 elapsed;
    irr::u32 lastUpdate;
};

} // namespace ecs::component

#endif // INDIESTUDIO_TIMER_COMP_HPP
