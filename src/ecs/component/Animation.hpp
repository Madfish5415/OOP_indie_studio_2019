/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <map>

class Animation {
  public:
    explicit Animation(const std::map<std::string, std::pair<size_t, size_t>> &animationRange);
    ~Animation();

  public:
    std::map<std::string, std::pair<size_t, size_t>> animationRange;
};

#endif /* !ANIMATION_HPP_ */
