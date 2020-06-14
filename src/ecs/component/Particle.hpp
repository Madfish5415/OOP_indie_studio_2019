/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <irrlicht.h>

/**
 * @file Particle.hpp
 * @brief Particle Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace ecs
 * @namespace component
 */
namespace ecs::component {

/**
 * @class Particle
 * @brief Adds particles.
 */
class Particle {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param particleSystem : The particle generator.
     */
    Particle(irr::scene::IParticleSystemSceneNode *particleSystem = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param particle : Element to be copied.
     */
    Particle(const Particle &particle);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Particle();

  public:
    irr::scene::IParticleSystemSceneNode *particleSystem; /** < The particle generator. */
};

} // namespace ecs::component

#endif /* !PARTICLE_HPP_ */
