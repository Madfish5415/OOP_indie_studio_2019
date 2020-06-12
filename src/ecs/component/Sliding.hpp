/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sliding
*/

#ifndef INDIESTUDIO_SLIDING_COMP_HPP
#define INDIESTUDIO_SLIDING_COMP_HPP

#include <irrlicht.h>

namespace ecs::component {

class Sliding {
  public:
    Sliding(irr::u32 delay = 1000,
        const irr::core::vector2d<irr::s32>& endPosition = irr::core::vector2d<irr::s32>(0, 0),
        const irr::core::vector2d<irr::s32>& addPosition = irr::core::vector2d<irr::s32>(0, 0));
    Sliding(const Sliding& sliding);
    virtual ~Sliding();

  public:
    irr::u32 delay;
    irr::u32 lastUpdate;
    irr::core::vector2d<irr::s32> endPosition;
    irr::core::vector2d<irr::s32> addPosition;
};

} // namespace ecs::component

#endif // INDIESTUDIO_SLIDING_COMP_HPP
