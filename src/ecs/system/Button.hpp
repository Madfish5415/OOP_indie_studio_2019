/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Button.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_BUTTON_HPP
#define OOP_INDIE_STUDIO_2019_BUTTON_HPP

#include <irrlicht.h>

#include "../WorldManager.hpp"

namespace ecs::system {

class Button : public ecs::System {
  public:
    explicit Button(ecs::WorldManager *worldManager);
    ~Button() override;

  public:
    void update() override;

  public:
    irr::gui::ICursorControl *mouse;
    irr::video::IVideoDriver *driver;
};

} // namespace ecs::system

#endif // OOP_INDIE_STUDIO_2019_BUTTON_HPP
