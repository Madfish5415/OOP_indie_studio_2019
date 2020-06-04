/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** EventReceiver.cpp
*/
#include "EventReceiver.hpp"

EventReceiver::EventReceiver(ecs::Universe *universe) : _universe(universe)
{
}

EventReceiver::~EventReceiver() = default;

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
    (void) event;
    return false;
}
