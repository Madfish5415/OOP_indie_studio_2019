/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** TestsEntityManager.cpp
*/

#include <criterion/criterion.h>

#include "ecs/EntityManager.hpp"

Test(EntityManager, constructor01)
{
    ecs::EntityManager entityManager;

    cr_assert_eq(1, 1);
}

Test(EntityManager, createEntity01)
{
    ecs::EntityManager entityManager;

    try {
        entityManager.createEntity();
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, createEntity02)
{
    ecs::EntityManager entityManager;

    for (ecs::Entity entity = 0; entity < ecs::MAX_ENTITIES; entity++) {
        entityManager.createEntity();
    }

    try {
        entityManager.createEntity();
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, destroyEntity01)
{
    ecs::EntityManager entityManager;

    auto entity = entityManager.createEntity();

    try {
        entityManager.destroyEntity(entity);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, destroyEntity02)
{
    ecs::EntityManager entityManager;

    entityManager.createEntity();

    try {
        entityManager.destroyEntity(2000);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, setSignature01)
{
    ecs::EntityManager entityManager;

    auto entity = entityManager.createEntity();

    ecs::Signature sig;

    try {
        entityManager.setSignature(entity, sig);
        cr_assert_eq(1, 1);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, setSignature02)
{
    ecs::EntityManager entityManager;

    entityManager.createEntity();

    ecs::Signature sig;

    try {
        entityManager.setSignature(2000, sig);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, getSignature01)
{
    ecs::EntityManager entityManager;

    auto entity = entityManager.createEntity();

    ecs::Signature sig;

    entityManager.setSignature(entity, sig);
    try {
        if (entityManager.getSignature(entity) == sig)
            cr_assert_eq(1, 1);
        else
            cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 0);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}

Test(EntityManager, getSignature02)
{
    ecs::EntityManager entityManager;

    auto entity = entityManager.createEntity();

    ecs::Signature sig;

    entityManager.setSignature(entity, sig);

    try {
        entityManager.getSignature(2000);
        cr_assert_eq(1, 0);
    } catch (std::runtime_error &r) {
        cr_assert_eq(1, 1);
    } catch (std::exception &e) {
        cr_assert_eq(1, 0);
    }
}