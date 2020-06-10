/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ExplosionDelay
*/

#ifndef EXPLOSIONDELAY_HPP_
#define EXPLOSIONDELAY_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class ExplosionDelay : public ecs::System {
    public:
      explicit ExplosionDelay(ecs::WorldManager* worldManager);
      ~ExplosionDelay();
    
    public:
      void update();

  private:
    irr::u32 time;
};
}

#endif /* !EXPLOSIONDELAY_HPP_ */
