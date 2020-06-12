/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StatRender.hpp
*/

#ifndef INDIESTUDIO_STATRENDER_COMP_HPP
#define INDIESTUDIO_STATRENDER_COMP_HPP

#include "../Def.hpp"

namespace ecs::component {

class StatRender {
  public:
    StatRender(ecs::Entity owner = 0, const std::string& type = "");
    StatRender(const StatRender& statRender);
    virtual ~StatRender();

  public:
    ecs::Entity owner;
    std::string type;
};

}

#endif // INDIESTUDIO_STATRENDER_COMP_HPP
