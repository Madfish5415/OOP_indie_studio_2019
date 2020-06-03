/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_PLAYER_HPP
#define OOP_INDIE_STUDIO_2019_PLAYER_HPP

#include <string>

/**
 * @file Player.hpp
 * @brief Player Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::component
 */
namespace ecs::component {

/**
 * @class Player
 * @brief Description of the entity that informs that it can be controlled by user entries.
 */
class Player {
  public:
    /**
     * @brief Constructor
     * Constructor of Player Class.
     * @param left : Makes the player go left.
     * @param right : Makes the player go right.
     * @param up : Makes the player go up.
     * @param down : Makes the player go down.
     * @param bomb : Makes the player plant a bomb.
     */
    Player(char left = 'Q', char right = 'D', char up = 'Z', char down = 'S',
        char bomb = 'B');
    /**
     * @brief Copy Constructor
     * Copy Constructor of Player Class.
     */
    Player(const Player& player);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Player();

  public:
    char left; /**< left key.*/
    char right; /**< right key.*/
    char up; /**< up key.*/
    char down; /**< down key.*/
    char bomb; /**< bomb key.*/
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_PLAYER_HPP
