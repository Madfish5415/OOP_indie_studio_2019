/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** StatRender.hpp
*/

#ifndef INDIESTUDIO_STATRENDER_HPP
#define INDIESTUDIO_STATRENDER_HPP

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class StatRender : public System {
  public:
    explicit StatRender(WorldManager *worldManager);
    ~StatRender() override;

  public:
    void update() override;
};

} // namespace ecs::system

#endif // INDIESTUDIO_STATRENDER_HPP
