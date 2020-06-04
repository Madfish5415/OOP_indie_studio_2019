/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** def.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_DEF_HPP
#define OOP_INDIE_STUDIO_2019_DEF_HPP

#include <bitset>

/**
 * @file Def.hpp
 * @brief Def File
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

using Entity = unsigned int; /** < Using Entity as unsigned int.*/
const Entity MAX_ENTITIES = 1000; /** < Defined the max number of entities for the project.*/

using ComponentType = unsigned int; /** < Using ComponentType as unsigned int.*/
const ComponentType MAX_COMPONENTS = 32; /** < Defined the max number of components for an entity for the project.*/

using Signature = std::bitset<MAX_COMPONENTS>; /** < Using Signature as std::bitset<MAX_COMPONENTS>.*/

}


#endif // OOP_INDIE_STUDIO_2019_DEF_HPP