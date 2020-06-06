/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IComponentArray.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP
#define OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP

#include "Def.hpp"

/**
 * @file IComponentArray.hpp
 * @brief IComponentArray Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class IComponentArray
 * @brief Interface of an array of components.
 */
class IComponentArray {
  public:
    /**
     * @brief Destructor
     * Pure virtual destructor because it's an inferface.
     */
    virtual ~IComponentArray() = default;

  public:
    /**
     * @brief entityDestroyed method
     * Pure virtual method because it's an inferface.
     */
    virtual void entityDestroyed(Entity entity) = 0;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_ICOMPONENTARRAY_HPP