/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Text.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_TEXT_HPP
#define OOP_INDIE_STUDIO_2019_TEXT_HPP

#include <string>

#include "irrlicht.h"

class Text {
  public:
    Text(irr::gui::IGUIEnvironment* gui, const wchar_t* text, const irr::core::rect<irr::s32>& rectangle,
        bool border = false, bool wordWrap = true, irr::gui::IGUIElement* parent = 0, irr::s32 id = -1,
        bool fillBackground = false);
    ~Text();

    void setFont(const irr::io::path& path);

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::gui::IGUIStaticText* text;
    irr::gui::IGUIFont* font;
};

#endif // OOP_INDIE_STUDIO_2019_TEXT_HPP
