/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.hpp
*/

#ifndef INDIESTUDIO_RENDER_HPP
#define INDIESTUDIO_RENDER_HPP

#include "../System.hpp"

namespace ecs::system {

class Render : public System {
  public:
    explicit Render(WorldManager *worldManager);
    ~Render() override;

  public:
    void update() override;
};

}

#endif // INDIESTUDIO_RENDER_HPP
