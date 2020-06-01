/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_IMAGE_HPP
#define OOP_INDIE_STUDIO_2019_IMAGE_HPP

#include "irrlicht.h"

class Image {
  public:
    Image(irr:video::IVideoDriver* driver, std::string texture, irr::core::position2d<irr:s32> position, irr::core::rect<irr::s32> rect, irr::core::rect<irr::s32>* clipRect = 0, irr::video::SColor scolor = irr::video::SColor(255, 255, 255, 255), bool useAlphaChannelOfTexture = false);
    ~Image();

  public:
    irr:video::IVideoDriver* driver;
    std::string texture;
    irr::core::position2d<irr:s32> position;
    irr::core::rect<irr::s32> rect;
    irr::core::rect<irr::s32>* clipRect;
    irr::video::SColor scolor;
    bool useAlphaChannelOfTexture;
};

#endif // OOP_INDIE_STUDIO_2019_IMAGE_HPP
