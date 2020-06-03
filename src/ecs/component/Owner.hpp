/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Owner
*/

#ifndef OWNER_HPP_
#define OWNER_HPP_

#include "../Def.hpp"

class Owner {
  public:
    explicit Owner(const ecs::Entity &ID);
    ~Owner();

  public:
    ecs::Entity entity;
};

#endif /* !OWNER_HPP_ */
