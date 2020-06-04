/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.cpp
*/

#include "Image.hpp"

#include <utility>

using namespace ecs::component;

Image::Image(irr::video::IVideoDriver* driver, const irr::io::path texture,
    irr::core::position2d<irr::s32>* position, irr::core::rect<irr::s32>* rect,
    irr::core::rect<irr::s32>* clipRect, irr::video::SColor scolor, bool useAlphaChannelOfTexture)
    : driver(driver),
      position(position),
      rect(rect),
      clipRect(clipRect),
      scolor(scolor),
      useAlphaChannelOfTexture(useAlphaChannelOfTexture)
{
    if(driver)
        this->texture = driver->getTexture(texture);
}

Image::~Image() = default;