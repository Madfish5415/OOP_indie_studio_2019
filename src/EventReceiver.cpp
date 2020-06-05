/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** EventReceiver.cpp
*/

#include "EventReceiver.hpp"

#include "ecs/Def.hpp"
#include "ecs/Universe.hpp"
#include "scene/Menu.hpp"
#include "scene/PlayerSelector.hpp"

EventReceiver::EventReceiver(ecs::Universe *universe) : _universe(universe)
{
}

EventReceiver::~EventReceiver() = default;

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
                if (id == BUTTON_ID::GUI_MENU_PLAY) {
                    scene::Menu::destroy(_universe);
                    scene::PlayerSelector::init(_universe);
                    if (_universe->hasWorldManager("PlayerSelector"))
                        _universe->setCurrentWorldManager("PlayerSelector");
                    return true;
                } else if (id == BUTTON_ID::GUI_MENU_HTP) {
                    if (_universe->hasWorldManager("HowToPlay")) {
                        scene::Menu::destroy(_universe);
                        _universe->setCurrentWorldManager("HowToPlay");
                    }
                    return true;
                } else if (id == BUTTON_ID::GUI_MENU_QUIT) {
                    _universe->getDevice()->closeDevice();
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_MENU) {
                    scene::PlayerSelector::destroy(_universe);
                    scene::Menu::init(_universe);
                    if (_universe->hasWorldManager("Menu"))
                        _universe->setCurrentWorldManager("Menu");
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_ADD_PLAYER) {
                    scene::PlayerSelector::addPlayer(_universe);
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_REMOVE_PLAYER) {
                    scene::PlayerSelector::removePlayer(_universe);
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_SKIN_P1_LEFT || id == BUTTON_ID::GUI_SELECT_SKIN_P1_RIGHT ||
                    id == BUTTON_ID::GUI_SELECT_SKIN_P2_LEFT || id == BUTTON_ID::GUI_SELECT_SKIN_P2_RIGHT ||
                    id == BUTTON_ID::GUI_SELECT_SKIN_P3_LEFT || id == BUTTON_ID::GUI_SELECT_SKIN_P3_RIGHT ||
                    id == BUTTON_ID::GUI_SELECT_SKIN_P4_LEFT || id == BUTTON_ID::GUI_SELECT_SKIN_P4_RIGHT) {
                    scene::PlayerSelector::changeSkin(_universe, id);
                    return true;
                }
        }
    }
    return false;
}