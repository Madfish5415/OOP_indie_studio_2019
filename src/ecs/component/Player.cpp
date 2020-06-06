/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

using namespace ecs::component;

Player::Player(std::unordered_map<std::string, irr::EKEY_CODE> keys, size_t id): keys(keys)
{
}

Player::Player(const Player& player) : keys(player.keys)
{
}

Player::~Player() = default;