/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#ifndef INDIESTUDIO_BOUNDINGBOX_COMP_HPP
#define INDIESTUDIO_BOUNDINGBOX_COMP_HPP

#include <irrlicht.h>

#include <array>

namespace ecs::component {

class BoundingBox {
  public:
    BoundingBox(irr::scene::IMeshSceneNode *mesh = nullptr, irr::scene::ITriangleSelector *selector = nullptr);
    BoundingBox(const BoundingBox &box);
    virtual ~BoundingBox();

  public:
    irr::scene::IMeshSceneNode *mesh;
    irr::scene::ITriangleSelector *selector;
    std::array<bool, 4> collision;
};

} // namespace ecs::component

#endif // INDIESTUDIO_BOUNDINGBOX_COMP_HPP
