/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ToDelete
*/

#ifndef INDIESTUDIO_TODELETE_HPP
#define INDIESTUDIO_TODELETE_HPP

namespace ecs::component {

class ToDelete {
  public:
    ToDelete();
    ToDelete(const ToDelete& toDelete);
    virtual ~ToDelete();
};

} // namespace ecs::component

#endif // INDIESTUDIO_TODELETE_HPP
