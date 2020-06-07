/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

using namespace ecs::component;

Player::Player(std::unordered_map<std::string, irr::EKEY_CODE> keys) : keys(keys), lastKey("")
{
}

Player::Player(const Player& player) : keys(player.keys), lastKey(player.lastKey)
{
}

Player::~Player() = default;
