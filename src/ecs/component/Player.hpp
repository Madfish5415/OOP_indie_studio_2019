/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_PLAYER_HPP
#define OOP_INDIE_STUDIO_2019_PLAYER_HPP

#include <string>

namespace ecs::component {

class Player {
  public:
    Player(char left = 'Q', char right = 'D', char up = 'Z', char down = 'S',
        char bomb = 'B');
    Player(const Player& player);
    ~Player();

  public:
    char left;
    char right;
    char up;
    char down;
    char bomb;
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_PLAYER_HPP
