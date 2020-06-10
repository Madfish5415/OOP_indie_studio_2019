/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerRender.cpp
*/

#include "TimerRender.hpp"

using namespace ecs::component;

TimerRender::TimerRender(ecs::Entity owner, size_t position) : owner(owner), position(position)
{
}

TimerRender::TimerRender(const TimerRender& timerRender) = default;

TimerRender::~TimerRender() = default;
