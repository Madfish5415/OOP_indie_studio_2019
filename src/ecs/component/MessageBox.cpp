/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MessageBox.cpp
*/

#include "MessageBox.hpp"

MessageBox::MessageBox(irr::gui::IGUIEnvironment* gui, const wchar_t* caption, const wchar_t* text, bool modal, irr::s32 flags, irr::gui::IGUIElement* parent, irr::s32 id, irr::video::ITexture* image) {
    this->gui = gui;
    this->messageBox = gui->addMessageBox(caption, text, modal, flags, parent, id, image);
}