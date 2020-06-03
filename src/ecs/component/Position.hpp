/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Position.hpp
*/

#ifndef INDIESTUDIO_POSITION_HPP
#define INDIESTUDIO_POSITION_HPP

/**
 * @file Position.hpp
 * @brief Position Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::component
 */
namespace ecs::component {

/**
 * @class Position
 * @brief Description of the entity that informs that it has a position.
 */
class Position {
  public:
    /**
     * @brief Constructor
     * Constructor of Position Class.
     * @param x : Position in horizontal axis.
     * @param y : Position in vertical axis.
     */
    Position(int x = 1, int y = 1);
    /**
     * @brief Copy Constructor
     * Copy Constructor of Position Class.
     */
    Position(const Position& position);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Position();

  public:
    int x; /** < Position in horizontal axis. */
    int y; /** < Position in veritcal axis. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_POSITION_HPP
