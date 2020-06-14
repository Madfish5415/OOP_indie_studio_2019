/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Countdown
*/

#ifndef INDIESTUDIO_SYSTEM_COUNTDOWN_HPP_
#define INDIESTUDIO_SYSTEM_COUNTDOWN_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Countdown : public System {
  public:
    explicit Countdown(ecs::WorldManager* worldManager);
    ~Countdown() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif /* !COUNTDOWN_HPP_ */
