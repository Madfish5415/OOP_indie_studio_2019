/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef OOP_INDIE_STUDIO_2019_COMP_PLAYER_HPP
#define OOP_INDIE_STUDIO_2019_COMP_PLAYER_HPP

#include <irrlicht.h>

#include <map>
#include <unordered_map>

/**
 * @file Player.hpp
 * @brief Player Class
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
 * @class Player
 * @brief Controlable by user input.
 */
class Player {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param keys : The map of all the inputs.
     */
    Player(std::unordered_map<std::string, irr::EKEY_CODE> keys = {{"up", irr::EKEY_CODE::KEY_KEY_Z},
               {"down", irr::EKEY_CODE::KEY_KEY_S}, {"left", irr::EKEY_CODE::KEY_KEY_Q},
               {"right", irr::EKEY_CODE::KEY_KEY_D}, {"bomb", irr::EKEY_CODE::KEY_SPACE}});
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param player : Element to be copied.
     */
    Player(const Player& player);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Player();

  public:
    std::unordered_map<std::string, irr::EKEY_CODE> keys; /** < The map of all the inputs. */
    std::string lastKey; /** < The last pressed key. */
};

} // namespace ecs::component

#endif /* !PLAYER_HPP_ */
