/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main.cpp
*/

#include <iostream>

#include "core/Core.hpp"
#include "ecs/Universe.hpp"
#include "ecs/WorldManager.hpp"

int main()
{
    core::Core core;

    core.init();
    core.run();
}