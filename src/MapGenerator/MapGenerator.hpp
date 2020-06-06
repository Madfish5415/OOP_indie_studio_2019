/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** MapGenerator.hpp
*/

#ifndef HELLOIRR_MAPGENERATOR_HPP
#define HELLOIRR_MAPGENERATOR_HPP

#include <array>

class MapGenerator {
  public:
    void initMap();
    int countWallNumber(int x, int y);
    void putWall(int x, int y);
    void generateMap();
    void fillMap();
    void createMap();
    std::array<std::array<char, 13>, 13> getMap();
  private:
    std::array<std::array<char, 13>, 13> _map;

};

#endif // HELLOIRR_MAPGENERATOR_HPP
