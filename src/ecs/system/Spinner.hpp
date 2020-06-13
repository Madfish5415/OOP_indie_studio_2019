/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Spinner.hpp
*/

#ifndef INDIESTUDIO_SPINNER_HPP
#define INDIESTUDIO_SPINNER_HPP

#include <irrlicht.h>

#include "../System.hpp"

namespace ecs::system {

class Spinner : public System {
  public:
    Spinner(WorldManager *worldManager);
    ~Spinner() override;

  public:
    void update() override;

  private:
    irr::u32 time;
};

} // namespace ecs::system

#endif // INDIESTUDIO_SPINNER_HPP
