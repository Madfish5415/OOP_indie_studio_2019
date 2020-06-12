/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MapGenerator.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP
#define OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP

#include <array>

class MapGenerator {
  public:
    MapGenerator();
    ~MapGenerator();

  private:
    void initMap();
    int countWallNumber(int x, int y);
    void putWall(int x, int y);
    void generateMap();
    void fillMap();

  public:
    void createMap();
    std::array<std::array<char, 13>, 13> getMap();

  private:
    std::array<std::array<char, 13>, 13> _map {};
};

#endif // OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP