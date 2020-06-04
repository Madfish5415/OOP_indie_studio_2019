/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP
#define OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP

#include <string>

#include "irrlicht.h"

namespace ecs::component {

class Image {
  public:
    Image(irr::video::IVideoDriver* driver = nullptr, irr::io::path texture = "",
        irr::core::position2d<irr::s32>* position = nullptr, irr::core::rect<irr::s32>* rect = nullptr,
        irr::core::rect<irr::s32>* clipRect = nullptr,
        irr::video::SColor scolor = irr::video::SColor(255, 255, 255, 255), bool useAlphaChannelOfTexture = false);
    ~Image();

  public:
    irr::video::IVideoDriver* driver;
    irr::video::ITexture* texture;
    irr::core::position2d<irr::s32>* position;
    irr::core::rect<irr::s32>* rect;
    irr::core::rect<irr::s32>* clipRect;
    irr::video::SColor scolor;
    bool useAlphaChannelOfTexture;
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP
