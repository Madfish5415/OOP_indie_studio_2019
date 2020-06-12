/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Countdown
*/

#ifndef INDIESTUDIO_SYSTEM_COUNTDOWN_HPP_
#define INDIESTUDIO_SYSTEM_COUNTDOWN_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Countdown : public System {
    public:
        Countdown(ecs::WorldManager* worldManager);
        ~Countdown();

    public:
        void update() override;
};

}

#endif /* !COUNTDOWN_HPP_ */
