/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <irrlicht.h>

namespace ecs::component {

class Particle {
    public:
        Particle(irr::scene::IParticleSystemSceneNode *particleSystem = nullptr);
        Particle(const Particle &particle);
        ~Particle();

    public:
        irr::scene::IParticleSystemSceneNode *particleSystem;
};

}

#endif /* !PARTICLE_HPP_ */
