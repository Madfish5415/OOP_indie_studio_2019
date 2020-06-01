/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.cpp
*/

#include "Image.hpp"

Image::Image(irr:video::IVideoDriver* driver, std::string texture, irr::core::position2d<irr:s32> position, irr::core::rect<irr::s32> rect, irr::core::rect<irr::s32>* clipRect, irr::video::SColor scolor, bool useAlphaChannelOfTexture) {
    this->driver = driver;
    this->position = position;
    this->rect = rect;
    this->clipRect = clipRect;
    this->scolor = scolor;
    this->useAlphaChannelOfTexture = useAlphaChannelOfTexture;
    this->texture = driver->getTexture(texture);
}