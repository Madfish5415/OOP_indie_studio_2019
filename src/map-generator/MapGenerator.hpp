/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MapGenerator.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP
#define OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP

#include <array>

/**
 * @file MapGenerator.hpp
 * @brief MapGenerator Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @class MapGenerator
 * @brief This class handle the procedural generation of a map.
 */
class MapGenerator {
  public:
    /**
     * @brief Constructor
     * Generate a map randomly.
     */
    MapGenerator();
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~MapGenerator();

  private:
    /**
     * @brief initMap method
     * This method create a base map with wall and players positions.
     */
    void initMap();
    /**
     * @brief countWallNumber method
     * This method count the number of wall near a position.
     * @param x : The abscissa.
     * @param y : The ordinate.
     * @return The number of wall near the position.
     */
    int countWallNumber(int x, int y);
    /**
     * @brief putWall method
     * This method uses an algorithm to place a wall at a given position.
     * @param x : The abscissa.
     * @param y : The ordinate.
     */
    void putWall(int x, int y);
    /**
     * @brief generateMap method
     * This method allows to generate all the walls of the map in a procedural way.
     */
    void generateMap();
    /**
     * @brief fillMap method
     * This method allows you to generate all the boxes of the map in a procedural way.
     */
    void fillMap();

  public:
    /**
     * @brief createMap method
     * This method calls all private map generation methods.
     */
    void createMap();
    /**
     * @brief getMap method
     * This method returns the map that is currently stored.
     * @return The map currently stored.
     */
    std::array<std::array<char, 13>, 13> getMap();

  private:
    std::array<std::array<char, 13>, 13> _map {}; /** < The currently stored map. */
};

#endif // OOP_INDIE_STUDIO_2019_MAPGENERATOR_HPP