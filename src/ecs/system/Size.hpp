/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Size
*/

#ifndef OOP_INDIE_STUDIO_2019_SIZE_HPP_
#define OOP_INDIE_STUDIO_2019_SIZE_HPP_

#include <irrlicht.h>

#include "../System.hpp"
#include "../WorldManager.hpp"

namespace ecs::system {

class Size : public ecs::System {
  public:
    explicit Size(WorldManager *worldManager);
    ~Size() override;

  public:
    void update() override;
};
} // namespace ecs::system

#endif /* !OOP_INDIE_STUDIO_2019_SIZE_HPP_ */
