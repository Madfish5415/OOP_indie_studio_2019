/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StatRender.cpp
*/

#include "StatRender.hpp"

using namespace ecs::component;

StatRender::StatRender(ecs::Entity owner, const std::string& type) : owner(owner), type(type)
{
}

StatRender::StatRender(const StatRender& statRender) = default;

StatRender::~StatRender() = default;
