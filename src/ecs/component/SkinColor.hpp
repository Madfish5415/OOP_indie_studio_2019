/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SkinColor
*/

#ifndef SKINCOLOR_HPP_
#define SKINCOLOR_HPP_

#include <string>

/**
 * @file SkinColor.hpp
 * @brief SkinColor Class
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
 * @class SkinColor
 * @brief Define the skin color of a player.
 */
class SkinColor {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param color : The color of the skin.
     */
    SkinColor(const std::string &color = "");
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param skinColor : Element to be copied.
     */
    SkinColor(const SkinColor &skinColor);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~SkinColor();

  public:
    std::string color; /** < The color of the skin. */
};

} // namespace ecs::component

#endif /* !SKINCOLOR_HPP_ */
