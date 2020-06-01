/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LookingView
*/

#ifndef LOOKINGVIEW_HPP_
#define LOOKINGVIEW_HPP_

#include <irrlicht.h>

class LookingView {
    public:
        LookingView(const irr::core::vector3df &direction);
        ~LookingView();

    public:
        irr::core::vector3df _direction;
};

#endif /* !LOOKINGVIEW_HPP_ */
