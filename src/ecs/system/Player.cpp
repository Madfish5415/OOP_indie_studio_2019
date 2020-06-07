/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player
*/

#include "Player.hpp"
#include "../WorldManager.hpp"
#include "../component/Render3d.hpp"
#include "../component/Player.hpp"
#include "../component/Motion.hpp"
#include "../component/Stats.hpp"
#include <iostream>

using namespace ecs::system;

Player::Player(ecs::WorldManager *worldManager) : System(worldManager)
{
}

Player::~Player() = default;

void Player::receiveKeyEvent(event::Key& event)
{
    float baseSpeed = 20;
    float multiplicator = baseSpeed / 4;

    for (const auto& entity : entities) {
        auto& node = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        auto& player = worldManager->getComponent<ecs::component::Player>(entity);
        auto& motion = worldManager->getComponent<ecs::component::Motion>(entity);
        auto& stats = worldManager->getComponent<ecs::component::Stats>(entity);

        if (event.keycode == player.keys["up"]) {
            if (event.pressed) {
                player.lastKey = "up";
                motion.direction.X = -1;
                motion.direction.Y = 0;
                motion.direction.Z = 0;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, -90, 0));
            } else {
                if (player.lastKey == "up")
                    motion.movementSpeed = 0;
            }
        } else if (event.keycode == player.keys["down"]) {
            if (event.pressed) {
                player.lastKey = "down";
                motion.direction.X = 1;
                motion.direction.Y = 0;
                motion.direction.Z = 0;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 90, 0));
            } else {
                if (player.lastKey == "down")
                    motion.movementSpeed = 0;
            }
        } else if (event.keycode == player.keys["left"]) {
            if (event.pressed) {
                player.lastKey = "left";
                motion.direction.X = 0;
                motion.direction.Y = 0;
                motion.direction.Z = -1;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 180, 0));
            } else {
                if (player.lastKey == "left")
                    motion.movementSpeed = 0;
            }
        } else if (event.keycode == player.keys["right"]) {
            if (event.pressed) {
                player.lastKey = "right";
                motion.direction.X = 0;
                motion.direction.Y = 0;
                motion.direction.Z = 1;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 0, 0));
                if (player.lastKey == "right")
                    motion.movementSpeed = 0;
            }
        } else if (event.keycode == player.keys["bomb"]) {
            //plant a bomb and do some magic
        }
    }
}
