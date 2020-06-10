/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SkinColor
*/

#include "SkinColor.hpp"

using namespace ecs::component;

SkinColor::SkinColor(const std::string &color) : color(color)
{
}

SkinColor::SkinColor(const SkinColor &skinColor) : color(skinColor.color)
{
}

SkinColor::~SkinColor() = default;
