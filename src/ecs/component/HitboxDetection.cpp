/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** HitboxDetection
*/

#include "HitboxDetection.hpp"

#include <utility>

using namespace ecs::component;

HitboxDetection::HitboxDetection(const std::vector<irr::core::line3df>& rays) : rays(rays)
{
}
HitboxDetection::HitboxDetection(const HitboxDetection& transform) = default;

HitboxDetection::~HitboxDetection() = default;
