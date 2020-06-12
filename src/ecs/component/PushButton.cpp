/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushButton.cpp
*/

#include "PushButton.hpp"

using namespace ecs::component;

PushButton::PushButton(irr::gui::IGUIEnvironment* gui, irr::core::rect<irr::s32>* rect, irr::gui::IGUIElement* parent,
               irr::s32 id, const wchar_t* text, const wchar_t* tooltipText)
    : gui(gui), rect(rect), parent(parent), id(id), text(text), tooltipText(tooltipText), font(nullptr),
      normalImage(nullptr), hoverImage(nullptr)
{
    if (gui) {
        button = gui->addButton(*rect, parent, id, text, tooltipText);
        button->setUseAlphaChannel(true);
        button->setDrawBorder(false);
        button->setIsPushButton(true);
    }
}

PushButton::PushButton(const PushButton& btn)
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
    button->setIsPushButton(true);
    font = btn.font;
    normalImage = btn.normalImage;
    hoverImage = btn.hoverImage;
}

PushButton::~PushButton() = default;

void PushButton::setFont(const irr::io::path& path)
{
    this->font = this->gui->getFont(path);
    this->button->setOverrideFont(this->font);
}

void PushButton::setText(const std::wstring& text)
{

    button->setText(text.c_str());
}

void PushButton::setImage(irr::video::ITexture* image)
{
    normalImage = image;
    button->setImage(image);
}

void PushButton::setHoverImage(irr::video::ITexture* image)
{
    hoverImage = image;
}

void PushButton::setPressedImage(irr::video::ITexture* image)
{
    button->setPressedImage(image);
}

