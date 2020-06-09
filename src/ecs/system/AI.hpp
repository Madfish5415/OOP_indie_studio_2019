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
    AI(ecs::WorldManager* worldManager);
    ~AI();

  public:
    void update();
};
}
#endif // INDIESTUDIO_AI_HPP
