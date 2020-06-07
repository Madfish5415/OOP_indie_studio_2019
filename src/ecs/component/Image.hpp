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
    Image(irr::gui::IGUIEnvironment* gui = nullptr, irr::video::IVideoDriver* driver = nullptr,
        const std::string& pathTexture = "", irr::core::position2d<irr::s32>* position = nullptr,
        bool useAlphaChannelOfTexture = true, irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1);
    Image(const Image& image);
    ~Image();

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::video::IVideoDriver* driver;
    irr::gui::IGUIImage* image;
    std::string pathTexture;
    irr::core::position2d<irr::s32>* position;
    bool useAlphaChannelOfTexture;
    irr::gui::IGUIElement* parent;
    irr::s32 id;
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP
