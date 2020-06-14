/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ToDelete
*/

#ifndef INDIESTUDIO_TODELETE_HPP
#define INDIESTUDIO_TODELETE_HPP

/**
 * @file ToDelete.hpp
 * @brief ToDelete Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace ecs
 * @namespace component
 */
namespace ecs::component {

/**
 * @class ToDelete
 * @brief Add entity to deletion list.
 */
class ToDelete {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     */
    ToDelete();
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param toDelete : Element to be copied.
     */
    ToDelete(const ToDelete& toDelete);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~ToDelete();
};

} // namespace ecs::component

#endif // INDIESTUDIO_TODELETE_HPP
