/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main.cpp
*/

#include <iostream>

#include "ecs/WorldManager.hpp"

int main()
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();

    ecs::Entity entity1 = worldManager.createEntity();

    worldManager.addComponent<int>(entity1, 1);

    worldManager.getComponent<int>(entity1)++;

    std::cout << worldManager.getComponent<int>(entity1) << std::endl;

    return 0;
}