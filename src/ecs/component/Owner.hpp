/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Owner
*/

#ifndef OWNER_HPP_
#define OWNER_HPP_

#include "../Def.hpp"

/**
 * @file Owner.hpp
 * @brief Owner Class
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
 * @class Owner
 * @brief Tell who is the owner of an entity.
 */
class Owner {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param ID : The owner ID.
     */
    Owner(const ecs::Entity &ID = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param owner : Element to be copied.
     */
    Owner(const Owner &owner);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Owner();

  public:
    ecs::Entity entity; /** < The owner id. */
};

} // namespace ecs::component

#endif /* !OWNER_HPP_ */
