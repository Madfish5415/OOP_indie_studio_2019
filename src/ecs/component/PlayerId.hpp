/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushButton.cpp
*/

#ifndef INDIESTUDIO_PLAYERID_HPP
#define INDIESTUDIO_PLAYERID_HPP

#include <cstddef>

/**
 * @file PlayerId.hpp
 * @brief PlayerId Class
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
 * @class PlayerId
 * @brief Contain a player id.
 */
class PlayerId {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param id : The id of the player.
     */
    PlayerId(size_t id = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param playerId : Element to be copied.
     */
    PlayerId(const PlayerId& playerId);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~PlayerId();

  public:
    size_t id; /** < The player id. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_PLAYERID_HPP
