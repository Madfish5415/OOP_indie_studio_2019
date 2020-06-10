/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** DrawScreen
*/

#ifndef DRAWSCREEN_HPP_
#define DRAWSCREEN_HPP_

#include "irrlicht.h"

#include "../ecs/WorldManager.hpp"

namespace scene {

class DrawScreen {
    public:
        DrawScreen() = delete;
        ~DrawScreen() = delete;

    public:
        static void init(ecs::Universe* universe);
        static void destroy(ecs::Universe* universe);

    public:
        static std::vector<ecs::Entity> images;
};

namespace drawScreen {
    const std::string BACKGROUND = "assets/img/win-screen/draw/draw.png";
}

}

#endif /* !DRAWSCREEN_HPP_ */
