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
    ~ExplosionDelay() override;

  public:
    void update() override;

  private:
    irr::u32 time;
};

} // namespace ecs::system

#endif /* !EXPLOSIONDELAY_HPP_ */
