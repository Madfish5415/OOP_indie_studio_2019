/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.cpp
*/

#include "Image.hpp"

#include <utility>

using namespace ecs::component;

Image::Image(irr::video::IVideoDriver* driver, const irr::io::path& texture,
    const irr::core::position2d<irr::s32>& position, irr::core::rect<irr::s32> rect,
    irr::core::rect<irr::s32>* clipRect, irr::video::SColor scolor, bool useAlphaChannelOfTexture)
    : driver(driver),
      texture(driver->getTexture(texture)),
      position(position),
      rect(std::move(rect)),
      clipRect(clipRect),
      scolor(scolor),
      useAlphaChannelOfTexture(useAlphaChannelOfTexture)
{
}
Image::Image(const Image& image)
    : driver(image.driver),
      texture(image.texture),
      position(image.position),
      rect(image.rect),
      clipRect(image.clipRect),
      scolor(image.scolor),
      useAlphaChannelOfTexture(image.useAlphaChannelOfTexture)
{
}

Image::~Image() = default;