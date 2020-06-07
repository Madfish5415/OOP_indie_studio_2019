/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Key
*/

#include "Key.hpp"

using namespace ecs::event;

Key::Key(const irr::EKEY_CODE& keycode, bool isPressed) : keycode(keycode), pressed(isPressed)
{
}

Key::~Key() = default;
