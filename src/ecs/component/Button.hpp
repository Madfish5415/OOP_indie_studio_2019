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

namespace ecs::component {

class Button {
  public:
    Button(irr::gui::IGUIEnvironment* gui = nullptr, irr::core::rect<irr::s32>* rect = nullptr,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, const wchar_t* text = nullptr,
        const wchar_t* tooltipText = nullptr);
    Button(const Button& button);
    ~Button();

    void setFont(const irr::io::path& path);
    void setImage(irr::video::ITexture* image);
    void setPressedImage(irr::video::ITexture* pressedImage);

  public:
    irr::gui::IGUIEnvironment* gui;
    irr::core::rect<irr::s32>* rect{};
    irr::gui::IGUIElement* parent;
    irr::s32 id;
    const wchar_t* text;
    const wchar_t* tooltipText;
    irr::gui::IGUIButton* button;
    irr::gui::IGUIFont* font;
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_BUTTON_HPP
