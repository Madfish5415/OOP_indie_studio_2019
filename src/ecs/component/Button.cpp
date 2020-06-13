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
      font(nullptr),
      normalImage(nullptr),
      hoverImage(nullptr)
{
    if (gui) {
        button = gui->addButton(*rect, parent, id, text, tooltipText);
        button->setUseAlphaChannel(true);
        button->setDrawBorder(false);
    }
}

Button::Button(const Button& btn)
{
    gui = btn.gui;
    if (btn.rect)
        rect.reset(new irr::core::rect<irr::s32>(btn.rect->UpperLeftCorner, btn.rect->LowerRightCorner));
    else
        rect = nullptr;
    parent = btn.parent;
    id = btn.id;
    text = btn.text;
    tooltipText = btn.tooltipText;
    button = btn.button;
    font = btn.font;
    normalImage = btn.normalImage;
    hoverImage = btn.hoverImage;
}

Button::~Button() = default;

void Button::setFont(const irr::io::path& path)
{
    this->font = this->gui->getFont(path);
    this->button->setOverrideFont(this->font);
}

void Button::setImage(irr::video::ITexture* image)
{
    normalImage = image;
    button->setImage(image);
}

void Button::setHoverImage(irr::video::ITexture* image)
{
    hoverImage = image;
}

void Button::setPressedImage(irr::video::ITexture* image)
{
    button->setPressedImage(image);
}
