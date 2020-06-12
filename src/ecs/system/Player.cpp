/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player
*/

#include "Player.hpp"

#include "../../scene/Bomberman.hpp"
#include "../WorldManager.hpp"
#include "../component/Animation.hpp"
#include "../component/BombStats.hpp"
#include "../component/BombTimer.hpp"
#include "../component/Motion.hpp"
#include "../component/Owner.hpp"
#include "../component/Player.hpp"
#include "../component/PlayerIndex.hpp"
#include "../component/Render3d.hpp"
#include "../component/Stats.hpp"

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
        auto& animation = worldManager->getComponent<ecs::component::Animation>(entity);

        if (event.keycode == player.keys["up"]) {
            if (event.pressed) {
                player.lastKey = "up";
                motion.direction.X = -1;
                motion.direction.Y = 0;
                motion.direction.Z = 0;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, -90, 0));
                animation.currentAnimation = "WALKING";
            } else {
                if (player.lastKey == "up") {
                    motion.movementSpeed = 0;
                    animation.currentAnimation = "IDLE";
                }
            }
        } else if (event.keycode == player.keys["down"]) {
            if (event.pressed) {
                player.lastKey = "down";
                motion.direction.X = 1;
                motion.direction.Y = 0;
                motion.direction.Z = 0;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 90, 0));
                animation.currentAnimation = "WALKING";
            } else {
                if (player.lastKey == "down") {
                    motion.movementSpeed = 0;
                    animation.currentAnimation = "IDLE";
                }
            }
        } else if (event.keycode == player.keys["left"]) {
            if (event.pressed) {
                player.lastKey = "left";
                motion.direction.X = 0;
                motion.direction.Y = 0;
                motion.direction.Z = -1;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 180, 0));
                animation.currentAnimation = "WALKING";
            } else {
                if (player.lastKey == "left") {
                    motion.movementSpeed = 0;
                    animation.currentAnimation = "IDLE";
                }
            }
        } else if (event.keycode == player.keys["right"]) {
            if (event.pressed) {
                player.lastKey = "right";
                motion.direction.X = 0;
                motion.direction.Y = 0;
                motion.direction.Z = 1;
                motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
                node->setRotation(irr::core::vector3df(0, 0, 0));
                animation.currentAnimation = "WALKING";
            } else {
                if (player.lastKey == "right") {
                    motion.movementSpeed = 0;
                    animation.currentAnimation = "IDLE";
                }
            }
        } else if (event.keycode == player.keys["bomb"] && event.pressed) {
            std::vector<ecs::Entity> bombs = worldManager->getEntities<ecs::component::BombStats,
                ecs::component::BombTimer, ecs::component::Owner>();
            int bombNbr = 0;

            for (const auto& bomb : bombs) {
                auto& owner = worldManager->getComponent<ecs::component::Owner>(bomb);
                if (owner.entity == entity)
                    bombNbr++;
            }

            auto& stat = worldManager->getComponent<ecs::component::Stats>(entity);
            auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);
            auto& playerIndex = worldManager->getComponent<ecs::component::PlayerIndex>(entity);

            if (bombNbr < stat.maxBomb && !alreadyExist(render3d.node->getPosition())) {
                scene::Bomberman::createBomb(worldManager, entity, stat.bombRadius, stat.wallPass, render3d.node->getPosition(), playerIndex.idx);
            }
        }
    }
}

bool Player::alreadyExist(const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> bombs = worldManager->getEntities<ecs::component::BombTimer, ecs::component::BombStats, ecs::component::Owner>();

    for (const auto& entity : bombs) {
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        auto newPos = pos;
        newPos.X = static_cast<irr::f32>(static_cast<int>(pos.X / 10.f) * 10 + 5);
        newPos.Y = 4;
        newPos.Z = static_cast<irr::f32>(static_cast<int>(pos.Z / 10.f) * 10 + 5);
        if (render3d.node->getPosition() == newPos) {
            return true;
        }
    }
    return false;
}
