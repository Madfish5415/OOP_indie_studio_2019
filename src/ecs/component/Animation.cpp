/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#include "Animation.hpp"

using namespace ecs::component;

Animation::Animation(const std::unordered_map<std::string, std::pair<size_t, size_t>> &animationRange)
    : animationRange(animationRange), currentAnimation(nullptr)
{
}

Animation::~Animation() = default;
