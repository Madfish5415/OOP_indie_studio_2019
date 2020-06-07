/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsSystem.cpp
*/

#include <criterion/criterion.h>

#include "ecs/System.hpp"

Test(System, constructor01)
{
    ecs::System system;

    cr_assert_eq(1, 1);
}