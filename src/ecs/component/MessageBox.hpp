/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MessageBox.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP
#define OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP

#include "irrlicht.h"

class MessageBox {
  public:
    MessageBox(irr::gui::IGUIEnvironment* gui, const wchar_t* caption, const wchar_t* text, bool modal = true, irr::s32 flags = EMBF_OK, irr::gui::iguiEnvironment* parent = 0, irr::s32 id = -1, irr::video::ITexture* image = 0);
    ~MessageBox();

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::gui::IGUIWindow* messageBox;
};

#endif // OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP
