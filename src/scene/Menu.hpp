/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Menu.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MENU_HPP
#define OOP_INDIE_STUDIO_2019_MENU_HPP

#include "../ecs/WorldManager.hpp"

namespace scene {

class Menu {
  public:
    Menu() = delete;
    ~Menu() = delete;

  public:
    static void init(ecs::WorldManager *worldManager);
    static void reset();
};

} // namespace scene

#endif // OOP_INDIE_STUDIO_2019_MENU_HPP
