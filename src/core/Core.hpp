/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_CORE_HPP
#define OOP_INDIE_STUDIO_2019_CORE_HPP

#include "../ecs/Universe.hpp"

/**
 * @file Core.hpp
 * @brief Core Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace core
 */
namespace core {

/**
 * @class Core
 * @brief This class is the core of our program, it handle the universe and the game loop.
 */
class Core {
  public:
    /**
     * @brief Constructor
     * Create the universe.
     */
    Core();
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Core();

  public:
    /**
     * @brief init method
     * This method create the first scene.
     */
    void init();
    /**
     * @brief run method
     * This method use the universe for loop on the current world manager (It's the game loop).
     */
    void run();

  private:
    std::unique_ptr<ecs::Universe> _universe; /** < A smart pointer on the universe. */
};

} // namespace core

#endif // OOP_INDIE_STUDIO_2019_CORE_HPP
