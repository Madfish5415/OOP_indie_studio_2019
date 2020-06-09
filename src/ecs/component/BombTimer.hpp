/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef BOMBTIMER_HPP_
#define BOMBTIMER_HPP_

#include <irrlicht.h>

namespace ecs::component {

class BombTimer {
  public:
    BombTimer(irr::u32 delay = 0);
    BombTimer(const BombTimer &bombTimer);
    ~BombTimer();

  public:
    irr::u32 delay;
    irr::u32 elapsed;
    irr::u32 lastUpdate;
};

} // namespace ecs::component

#endif /* !BOMBTIMER_HPP_ */
