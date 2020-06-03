/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.cpp
*/

#include "Render.hpp"

using namespace ecs::component;

Render::Render(const char& sprite) : sprite(sprite)
{
}

Render::Render(const Render& render)
{
    sprite = render.sprite;
}

Render::~Render() = default;
