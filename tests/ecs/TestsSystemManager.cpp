/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsSystemManager.cpp
*/

#include <criterion/criterion.h>

#include "ecs/SystemManager.hpp"
#include "SystemTest.hpp"

Test(SystemManager, constructor01)
{
    ecs::SystemManager systemManager;

    cr_assert_eq(1, 1);
}

Test(SystemManager, registerSystem01)
{
    ecs::SystemManager systemManager;

    try {
        systemManager.registerSystem<ecs::System>();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, registerSystem02)
{
    ecs::SystemManager systemManager;

    try {
        systemManager.registerSystem<ecs::System>();
        systemManager.registerSystem<ecs::System>();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, setSignature01)
{
    ecs::SystemManager systemManager;

    systemManager.registerSystem<ecs::System>();
    try {
        systemManager.setSignature<ecs::System>(ecs::Signature());
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, setSignature02)
{
    ecs::SystemManager systemManager;

    systemManager.registerSystem<ecs::System>();
    try {
        systemManager.setSignature<SystemTest>(ecs::Signature());
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, entityDestroyed01)
{
    ecs::SystemManager systemManager;

    systemManager.registerSystem<ecs::System>();
    try {
        systemManager.entityDestroyed(1);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, entitySignatureChanged01)
{
    ecs::SystemManager systemManager;

    systemManager.registerSystem<ecs::System>();
    try {
        systemManager.entitySignatureChanged(1, ecs::Signature());
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(SystemManager, entitySignatureChanged02)
{
    ecs::SystemManager systemManager;

    systemManager.registerSystem<ecs::System>();

    auto sig1 = ecs::Signature();
    auto sig2 = ecs::Signature();

    sig1.set(0, true);
    sig2.set(0, true);

    systemManager.setSignature<ecs::System>(sig1);
    systemManager.entitySignatureChanged(1, sig2);

    sig2.set(1, true);

    try {
        systemManager.entitySignatureChanged(1, sig2);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}