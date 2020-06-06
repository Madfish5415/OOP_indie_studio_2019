/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Owner
*/

#ifndef OWNER_HPP_
#define OWNER_HPP_

#include "../Def.hpp"

namespace ecs::component {

class Owner {
  public:
    explicit Owner(const ecs::Entity &ID = 0);
    Owner(const Owner &owner);
    ~Owner();

  public:
    ecs::Entity entity;
};

} // namespace ecs::component

#endif /* !OWNER_HPP_ */
