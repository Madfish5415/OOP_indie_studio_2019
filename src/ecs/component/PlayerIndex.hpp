/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PlayerIndex.hpp
*/

#ifndef INDIESTUDIO_PLAYERINDEX_HPP
#define INDIESTUDIO_PLAYERINDEX_HPP

/**
 * @file PlayerIndex.hpp
 * @brief PlayerIndex Class
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
 * @class PlayerIndex
 * @brief Contain a player index.
 */
class PlayerIndex {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param idx : The index of the player.
     */
    PlayerIndex(int idx = 0);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param playerIndex : Element to be copied.
     */
    PlayerIndex(const PlayerIndex& playerIndex);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~PlayerIndex();

  public:
    int idx; /** < The player index. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_PLAYERINDEX_HPP
