/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** def.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_DEF_HPP
#define OOP_INDIE_STUDIO_2019_DEF_HPP

#include <bitset>

namespace ecs {

using Entity = unsigned int;
const Entity MAX_ENTITIES = 1000;

using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

}


#endif // OOP_INDIE_STUDIO_2019_DEF_HPP
