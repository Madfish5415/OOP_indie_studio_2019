/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Render.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_RENDER_HPP
#define OOP_INDIE_STUDIO_2019_RENDER_HPP

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Render : public ecs::System {
    public:
        explicit Render(WorldManager *worldManager);
        ~Render();

    public:
        void update();

    public:
        irr::scene::ISceneManager *smgr;
        irr::gui::IGUIEnvironment *gui;
};
}

#endif /* !RENDER_HPP_ */
