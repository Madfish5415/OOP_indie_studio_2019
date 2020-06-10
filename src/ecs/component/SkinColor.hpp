/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SkinColor
*/

#ifndef SKINCOLOR_HPP_
#define SKINCOLOR_HPP_

#include <string>

namespace ecs::component {

class SkinColor {
    public:
        SkinColor(const std::string &color = "");
        SkinColor(const SkinColor &skinColor);
        ~SkinColor();

    public:
        const std::string &color;
};

}

#endif /* !SKINCOLOR_HPP_ */
