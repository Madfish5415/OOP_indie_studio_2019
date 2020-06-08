/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerRender.hpp
*/

#ifndef INDIESTUDIO_TIMERRENDER_HPP
#define INDIESTUDIO_TIMERRENDER_HPP

#include "../System.hpp"

namespace ecs::system {

class TimerRender : public System {
  public:
    TimerRender(WorldManager *worldManager);
    ~TimerRender() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_TIMERRENDER_HPP
