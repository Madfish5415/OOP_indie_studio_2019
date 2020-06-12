/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Render3d
*/

#ifndef RENDER3D_HPP_
#define RENDER3D_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Render3d {
  public:
    Render3d(irr::scene::ISceneNode *node = nullptr);
    Render3d(const Render3d &render);
    virtual ~Render3d();

  public:
    irr::scene::ISceneNode *node;
};

} // namespace ecs::component

#endif /* !RENDER3D_HPP_ */
