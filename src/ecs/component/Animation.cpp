/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#include "Animation.hpp"

#include <utility>

using namespace ecs::component;

Animation::Animation(std::unordered_map<std::string, std::pair<size_t, size_t>> animationRange)
    : animationRange(std::move(animationRange)), currentAnimation("")
{
}
Animation::Animation(const Animation &Animation) = default;

Animation::~Animation() = default;
