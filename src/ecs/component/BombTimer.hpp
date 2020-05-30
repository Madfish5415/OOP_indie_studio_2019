/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#ifndef BOMBTIMER_HPP_
#define BOMBTIMER_HPP_

#include <irrlicht.h>

class BombTimer {
    public:
        BombTimer(const irr::u32 &duration);
        ~BombTimer();

    public:
        irr::u32 _timerStart;
        irr::u32 _duration;
};

#endif /* !BOMBTIMER_HPP_ */
