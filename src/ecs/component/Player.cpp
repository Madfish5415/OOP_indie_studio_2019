/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

using namespace ecs::component;

Player::Player(std::unordered_map<std::string, irr::EKEY_CODE> keys, size_t id): keys(keys), id(id)
{
}

Player::Player(const Player& player) : id(player.id), keys(player.keys)
{
}

Player::~Player() = default;