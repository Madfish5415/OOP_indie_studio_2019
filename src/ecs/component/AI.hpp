/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#ifndef OOP_INDIE_STUDIO_2019_AI_HPP_
#define OOP_INDIE_STUDIO_2019_AI_HPP_

#include <irrlicht.h>

#include <string>

/**
 * @file AI.hpp
 * @brief AI Class
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
 * @class AI
 * @brief Describes an entity as being controlled by an AI.
 */
class AI {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    AI();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param ai : Element to be copied.
     */
    AI(const AI& ai);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~AI();

  public:
    std::string lastDirection; /** < The last direction choosen by the AI system. */
    irr::core::vector3d<irr::f32> lastPos; /** < The last pos choosen by the AI system. */
    irr::core::vector3d<irr::f32> lastEscape;  /** < The last pos choosen by the escape method. */
    std::string lastChoice; /** < The last direction choosen by the escape method. */
};

} // namespace ecs::component

#endif /* !OOP_INDIE_STUDIO_2019_AI_HPP_ */
