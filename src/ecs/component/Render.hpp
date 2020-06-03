/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.hpp
*/

#ifndef INDIESTUDIO_COMP_RENDER_HPP
#define INDIESTUDIO_COMP_RENDER_HPP

/**
 * @file Render.hpp
 * @brief Render Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::component
 */
namespace ecs::component {

/**
 * @class Render
 * @brief Description to the entity that informs that it can be displayed.
 */
class Render {
  public:
    /**
     * @brief Constructor
     * Constructor of Render Class.
     * @param sprite : Sprite of the entity.
     */
    Render(const char& sprite = 'P');
    /**
     * @brief Copy Constructor
     * Copy Constructor of Render Class.
     */
    Render(const Render& render);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Render();

  public:
    char sprite; /**< Sprite of the entity. */
};

} // namespace ecs::component

#endif // INDIESTUDIO_COMP_RENDER_HPP
