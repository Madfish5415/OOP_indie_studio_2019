/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main.cpp
*/

#include "ecs/ComponentManager.hpp"
#include "ecs/EntityManager.hpp"

#include <iostream>

int main()
{
    ecs::ComponentManager componentManager;

    componentManager.RegisterComponent<int>();

    componentManager.AddComponent<int>(1, 1);

    componentManager.GetComponent<int>(1)++;

    std::cout << componentManager.GetComponent<int>(1) << std::endl;

    return 0;
}