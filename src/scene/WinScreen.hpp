/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinScreen
*/

#ifndef WINSCREEN_HPP_
#define WINSCREEN_HPP_

#include "irrlicht.h"

#include "../ecs/WorldManager.hpp"

namespace scene {

class WinScreen {
    public:
        WinScreen() = delete;
        ~WinScreen() = delete;

    public:
        static void init(ecs::Universe* universe);
        static void destroy(ecs::Universe* universe);
    
    public:
    static std::vector<ecs::Entity> images;
};

namespace winScreen {
    const std::string BACKGROUND = "assets/img/win-screen/background.png";
}
}
#endif /* !WINSCREEN_HPP_ */
