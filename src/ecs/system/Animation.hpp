/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#ifndef INDIESTUDIO_ANIMATION_HPP_
#define INDIESTUDIO_ANIMATION_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Animation : public ecs::System {
  public:
    explicit Animation(ecs::WorldManager* worldManager);
    ~Animation() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_ANIMATION_HPP_
