/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef BOMBTIMER_HPP_
#define BOMBTIMER_HPP_

#include <irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>
#include <irrlicht/irrTypes.h>

namespace ecs::component {

class BombTimer {
  public:
    BombTimer(const irr::u32 &duration = 0, irr::IrrlichtDevice *dev = nullptr);
    BombTimer(const BombTimer &bombTimer);
    ~BombTimer();

  public:
    irr::u32 timerStart;
    irr::u32 duration;
};

} // namespace ecs::component

#endif /* !BOMBTIMER_HPP_ */
