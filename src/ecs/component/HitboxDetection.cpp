/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** HitboxDetection
*/

#include "HitboxDetection.hpp"

HitboxDetection::HitboxDetection(const std::vector<irr::core::line3df> &rays)
{
    _rays = rays;
}

HitboxDetection::~HitboxDetection()
{
}
