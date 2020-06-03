/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Size
*/

#ifndef SIZE_HPP_
#define SIZE_HPP_

#include <irrlicht.h>

class Size {
  public:
    explicit Size(const irr::core::vector3df &size);
    ~Size();

  public:
    irr::core::vector3df size;
};

#endif /* !SIZE_HPP_ */
