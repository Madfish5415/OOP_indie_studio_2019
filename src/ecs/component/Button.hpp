/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_BUTTON_HPP
#define OOP_INDIE_STUDIO_2019_BUTTON_HPP

#include <string>

#include "irrlicht.h"

class Button {
  public:
    Button(irr::gui::IGUIEnvironment* gui, const irr::core::rect<irr::s32>& position,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, const wchar_t* text = nullptr,
        const wchar_t* tooltipText = nullptr);
    ~Button();

    void setFont(const irr::io::path& path);
    void setImage(irr::video::ITexture* image);
    void setPressedImage(irr::video::ITexture* pressedImage);

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::gui::IGUIButton* button;
    irr::gui::IGUIFont* font;
};

#endif // OOP_INDIE_STUDIO_2019_BUTTON_HPP
