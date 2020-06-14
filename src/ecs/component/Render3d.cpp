/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Render3d
*/

#include "Render3d.hpp"

using namespace ecs::component;

Render3d::Render3d(irr::scene::ISceneNode *node) : node(node)
{
}

Render3d::Render3d(const Render3d &render) = default;

Render3d::~Render3d() = default;