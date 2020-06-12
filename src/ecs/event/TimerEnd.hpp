/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerEnd
*/

#ifndef INDIESTUDIO_TIMEREND_HPP
#define INDIESTUDIO_TIMEREND_HPP

#include "../Event.hpp"

namespace ecs::event {

class TimerEnd : public ecs::Event {
  public:
    TimerEnd();
    ~TimerEnd() override;
};

} // namespace ecs::event

#endif // INDIESTUDIO_TIMEREND_HPP
