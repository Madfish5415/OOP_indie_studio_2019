/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#ifndef INDIESTUDIO_BOUNDINGBOX_HPP
#define INDIESTUDIO_BOUNDINGBOX_HPP

#include <irrlicht.h>

#include "../System.hpp"

namespace ecs::system {

class BoundingBox : public System {
  public:
    explicit BoundingBox(WorldManager *worldManager);
    ~BoundingBox() override;

  public:
    void update() override;

  private:
    bool isCollide(irr::scene::IMeshSceneNode *mesh, size_t id);
};

} // namespace ecs::system

#endif // INDIESTUDIO_BOUNDINGBOX_HPP
