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
        ~Delay();

    public:
      size_t value;
      irr::u32 lastUpdate;
};

}

#endif /* !DELAY_HPP_ */
