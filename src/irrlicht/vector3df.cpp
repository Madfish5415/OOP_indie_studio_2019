/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** irrlicht.cpp
*/

#include <irrlicht.h>

irr::core::vector3df operator*(const irr::core::vector3df& vec, irr::f32 value) {
    irr::core::vector3df tmp;
    tmp.X = vec.X * value;
    tmp.Y = vec.Y * value;
    tmp.Z = vec.Z * value;
    return tmp;
}