/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player.cpp
*/

#include "Player.hpp"

#include <utility>

using namespace ecs::component;

Player::Player(char left, char right, char up, char down, char bomb)
    : left(left), right(right), up(up), down(down), bomb(bomb)
{
}

Player::Player(const Player& player)
{
    left = player.left;
    right = player.right;
    up = player.up;
    down = player.down;
    bomb = player.bomb;
}

Player::~Player() = default;
