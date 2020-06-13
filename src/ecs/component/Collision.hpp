/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Collision
*/

#ifndef COLLISON_HPP_
#define COLLISON_HPP_

namespace ecs::component {

class Collision {
  public:
    Collision();
    Collision(const Collision& collision);
    virtual ~Collision();
};

} // namespace ecs::component

#endif /* !ANIMATION_HPP_ */
