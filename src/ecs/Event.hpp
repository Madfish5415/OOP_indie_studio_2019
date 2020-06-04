/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_EVENT_HPP
#define OOP_INDIE_STUDIO_2019_EVENT_HPP

#include <unordered_map>
#include <utility>

/**
 * @file Event.hpp
 * @brief Event Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

/**
 * @class Event
 * @brief Default class of an event
 */
class Event {
  public:
    /**
     * @brief Constructor
     * Constructor of Event Class.
     */
    Event() = default;
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    virtual ~Event() = default;
};

} // namespace ecs

#endif // OOP_INDIE_STUDIO_2019_EVENT_HPP