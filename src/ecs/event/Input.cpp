/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Input.cpp
*/

#include "Input.hpp"

#include <utility>

using namespace ecs::event;

Input::Input(std::string input) : input(std::move(input))
{
}

Input::~Input() = default;
