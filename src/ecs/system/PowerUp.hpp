/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#ifndef INDIESTUDIO_POWERUP_HPP_
#define INDIESTUDIO_POWERUP_HPP_

#include "../System.hpp"

namespace ecs::system {

class PowerUp : public System {
    public:
        explicit PowerUp(ecs::WorldManager *worldManager);
        ~PowerUp() override;

    public:
        void update() override;
};

}

#endif /* !INDIESTUDIO_POWERUP_HPP_ */
