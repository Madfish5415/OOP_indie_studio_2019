/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

using namespace ecs::component;

BoundingBox::BoundingBox(irr::scene::IMeshSceneNode *mesh, irr::scene::ITriangleSelector *selector)
    : mesh(mesh), selector(selector), collision({false, false, false, false})
{
}

BoundingBox::BoundingBox(const BoundingBox &box) = default;

BoundingBox::~BoundingBox() = default;
