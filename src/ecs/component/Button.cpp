/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button.cpp
*/

#include "Button.hpp"

using namespace ecs::component;

Button::Button(irr::gui::IGUIEnvironment* gui, irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent,
    irr::s32 id, const wchar_t* text, const wchar_t* tooltipText)
    : gui(gui),
      rect(rect),
      parent(parent),
      id(id),
      text(text),
      tooltipText(tooltipText),
      button(gui->addButton(*rect, parent, id, text, tooltipText)),
      font(nullptr)
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

Button::Button(const Button& btn)
{
    gui = btn.gui;
    rect->UpperLeftCorner.X = btn.rect->UpperLeftCorner.X;
    rect->UpperLeftCorner.Y = btn.rect->UpperLeftCorner.Y;
    rect->LowerRightCorner.X = btn.rect->LowerRightCorner.X;
    rect->LowerRightCorner.Y = btn.rect->LowerRightCorner.Y;
    parent = btn.parent;
    id = btn.id;
    text = btn.text;
    tooltipText = btn.tooltipText;
    button = btn.button;
    font = btn.font;
}
Button::~Button() = default;