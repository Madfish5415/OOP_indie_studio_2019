/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_IMAGE_HPP
#define OOP_INDIE_STUDIO_2019_IMAGE_HPP

#include <IVideoDriver.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Image : public ecs::System {
  public:
    explicit Image(irr::video::IVideoDriver *driver, WorldManager *worldManager);
    ~Image() override;

  public:
    void update() override;

  public:
    irr::video::IVideoDriver *driver;
};

}
#endif // OOP_INDIE_STUDIO_2019_IMAGE_HPP
