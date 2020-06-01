/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE up, irr::EKEY_CODE down, irr::EKEY_CODE bomb)
{
    _left = left;
    _right = right;
    _up = up;
    _down = down;
    _bomb = bomb;
}

Player::~Player()
{
}
