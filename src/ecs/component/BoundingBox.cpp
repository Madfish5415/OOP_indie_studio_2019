/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

ecs::component::BoundingBox::BoundingBox(irr::scene::IMeshSceneNode *mesh, irr::scene::ITriangleSelector *selector)
    : mesh(mesh), selector(selector), collision({false, false, false, false})
{
}

ecs::component::BoundingBox::BoundingBox(const ecs::component::BoundingBox &box) = default;

ecs::component::BoundingBox::~BoundingBox() = default;
