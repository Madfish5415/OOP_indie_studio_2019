/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Spinner.hpp
*/

#ifndef INDIESTUDIO_SPINNER_COMP_HPP
#define INDIESTUDIO_SPINNER_COMP_HPP

#include <irrlicht.h>

namespace ecs::component {

class Spinner {
  public:
    Spinner(
        const irr::core::vector3d<irr::f32>& rotation = irr::core::vector3d<irr::f32>(0, 0, 0), irr::u32 delay = 2000);
    Spinner(const Spinner& spinner);
    virtual ~Spinner();

  public:
    irr::core::vector3d<irr::f32> rotation;
    irr::u32 delay;
    irr::u32 lastUpdate;
};

} // namespace ecs::component

#endif // INDIESTUDIO_SPINNER_COMP_HPP
