/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StatRender.hpp
*/

#ifndef INDIESTUDIO_STATRENDER_COMP_HPP
#define INDIESTUDIO_STATRENDER_COMP_HPP

#include "../Def.hpp"

/**
 * @file StatRender.hpp
 * @brief StatRender Class
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
 * @class StatRender
 * @brief Render stats.
 */
class StatRender {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param owner : The owner.
     * @param type : The stat type.
     */
    StatRender(ecs::Entity owner = 0, const std::string& type = "");
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param statRender : Element to be copied.
     */
    StatRender(const StatRender& statRender);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~StatRender();

  public:
    ecs::Entity owner; /** < The owner. */
    std::string type; /** < The stat type. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_STATRENDER_COMP_HPP
