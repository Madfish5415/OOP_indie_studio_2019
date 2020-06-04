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

class EventReceiver : public irr::IEventReceiver {
    public:
        EventReceiver(ecs::Universe *universe)
        {
            _universe = universe;
        }

        ~EventReceiver() = default;

        bool OnEvent(const irr::SEvent& event) override;

    private:
        ecs::Universe *_universe;
};

#endif /* !EVENTRECEIVER_HPP_ */
