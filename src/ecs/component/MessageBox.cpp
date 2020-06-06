/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MessageBox.cpp
*/

#include "MessageBox.hpp"

using namespace ecs::component;

MessageBox::MessageBox(irr::gui::IGUIEnvironment* gui, const wchar_t* caption, const wchar_t* text, bool modal,
    irr::s32 flags, irr::gui::IGUIElement* parent, irr::s32 id, irr::video::ITexture* image)
    : gui(gui), messageBox(gui->addMessageBox(caption, text, modal, flags, parent, id, image))
{
}

MessageBox::MessageBox(const MessageBox &messageBox) : gui(messageBox.gui), messageBox(messageBox.messageBox)
{
}

MessageBox::~MessageBox() = default;