/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <string>
#include <unordered_map>

/**
 * @file Animation.hpp
 * @brief Animation Class
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
 * @class Animation
 * @brief Allow entity to have animation.
 */
class Animation {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param animationRange : A list of range assign to a animation name.
     */
    Animation(std::unordered_map<std::string, std::pair<size_t, size_t>> animationRange =
                  std::unordered_map<std::string, std::pair<size_t, size_t>>());
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param animation : Element to be copied.
     */
    Animation(const Animation& animation);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Animation();

  public:
    std::unordered_map<std::string, std::pair<size_t, size_t>> animationRange; /** < The animation range list. */
    std::string currentAnimation; /** < The currently played animation. */
};

} // namespace ecs::component

#endif /* !ANIMATION_HPP_ */
