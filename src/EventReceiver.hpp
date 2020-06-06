/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EventReceiver
*/

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

namespace ecs {
class Universe;
}

#include <irrlicht.h>

/**
 * @file EventReceiver.hpp
 * @brief EventReceiver Class
 * @author Lucas.M
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @class EventReceiver
 * @brief Daughter class that collects events from the Irrlicht library.
 */
class EventReceiver : public irr::IEventReceiver {
  public:
    /**
     * @brief Constructor
     * Store a pointer on the universe.
     * @param universe : Pointer on Universe.
     */
    explicit EventReceiver(ecs::Universe *universe);

    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~EventReceiver() override;

    /**
     * @brief OnEvent method
     * This method was called by Irrlicht when it receive an event
     * @param event : Irrlicht event.
     * @return True if the event is totally handled and False otherwise.
     */
    bool OnEvent(const irr::SEvent &event) override;

  private:
    ecs::Universe *_universe; /** < Pointer on universe for having access to all the WorldManager */
};

#endif /* !EVENTRECEIVER_HPP_ */
