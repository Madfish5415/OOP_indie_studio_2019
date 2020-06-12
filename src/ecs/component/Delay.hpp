/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Delay
*/

#ifndef DELAY_HPP_
#define DELAY_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Delay {
  public:
    Delay(irr::u32 value = 2000);
    Delay(const Delay& delay);
    virtual ~Delay();

  public:
    size_t value;
    irr::u32 lastUpdate;
};

} // namespace ecs::component

#endif /* !DELAY_HPP_ */
