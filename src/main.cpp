/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main.cpp
*/

#include <iostream>

#include "GameLoop.hpp"

int main()
{
    GameLoop gameLoop;

    gameLoop.init();
    gameLoop.run();

    return 0;
}