/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <unordered_map>
#include <string>

namespace ecs::component {

class Animation {
  public:
    explicit Animation(std::unordered_map<std::string, std::pair<size_t, size_t>> animationRange  = std::unordered_map<std::string, std::pair<size_t, size_t>>());
    Animation(const Animation& Animation);
    ~Animation();

  public:
    std::unordered_map<std::string, std::pair<size_t, size_t>> animationRange;
    std::string currentAnimation;
};

} // namespace ecs::component

#endif /* !ANIMATION_HPP_ */
