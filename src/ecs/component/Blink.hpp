/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Blink.hpp
*/

#ifndef INDIESTUDIO_BLINK_COMP_HPP
#define INDIESTUDIO_BLINK_COMP_HPP

#include <irrlicht.h>

namespace ecs::component {

class Blink {
  public:
    Blink(irr::u32 millisecond = 2000);
    ~Blink();

  public:
    size_t millisecond;
    irr::u32 lastUpdate;
};

} // namespace ecs::component

#endif // INDIESTUDIO_BLINK_COMP_HPP
