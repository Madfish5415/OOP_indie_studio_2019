/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Render3d
*/

#ifndef RENDER3D_HPP_
#define RENDER3D_HPP_

#include <irrlicht.h>

/**
 * @file Render3d.hpp
 * @brief Render3d Class
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
 * @class Render3d
 * @brief Allow entity to have a 3D representation.
 */
class Render3d {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param node : A pointer on the node.
     */
    Render3d(irr::scene::ISceneNode *node = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param render : Element to be copied.
     */
    Render3d(const Render3d &render);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Render3d();

  public:
    irr::scene::ISceneNode *node; /** < The node. */
};

} // namespace ecs::component

#endif /* !RENDER3D_HPP_ */
