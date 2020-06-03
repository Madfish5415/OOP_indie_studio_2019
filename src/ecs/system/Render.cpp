/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include "../WorldManager.hpp"
#include "../component/Position.hpp"
#include "../component/Render.hpp"

#include <array>
#include <iostream>

static std::array<std::array<char, 13>, 13> map;

static void initMap()
{
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            map[i][j] = ' ';
        }
    }
    for (int i = 0; i < 13; i++) {
        map[0][i] = '#';
        map[i][0] = '#';
        map[12][i] = '#';
        map[i][12] = '#';
    }
}

using namespace ecs::system;

Render::Render(ecs::WorldManager* worldManager) : System(worldManager)
{
}

Render::~Render() = default;

void Render::update()
{
    initMap();

    for (const auto& entity : entities) {
        auto& position = worldManager->getComponent<ecs::component::Position>(entity);
        auto& render = worldManager->getComponent<ecs::component::Render>(entity);

        map[position.y][position.x] = render.sprite;
    }

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++)
            std::cout << map[i][j];
        std::cout << std::endl;
    }
}