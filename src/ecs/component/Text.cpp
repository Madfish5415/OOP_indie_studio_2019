/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

Text::Text(irr::gui::IGUIEnvironment* gui, const wchar_t* text, const irr::core::rect<irr::s32>& rectangle, bool border,
    bool wordWrap, irr::gui::IGUIElement* parent, irr::s32 id, bool fillBackground)
{
    this->gui = gui;
    this->text = gui->addStaticText(text, rectangle, border, wordWrap, parent, id, fillBackground);
    this->font = nullptr;
}

void Text::setFont(const irr::io::path& path)
{
    this->font = this->gui->getFont(path);
    this->text->setOverrideFont(this->font);
}
