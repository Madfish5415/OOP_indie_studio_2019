/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsComponentManager.cpp
*/

#include <criterion/criterion.h>

#include "ecs/ComponentManager.hpp"

Test(ComponentManager, constructor01)
{
    ecs::ComponentManager componentManager;

    cr_assert_eq(1, 1);
}

Test(ComponentManager, registerComponent01)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.registerComponent<int>();
        componentManager.registerComponent<double>();
        componentManager.registerComponent<float>();
        componentManager.registerComponent<char>();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, registerComponent02)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.registerComponent<int>();
        componentManager.registerComponent<double>();
        componentManager.registerComponent<float>();
        componentManager.registerComponent<char>();
        componentManager.registerComponent<int>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponentType01)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    try {
        if (componentManager.getComponentType<int>() == 0 && componentManager.getComponentType<double>() == 1 &&
            componentManager.getComponentType<float>() == 2 && componentManager.getComponentType<char>() == 3)
            cr_assert_eq(1, 1);
        else
            cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponentType02)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.getComponentType<int>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponentType03)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.getComponentType<double>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponentType04)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.getComponentType<float>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponentType05)
{
    ecs::ComponentManager componentManager;

    try {
        componentManager.getComponentType<char>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, addComponent01)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    try {
        componentManager.addComponent<int>(1, 2);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, addComponent02)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    try {
        componentManager.addComponent<int>(1, 2);
        componentManager.addComponent<int>(1, 2);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, removeComponent01)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    componentManager.addComponent<int>(1, 2);

    try {
        componentManager.removeComponent<int>(1);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, removeComponent02)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    componentManager.addComponent<int>(1, 2);

    try {
        componentManager.removeComponent<float>(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponent01)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    componentManager.addComponent<int>(1, 2);

    try {
        if (componentManager.getComponent<int>(1) == 2)
            cr_assert_eq(1, 1);
        else
            cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, getComponent02)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    componentManager.addComponent<int>(1, 2);

    try {
        componentManager.getComponent<float>(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(ComponentManager, entityDestroyed01)
{
    ecs::ComponentManager componentManager;

    componentManager.registerComponent<int>();
    componentManager.registerComponent<double>();
    componentManager.registerComponent<float>();
    componentManager.registerComponent<char>();

    componentManager.addComponent<int>(1, 2);

    componentManager.entityDestroyed(1);
    try {
        componentManager.removeComponent<int>(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}