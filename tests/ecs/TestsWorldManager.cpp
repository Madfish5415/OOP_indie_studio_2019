/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsWorldManager.cpp
*/

#include <criterion/criterion.h>

#include "ecs/WorldManager.hpp"

Test(WorldManager, constructor1)
{
    ecs::WorldManager worldManager;

    cr_assert_eq(1, 1);
}

Test(WorldManager, createEntity01)
{
    ecs::WorldManager worldManager;

    try {
        worldManager.createEntity();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, createEntity02)
{
    ecs::WorldManager worldManager;

    for (ecs::Entity entity = 0; entity < ecs::MAX_ENTITIES; entity++) {
        worldManager.createEntity();
    }

    try {
        worldManager.createEntity();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, destroyEntity01)
{
    ecs::WorldManager worldManager;

    auto entity = worldManager.createEntity();

    try {
        worldManager.destroyEntity(entity);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, destroyEntity02)
{
    ecs::WorldManager worldManager;

    worldManager.createEntity();

    try {
        worldManager.destroyEntity(2000);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, registerComponent01)
{
    ecs::WorldManager worldManager;

    try {
        worldManager.registerComponent<int>();
        worldManager.registerComponent<double>();
        worldManager.registerComponent<float>();
        worldManager.registerComponent<char>();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, registerComponent02)
{
    ecs::WorldManager worldManager;

    try {
        worldManager.registerComponent<int>();
        worldManager.registerComponent<double>();
        worldManager.registerComponent<float>();
        worldManager.registerComponent<char>();
        worldManager.registerComponent<int>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &e) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, addComponent01)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    try {
        worldManager.addComponent<int>(1, 2);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, addComponent02)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    try {
        worldManager.addComponent<int>(1, 2);
        worldManager.addComponent<int>(1, 2);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, removeComponent01)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    worldManager.addComponent<int>(1, 2);

    try {
        worldManager.removeComponent<int>(1);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, removeComponent02)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    worldManager.addComponent<int>(1, 2);

    try {
        worldManager.removeComponent<float>(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, getComponent01)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    worldManager.addComponent<int>(1, 2);

    try {
        if (worldManager.getComponent<int>(1) == 2)
            cr_assert_eq(1, 1);
        else
            cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, getComponent02)
{
    ecs::WorldManager worldManager;

    worldManager.registerComponent<int>();
    worldManager.registerComponent<double>();
    worldManager.registerComponent<float>();
    worldManager.registerComponent<char>();

    worldManager.addComponent<int>(1, 2);

    try {
        worldManager.getComponent<float>(1);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, registerSystem01)
{
    ecs::WorldManager worldManager;

    try {
        worldManager.registerSystem<ecs::System>();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, registerSystem02)
{
    ecs::WorldManager worldManager;

    try {
        worldManager.registerSystem<ecs::System>();
        worldManager.registerSystem<ecs::System>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(WorldManager, setSignature01)
{
    ecs::WorldManager worldManager;

    worldManager.registerSystem<ecs::System>();
    try {
        worldManager.setSystemSignature<ecs::System>(ecs::Signature());
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}