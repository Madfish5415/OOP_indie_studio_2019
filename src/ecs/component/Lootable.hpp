/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Lootable
*/

#ifndef LOOTABLE_HPP_
#define LOOTABLE_HPP_

namespace ecs::component {

class Lootable {
  public:
    Lootable();
    Lootable(const Lootable& lootable);
    ~Lootable();
};

} // namespace ecs::component

#endif /* !LOOTABLE_HPP_ */
