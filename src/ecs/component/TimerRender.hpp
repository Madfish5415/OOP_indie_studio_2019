/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerRender.hpp
*/

#ifndef INDIESTUDIO_TIMERRENDER_COMP_HPP
#define INDIESTUDIO_TIMERRENDER_COMP_HPP

#include "../Def.hpp"

namespace ecs::component {

class TimerRender {
  public:
    TimerRender(Entity owner = 0, size_t position = 0);
    TimerRender(const TimerRender& timerRender);
    virtual ~TimerRender();

  public:
    ecs::Entity owner;
    size_t position;
};

} // namespace ecs::component

#endif // INDIESTUDIO_TIMERRENDER_COMP_HPP
