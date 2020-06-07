/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Blink.hpp
*/

#ifndef INDIESTUDIO_BLINK_HPP
#define INDIESTUDIO_BLINK_HPP

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Blink : public ecs::System {
  public:
    explicit Blink(ecs::WorldManager* worldManager);
    ~Blink();

  public:
    void update();

  private:
    irr::u32 time;
};

} // namespace ecs::system

#endif // INDIESTUDIO_BLINK_HPP
