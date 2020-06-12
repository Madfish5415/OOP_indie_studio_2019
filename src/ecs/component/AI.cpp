/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "AI.hpp"

using namespace ecs::component;

AI::AI() : lastDirection(""), lastPos(irr::core::vector3d<irr::f32>(1500, 1500, 1500))
{

}

AI::AI(const AI& ai) = default;

AI::~AI() = default;