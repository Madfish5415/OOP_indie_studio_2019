/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** HitboxDetection
*/

#include "HitboxDetection.hpp"

#include <utility>

HitboxDetection::HitboxDetection(const std::vector<irr::core::line3df>& rays) : rays(rays)
{
}

HitboxDetection::~HitboxDetection() = default;
