/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

using namespace ecs::component;

Player::Player(irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE up, irr::EKEY_CODE down, irr::EKEY_CODE bomb)
    : left(left), right(right), up(up), down(down), bomb(bomb)
{
}

Player::~Player() = default;