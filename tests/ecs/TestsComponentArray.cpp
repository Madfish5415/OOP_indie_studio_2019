/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsComponentArray.cpp
*/

#include <criterion/criterion.h>

#include "ecs/ComponentArray.hpp"

Test(ComponentArray, constructor01)
{
    ecs::ComponentArray<int> componentArray;

    cr_assert_eq(1, 1);
}

Test(ComponentArray, insert01)
{
    ecs::ComponentArray<int> componentArray;

    try {
        componentArray.insert(1, 2);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, insert02)
{
    ecs::ComponentArray<int> componentArray;

    try {
        componentArray.insert(1, 2);
        componentArray.insert(1, 2);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, remove01)
{
    ecs::ComponentArray<int> componentArray;

    componentArray.insert(1, 2);

    try {
        componentArray.remove(1);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, remove02)
{
    ecs::ComponentArray<int> componentArray;

    try {
        componentArray.remove(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, get01)
{
    ecs::ComponentArray<int> componentArray;

    componentArray.insert(1, 2);

    try {
        if (componentArray.get(1) == 2)
            cr_assert_eq(1, 1);
        else
            cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, get02)
{
    ecs::ComponentArray<int> componentArray;

    componentArray.insert(1, 2);

    try {
        componentArray.get(2);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentArray, entityDestroyed01)
{
    ecs::ComponentArray<int> componentArray;

    componentArray.insert(1, 2);

    componentArray.entityDestroyed(1);
    try {
        componentArray.remove(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}