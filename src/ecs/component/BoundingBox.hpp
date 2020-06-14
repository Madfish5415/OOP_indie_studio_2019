/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#ifndef INDIESTUDIO_BOUNDINGBOX_COMP_HPP
#define INDIESTUDIO_BOUNDINGBOX_COMP_HPP

#include <irrlicht.h>

#include <array>

/**
 * @file BoundingBox.hpp
 * @brief BoundingBox Class
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
 * @class BoundingBox
 * @brief Rectangular collision.
 */
class BoundingBox {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param mesh : BoundingBox mesh.
     * @param selector : BoundingBox triangle selector.
     */
    BoundingBox(irr::scene::IMeshSceneNode *mesh = nullptr, irr::scene::ITriangleSelector *selector = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param box : Element to be copied.
     */
    BoundingBox(const BoundingBox &box);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~BoundingBox();

  public:
    irr::scene::IMeshSceneNode *mesh; /** < BoundingBox mesh. */
    irr::scene::ITriangleSelector *selector; /** < BoundingBox triangle selector. */
    std::array<bool, 4> collision; /** < Tell if the BoundingBox is applied on player (sorted by player id). */
};

} // namespace ecs::component

#endif // INDIESTUDIO_BOUNDINGBOX_COMP_HPP
