/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI.hpp
*/

#ifndef INDIESTUDIO_AI_HPP
#define INDIESTUDIO_AI_HPP

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class AI : public ecs::System {
  public:
    explicit AI(ecs::WorldManager* worldManager);
    ~AI() override;

  public:
    void update() override;

  private:
    void plantBomb(ecs::Entity ai, ecs::WorldManager* worldManager);
    bool alreadyExist(const irr::core::vector3d<irr::f32>& pos);
};

} // namespace ecs::system

#endif // INDIESTUDIO_AI_HPP
