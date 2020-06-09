/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushButton.cpp
*/

#include "PlayerId.hpp"

using namespace ecs::component;

PlayerId::PlayerId(size_t id) : id(id)
{
}

PlayerId::PlayerId(const PlayerId& playerId) = default;

PlayerId::~PlayerId() = default;
