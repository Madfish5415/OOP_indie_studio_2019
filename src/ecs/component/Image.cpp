/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.cpp
*/

#include "Image.hpp"

#include <utility>

using namespace ecs::component;

Image::Image(irr::gui::IGUIEnvironment* gui, irr::video::IVideoDriver* driver, const std::string& pathTexture,
             irr::core::position2d<irr::s32>* position, bool useAlphaChannelOfTexture,
             irr::gui::IGUIElement* parent, irr::s32 id)
    : gui(gui),
      driver(driver),
      pathTexture(pathTexture),
      position(position),
      useAlphaChannelOfTexture(useAlphaChannelOfTexture),
      parent(parent),
      id(id)
{
    if (gui && driver) {
        irr::video::ITexture *texture = driver->getTexture(pathTexture.c_str());
        this->image = gui->addImage(texture, *position, useAlphaChannelOfTexture, parent, id, nullptr);
    }
}

Image::Image(const Image& image) = default;

Image::~Image() = default;