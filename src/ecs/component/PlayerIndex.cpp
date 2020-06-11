/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PlayerIndex.cpp
*/

#include "PlayerIndex.hpp"

using namespace ecs::component;

PlayerIndex::PlayerIndex(int idx) : idx(idx)
{
}

PlayerIndex::PlayerIndex(const PlayerIndex& playerIndex) = default;

PlayerIndex::~PlayerIndex() = default;
