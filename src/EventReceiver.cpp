/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** EventReceiver.cpp
*/

#include "EventReceiver.hpp"

#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "ecs/Def.hpp"
#include "ecs/Universe.hpp"
#include "ecs/component/Button.hpp"
#include "ecs/component/Image.hpp"
#include "ecs/component/Music.hpp"
#include "ecs/component/PushButton.hpp"
#include "ecs/event/Key.hpp"
#include "scene/Bomberman.hpp"
#include "scene/Keybinding.hpp"
#include "scene/LoadingMenu.hpp"
#include "scene/Menu.hpp"
#include "scene/Pause.hpp"
#include "scene/PlayerSelector.hpp"
#include "scene/Settings.hpp"

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
            scene::Menu::init(_universe, sf::Time::Zero);
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
        if (_universe->hasWorldManager("Bomberman") &&
            _universe->getCurrentWorldManager() == _universe->getWorldManager("Bomberman")) {
            ecs::event::Key keyEvent(event.KeyInput.Key, event.KeyInput.PressedDown);
            _universe->getWorldManager("Bomberman")->publish(keyEvent);
            if (event.KeyInput.Key == irr::KEY_ESCAPE && !event.KeyInput.PressedDown) {
                scene::Pause::init(_universe);
                _universe->setCurrentWorldManager("Pause");
            }
            return false;
        }
        if (_universe->hasWorldManager("Pause") &&
            _universe->getCurrentWorldManager() == _universe->getWorldManager("Pause")) {
            if (event.KeyInput.Key == irr::KEY_ESCAPE && !event.KeyInput.PressedDown) {
                scene::Pause::destroy(_universe);
                _universe->setCurrentWorldManager("Bomberman");
            }
            return true;
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
                    auto entity = _universe->getWorldManager("Menu")->getEntities<ecs::component::Music>();
                    auto& music = _universe->getWorldManager("Menu")->getComponent<ecs::component::Music>(entity[0]);
                    sf::Time time = music.music->getPlayingOffset();
                    scene::Menu::destroy(_universe);
                    scene::PlayerSelector::init(_universe, time);
                    if (_universe->hasWorldManager("PlayerSelector"))
                        _universe->setCurrentWorldManager("PlayerSelector");
                    return true;
                } else if (id == BUTTON_ID::GUI_MENU_HTP) {
                    if (_universe->hasWorldManager("HowToPlay")) {
                        scene::Menu::destroy(_universe);
                        _universe->setCurrentWorldManager("HowToPlay");
                    }
                    return true;
                } else if (id == BUTTON_ID::GUI_MENU_SETTINGS) {
                    auto musics = _universe->getWorldManager("Menu")->getEntities<ecs::component::Music>();
                    auto& music = _universe->getWorldManager("Menu")->getComponent<ecs::component::Music>(musics[0]);
                    scene::Settings::init(_universe, music.music);
                    if (_universe->hasWorldManager("Settings")) {
                        _universe->setCurrentWorldManager("Settings");
                    }
                    return true;
                } else if (id == BUTTON_ID::GUI_MENU_QUIT) {
                    _universe->getDevice()->closeDevice();
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_MENU) {
                    auto entity = _universe->getWorldManager("PlayerSelector")->getEntities<ecs::component::Music>();
                    auto& music = _universe->getWorldManager("PlayerSelector")->getComponent<ecs::component::Music>(entity[0]);
                    sf::Time time = music.music->getPlayingOffset();
                    scene::PlayerSelector::destroy(_universe);
                    scene::Menu::init(_universe, time);
                    if (_universe->hasWorldManager("Menu"))
                        _universe->setCurrentWorldManager("Menu");
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_ADD_PLAYER) {
                    scene::PlayerSelector::addPlayer(_universe);
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_REMOVE_PLAYER) {
                    scene::PlayerSelector::removePlayer(_universe);
                    return true;
                } else if (id >= BUTTON_ID::GUI_SELECT_SKIN_P1_LEFT && id <= BUTTON_ID::GUI_SELECT_SKIN_P4_RIGHT) {
                    scene::PlayerSelector::changeSkin(_universe, id);
                    return true;
                } else if (id >= BUTTON_ID::GUI_SELECT_TYPE_P1_LEFT && id <= BUTTON_ID::GUI_SELECT_TYPE_P4_RIGHT) {
                    scene::PlayerSelector::changeType(_universe, id);
                    return true;
                } else if (id == BUTTON_ID::GUI_SELECT_KB_P1 || id == BUTTON_ID::GUI_SELECT_KB_P2 ||
                    id == BUTTON_ID::GUI_SELECT_KB_P3 || id == BUTTON_ID::GUI_SELECT_KB_P4) {
                    if (!scene::PlayerSelector::typeList[id - BUTTON_ID::GUI_SELECT_KB_P1]) {
                        auto &image = _universe->getWorldManager("PlayerSelector")
                            ->getComponent<ecs::component::Image>(
                                scene::PlayerSelector::playerIds[id - BUTTON_ID::GUI_SELECT_KB_P1]);
                        scene::Keybinding::init(_universe, image.pathTexture,
                                                &scene::PlayerSelector::playerComponent[id - BUTTON_ID::GUI_SELECT_KB_P1]);
                        _universe->setCurrentWorldManager("Keybinding");
                    }
                } else if (id == GUI_SELECT_KB_BACK) {
                    scene::Keybinding::destroy(_universe);
                    _universe->setCurrentWorldManager("PlayerSelector");
                    return true;
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
                        for (const auto &entity : scene::PlayerSelector::playerIds) {
                            auto &image = _universe->getWorldManager("PlayerSelector")
                                              ->getComponent<ecs::component::Image>(entity);
                            std::string path = scene::playerselector::player::SKIN_TO_MODEL[image.pathTexture];
                            pathTextureList.push_back(path);
                        }
                        std::vector<ecs::component::Player> tmpCmp = scene::PlayerSelector::playerComponent;
                        std::vector<bool> tmpType = scene::PlayerSelector::typeList;
                        scene::PlayerSelector::destroy(_universe);
                        scene::Bomberman::init(_universe, tmpCmp, pathTextureList, tmpType);
                        if (_universe->hasWorldManager("Bomberman"))
                            _universe->setCurrentWorldManager("Bomberman");
                    }
                    return true;
                } else if (id == GUI_GAME_PAUSE) {
                    scene::Pause::init(_universe);
                    _universe->setCurrentWorldManager("Pause");
                    return true;
                } else if (id == GUI_PAUSE_RESUME) {
                    scene::Pause::destroy(_universe);
                    _universe->setCurrentWorldManager("Bomberman");
                    return true;
                } else if (id == GUI_PAUSE_MENU) {
                    scene::Pause::destroy(_universe);
                    scene::Bomberman::destroy(_universe);
                    scene::Menu::init(_universe, sf::Time::Zero);
                    if (_universe->hasWorldManager("Menu"))
                        _universe->setCurrentWorldManager("Menu");
                    return true;
                } else if (id == GUI_PAUSE_SETTINGS) {
                    auto musics = _universe->getWorldManager("Bomberman")->getEntities<ecs::component::Music>();
                    auto& music = _universe->getWorldManager("Bomberman")->getComponent<ecs::component::Music>(musics[0]);
                    scene::Settings::init(_universe, music.music);
                    if (_universe->hasWorldManager("Settings"))
                        _universe->setCurrentWorldManager("Settings");
                    return true;
                } else if (id == GUI_SETTINGS_BACK) {
                    scene::Settings::destroy(_universe);
                    if (_universe->hasWorldManager("Pause"))
                        _universe->setCurrentWorldManager("Pause");
                    else
                        _universe->setCurrentWorldManager("Menu");
                    return true;
                } else if (id == GUI_SETTINGS_MUSIC_VOL_MINUS) {
                    scene::Settings::musicVolume -= 10;
                    if (scene::Settings::musicVolume < 0)
                        scene::Settings::musicVolume = 0;
                    scene::Settings::updateSoundBar(_universe);
                    return true;
                } else if (id == GUI_SETTINGS_MUSIC_VOL_PLUS) {
                    scene::Settings::musicVolume += 10;
                    if (scene::Settings::musicVolume > 100)
                        scene::Settings::musicVolume = 100;
                    scene::Settings::updateSoundBar(_universe);
                    return true;
                } else if (id == GUI_SETTINGS_SOUND_VOL_MINUS) {
                    scene::Settings::soundVolume -= 10;
                    if (scene::Settings::soundVolume < 0)
                        scene::Settings::soundVolume = 0;
                    scene::Settings::updateSoundBar(_universe);
                    return true;
                } else if (id == GUI_SETTINGS_SOUND_VOL_PLUS) {
                    scene::Settings::soundVolume += 10;
                    if (scene::Settings::soundVolume > 100)
                        scene::Settings::soundVolume = 100;
                    scene::Settings::updateSoundBar(_universe);
                    return true;
                }
            default:
                break;
        }
    }
    return false;
}