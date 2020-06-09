/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Particle
*/

#include "Particle.hpp"

using namespace ecs::component;

Particle::Particle(irr::scene::IParticleSystemSceneNode *particleSystem) : particleSystem(particleSystem)
{
}

Particle::Particle(const Particle &particle) : particleSystem(particle.particleSystem)
{
}

Particle::~Particle() = default;