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
        Animation(ecs::WorldManager* worldManager);
        ~Animation();

    public:
        void update();
};
}

#endif // INDIESTUDIO_ANIMATION_HPP_
