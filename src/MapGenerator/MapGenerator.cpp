/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** MapGenerator.cpp
*/

#include <cstdlib>

#include "MapGenerator.hpp"

void MapGenerator::initMap()
{
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++)
            _map[i][j] = ' ';
    }
    for (int i = 0; i < 13; i++) {
        _map[0][i] = '#';
        _map[i][0] = '#';
        _map[12][i] = '#';
        _map[i][12] = '#';
    }
    for (int i = 2; i < 11; i += 2) {
        for (int j = 2; j < 11; j += 2)
            _map[i][j] = '#';
    }
    _map[1][1] = 'P';
    _map[1][11] = 'P';
    _map[11][1] = 'P';
    _map[11][11] = 'P';

    _map[1][2] = '0';
    _map[2][1] = '0';
    _map[1][10] = '0';
    _map[2][11] = '0';
    _map[10][1] = '0';
    _map[11][2] = '0';
    _map[10][11] = '0';
    _map[11][10] = '0';
}

int MapGenerator::countWallNumber(int x, int y)
{
    int nb = 0;

    if (_map[y][x] != '#')
        return 0;
    if (_map[y - 1][x] == '#')
        nb++;
    if (_map[y + 1][x] == '#')
        nb++;
    if (_map[y][x - 1] == '#')
        nb++;
    if (_map[y][x + 1] == '#')
        nb++;
    return nb;
}

void MapGenerator::putWall(int x, int y)
{
    int wallNbr = 0;
    
    if (std::rand() % 2 == 0)
        return;

    wallNbr = (countWallNumber(x - 1, y) + countWallNumber(x, y + 1) + countWallNumber(x + 1, y) + countWallNumber(x, y - 1));
    if (wallNbr < 2)
        _map[y][x] = '#';
}

void MapGenerator::generateMap()
{
    for (int x = 2, y = 3; x <= 10 && y <= 10; x += ((y == 10) ? 1 : 0), y += ((y == 10) ? 0 : 1)) {
        if (_map[y][x] == '#')
            continue;
        for (int x2 = x, y2 = y; x2 <= 10 && y2 >= 2; x2++, y2--) {
            putWall(x2, y2);
        }
    }
}

void MapGenerator::fillMap()
{
    for (int y = 1; y < 12; y++)
        for (int x = 1; x < 12; x++) {
            if (_map[y][x] == ' ')
                _map[y][x] = (std::rand() % 10 >= 8) ? ' ' : '*';
            if (_map[y][x] == '0')
                _map[y][x] = ' ';
        }
}

void MapGenerator::createMap()
{
    initMap();
    generateMap();
    fillMap();
}

std::array<std::array<char, 13>, 13> MapGenerator::getMap()
{
    return _map;
}
