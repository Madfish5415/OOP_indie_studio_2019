/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button.cpp
*/

#include "Button.hpp"

Button::Button(irr::gui::IGUIEnvironment* gui, const irr::core::rect<irr::s32>& position, irr::gui::IGUIElement* parent,
    irr::s32 id, const wchar_t* text, const wchar_t* tooltipText)
    : gui(gui), button(gui->addButton(position, parent, id, text, tooltipText)), font(nullptr)
{
}

void Button::setFont(const irr::io::path& path)
{
    this->font = this->gui->getFont(path);
    this->button->setOverrideFont(this->font);
}

void Button::setImage(irr::video::ITexture* image)
{
    this->button->setImage(image);
}

void Button::setPressedImage(irr::video::ITexture* pressedImage)
{
    this->button->setPressedImage(pressedImage);
}
Button::~Button() = default;
