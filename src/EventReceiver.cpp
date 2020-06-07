/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** EventReceiver.cpp
*/

#include <vector>

#include "EventReceiver.hpp"

#include "ecs/Def.hpp"
#include "ecs/Universe.hpp"
#include "ecs/component/Image.hpp"
#include "ecs/component/PushButton.hpp"
#include "scene/Bomberman.hpp"
#include "scene/Keybinding.hpp"
#include "scene/LoadingMenu.hpp"
#include "scene/Menu.hpp"
#include "scene/PlayerSelector.hpp"

EventReceiver::EventReceiver(ecs::Universe *universe) : _universe(universe)
{
}

EventReceiver::~EventReceiver() = default;

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        if (_universe->hasWorldManager("LoadingMenu") &&
            _universe->getCurrentWorldManager() == _universe->getWorldManager("LoadingMenu")) {
            scene::LoadingMenu::destroy(_universe);
            scene::Menu::init(_universe);
            _universe->setCurrentWorldManager("Menu");
        }
        if (_universe->hasWorldManager("Keybinding") &&
            _universe->getCurrentWorldManager() == _universe->getWorldManager("Keybinding")) {
            int idx = 0;
            for (auto &entity : scene::Keybinding::pushButtons) {
                auto &btn = _universe->getWorldManager("Keybinding")->getComponent<ecs::component::PushButton>(entity);
                if (idx == 0 && btn.button->isPressed()) {
                    if (scene::KEYBINDING_MAP.count(event.KeyInput.Key)) {
                        scene::Keybinding::player->keys["up"] = event.KeyInput.Key;
                        btn.button->setPressed(false);
                        btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["up"]]);
                    }
                    return true;
                } else if (idx == 1 && btn.button->isPressed()) {
                    if (scene::KEYBINDING_MAP.count(event.KeyInput.Key)) {
                        scene::Keybinding::player->keys["down"] = event.KeyInput.Key;
                        btn.button->setPressed(false);
                        btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["down"]]);
                    }
                    return true;
                } else if (idx == 2 && btn.button->isPressed()) {
                    if (scene::KEYBINDING_MAP.count(event.KeyInput.Key)) {
                        scene::Keybinding::player->keys["left"] = event.KeyInput.Key;
                        btn.button->setPressed(false);
                        btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["left"]]);
                    }
                    return true;
                } else if (idx == 3 && btn.button->isPressed()) {
                    if (scene::KEYBINDING_MAP.count(event.KeyInput.Key)) {
                        scene::Keybinding::player->keys["right"] = event.KeyInput.Key;
                        btn.button->setPressed(false);
                        btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["right"]]);
                    }
                    return true;
                } else if (idx == 4 && btn.button->isPressed()) {
                    if (scene::KEYBINDING_MAP.count(event.KeyInput.Key)) {
                        scene::Keybinding::player->keys["bomb"] = event.KeyInput.Key;
                        btn.button->setPressed(false);
                        btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["bomb"]]);
                    }
                    return true;
                }
                idx++;
            }
        }
    }
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
        switch (event.MouseInput.Event) {
            case irr::EMOUSE_INPUT_EVENT::EMIE_LMOUSE_PRESSED_DOWN:
                if (_universe->hasWorldManager("Keybinding") &&
                    _universe->getCurrentWorldManager() == _universe->getWorldManager("Keybinding")) {
                    int idx = 0;
                    for (auto &entity : scene::Keybinding::pushButtons) {
                        auto &btn =
                            _universe->getWorldManager("Keybinding")->getComponent<ecs::component::PushButton>(entity);
                        if (idx == 0 && btn.button->isPressed()) {
                            btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["up"]]);
                        } else if (idx == 1 && btn.button->isPressed()) {
                            btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["down"]]);
                        } else if (idx == 2 && btn.button->isPressed()) {
                            btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["left"]]);
                        } else if (idx == 3 && btn.button->isPressed()) {
                            btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["right"]]);
                        } else if (idx == 4 && btn.button->isPressed()) {
                            btn.setText(scene::KEYBINDING_MAP[scene::Keybinding::player->keys["bomb"]]);
                        }
                        btn.button->setPressed(false);
                        idx++;
                    }
                }
                break;
            default:
                break;
        }
    }
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
                } else if (id == BUTTON_ID::GUI_SELECT_KB_P1 || id == BUTTON_ID::GUI_SELECT_KB_P2 ||
                    id == BUTTON_ID::GUI_SELECT_KB_P3 || id == BUTTON_ID::GUI_SELECT_KB_P4) {
                    auto &image = _universe->getWorldManager("PlayerSelector")
                                      ->getComponent<ecs::component::Image>(
                                          scene::PlayerSelector::playerIds[id - BUTTON_ID::GUI_SELECT_KB_P1]);
                    scene::Keybinding::init(_universe, image.pathTexture,
                        &scene::PlayerSelector::playerComponent[id - BUTTON_ID::GUI_SELECT_KB_P1]);
                    _universe->setCurrentWorldManager("Keybinding");
                } else if (id == GUI_SELECT_KB_BACK) {
                    scene::Keybinding::destroy(_universe);
                    _universe->setCurrentWorldManager("PlayerSelector");
                } else if (id == GUI_SELECT_KB_UP || id == GUI_SELECT_KB_DOWN || id == GUI_SELECT_KB_LEFT ||
                    id == GUI_SELECT_KB_RIGHT || id == GUI_SELECT_KB_ACTION) {
                    auto &btn = _universe->getWorldManager("Keybinding")
                                    ->getComponent<ecs::component::PushButton>(
                                        scene::Keybinding::pushButtons[id - GUI_SELECT_KB_UP]);
                    if (btn.button->isPressed()) {
                        btn.button->setText(L"...");
                    }
                } else if (id == GUI_SELECT_FIGHT) {
                    if (!scene::PlayerSelector::checkKeybinding(_universe)) {
                        scene::PlayerSelector::invalidKeybinding(_universe);
                    } else {
                        std::vector<std::string> pathTextureList;
                        for (const auto& entity : scene::PlayerSelector::playerIds) {
                            auto& image = _universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Image>(entity);
                            std::string path = scene::playerselector::player::SKIN_TO_MODEL[image.pathTexture];
                            pathTextureList.push_back(path);
                        }
                        std::vector<ecs::component::Player> tmp = scene::PlayerSelector::playerComponent;
                        scene::PlayerSelector::destroy(_universe);
                        scene::Bomberman::init(_universe, tmp, pathTextureList);
                        if (_universe->hasWorldManager("Bomberman"))
                            _universe->setCurrentWorldManager("Bomberman");
                    }
                    return true;
                }
            default:
                break;
        }
    }
    return false;
}