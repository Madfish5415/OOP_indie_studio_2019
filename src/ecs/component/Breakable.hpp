/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Breakable
*/

#ifndef INDIESTUDIO_BREAKABLE_HPP
#define INDIESTUDIO_BREAKABLE_HPP

namespace ecs::component {

class Breakable {
  public:
    Breakable();
    Breakable(const Breakable& breakable);
    virtual ~Breakable();
};

} // namespace ecs::component

#endif // INDIESTUDIO_BREAKABLE_HPP
