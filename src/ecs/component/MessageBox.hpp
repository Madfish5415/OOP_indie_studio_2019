/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MessageBox.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP
#define OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP

#include "irrlicht.h"

namespace ecs::component {

class MessageBox {
  public:
    MessageBox(irr::gui::IGUIEnvironment* gui, const wchar_t* caption, const wchar_t* text, bool modal = true,
        irr::s32 flags = irr::gui::EMBF_OK, irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1,
        irr::video::ITexture* image = nullptr);
    ~MessageBox();

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::gui::IGUIWindow* messageBox;
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP