/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "AI.hpp"

using namespace ecs::component;

AI::AI()
    : lastDirection(""),
      lastPos(irr::core::vector3d<irr::f32>(1500, 1500, 1500)),
      lastEscape(irr::core::vector3d<irr::f32>(-50, 0, -50)),
      lastChoice("")
{
}

AI::AI(const AI& ai) = default;

AI::~AI() = default;