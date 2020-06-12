/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI.cpp
*/

#include "../component/AI.hpp"

#include <irrlicht.h>

#include <iostream>

#include "../../scene/Bomberman.hpp"
#include "../component/Animation.hpp"
#include "../component/BombStats.hpp"
#include "../component/BombTimer.hpp"
#include "../component/Breakable.hpp"
#include "../component/Motion.hpp"
#include "../component/Owner.hpp"
#include "../component/Particle.hpp"
#include "../component/Player.hpp"
#include "../component/PlayerIndex.hpp"
#include "../component/Render3d.hpp"
#include "../component/Stats.hpp"
#include "../component/Unbreakable.hpp"
#include "../system/Player.hpp"
#include "AI.hpp"

using namespace ecs::system;

AI::AI(ecs::WorldManager* worldManager) : ecs::System(worldManager)
{
}

AI::~AI() = default;

bool AI::alreadyExist(const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> bombs =
        worldManager->getEntities<ecs::component::BombTimer, ecs::component::BombStats, ecs::component::Owner>();

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

void AI::plantBomb(ecs::Entity ai, ecs::WorldManager* worldManager)
{
    std::vector<ecs::Entity> bombs =
        worldManager->getEntities<ecs::component::BombStats, ecs::component::BombTimer, ecs::component::Owner>();
    int bombNbr = 0;

    for (const auto& bomb : bombs) {
        auto& owner = worldManager->getComponent<ecs::component::Owner>(bomb);
        if (owner.entity == ai)
            bombNbr++;
    }

    auto& stat = worldManager->getComponent<ecs::component::Stats>(ai);
    auto& playerIndex = worldManager->getComponent<ecs::component::PlayerIndex>(ai);
    auto pos = worldManager->getComponent<ecs::component::Render3d>(ai).node->getPosition();

    if (bombNbr < stat.maxBomb && !alreadyExist(pos)) {
        scene::Bomberman::createBomb(worldManager, ai, stat.bombRadius, stat.wallPass, pos, playerIndex.idx);
    }
}

static bool canMoveDirection(irr::core::vector3d<irr::f32> wantedPos, ecs::WorldManager* worldManager,
    const std::string& direction, bool checkRadius)
{
    if (wantedPos.X < 0 || wantedPos.Z < 0)
        return false;
    auto ents = worldManager->getEntities<ecs::component::Breakable>();
    auto entsUnbrk = worldManager->getEntities<ecs::component::Unbreakable>();
    auto entsParticles = worldManager->getEntities<ecs::component::Particle>();

    if (direction == "LEFT")
        wantedPos.Z -= 10;
    else if (direction == "RIGHT")
        wantedPos.Z += 10;
    else if (direction == "UP")
        wantedPos.X -= 10;
    else if (direction == "DOWN")
        wantedPos.X += 10;

    for (const auto& ent : ents) {
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto& pos = render.node->getPosition();
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
        if (checkRadius) {
            try {
                auto& bombStats = worldManager->getComponent<ecs::component::BombStats>(ent);

                if (pos.X == wantedPos.X) {
                    if ((pos.Z <= wantedPos.Z &&
                            pos.Z + (10 * static_cast<float>(bombStats.bombRadius)) >= wantedPos.Z) ||
                        (pos.Z >= wantedPos.Z &&
                            pos.Z - (10 * static_cast<float>(bombStats.bombRadius)) <= wantedPos.Z))
                        return false;
                } else if (pos.Z == wantedPos.Z) {
                    if ((pos.X <= wantedPos.X &&
                            pos.X + (10 * static_cast<float>(bombStats.bombRadius)) >= wantedPos.X) ||
                        (pos.X >= wantedPos.X &&
                            pos.X - (10 * static_cast<float>(bombStats.bombRadius)) <= wantedPos.X))
                        return false;
                }
            } catch (std::exception& e) {
            }
        }
    }
    for (const auto& ent : entsUnbrk) {
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto& pos = render.node->getPosition();
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    for (const auto& ent : entsParticles) {
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto& pos = render.node->getPosition();
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    return true;
}

static std::string escapeFromDie(const irr::core::vector3d<irr::f32>& oldPos,
    const irr::core::vector3d<irr::f32>& wantedPos, ecs::WorldManager* worldManager)
{
    static irr::core::vector3d<irr::f32> lastEscape = irr::core::vector3d<irr::f32>(-50, 0, -50);
    static std::string lastChoice;
    std::vector<ecs::Entity> bombEnts =
        worldManager->getEntities<ecs::component::BombStats, ecs::component::Render3d>();

    bool possLeft = canMoveDirection(wantedPos, worldManager, "LEFT", false);
    bool possRight = canMoveDirection(wantedPos, worldManager, "RIGHT", false);
    bool possUp = canMoveDirection(wantedPos, worldManager, "UP", false);
    bool possDown = canMoveDirection(wantedPos, worldManager, "DOWN", false);

    for (const auto& ent : bombEnts) {
        auto& bombStats = worldManager->getComponent<ecs::component::BombStats>(ent);
        const auto& pos = worldManager->getComponent<ecs::component::Render3d>(ent).node->getPosition();

        if (pos.X == wantedPos.X) {
            if (lastEscape.X == wantedPos.X && lastEscape.Z == wantedPos.Z)
                return lastChoice;
            if (pos.Z <= wantedPos.Z && pos.Z + (10 * static_cast<float>(bombStats.bombRadius)) >= wantedPos.Z) {
                if (oldPos.Z <= wantedPos.Z && possRight) {
                    return "RIGHT";
                } else if (possUp || possDown) {
                    lastEscape = wantedPos;
                    lastChoice = (possUp && std::rand() % 2 == 0) ? "UP" : ((possDown) ? "DOWN" : "UP");
                    return lastChoice;
                } else if (possRight) {
                    lastEscape = wantedPos;
                    lastChoice = "RIGHT";
                    return "RIGHT";
                } else if (possLeft) {
                    lastEscape = wantedPos;
                    lastChoice = "LEFT";
                    return "LEFT";
                } else {
                    return "";
                }
            } else if (pos.Z >= wantedPos.Z && pos.Z - (10 * static_cast<float>(bombStats.bombRadius)) <= wantedPos.Z) {
                if (oldPos.Z >= wantedPos.Z && possLeft) {
                    return "LEFT";
                } else if (possUp || possDown) {
                    if (lastEscape.X == wantedPos.X && lastEscape.Z == wantedPos.Z)
                        return lastChoice;
                    lastEscape = wantedPos;
                    lastChoice = (possUp && std::rand() % 2 == 0) ? "UP" : ((possDown) ? "DOWN" : "UP");
                    return lastChoice;
                } else if (possLeft) {
                    lastEscape = wantedPos;
                    lastChoice = "LEFT";
                    return "LEFT";
                } else if (possRight) {
                    lastEscape = wantedPos;
                    lastChoice = "RIGHT";
                    return "RIGHT";
                } else {
                    return "";
                }
            }
        } else if (pos.Z == wantedPos.Z) {
            if (lastEscape.X == wantedPos.X && lastEscape.Z == wantedPos.Z)
                return lastChoice;
            if (pos.X <= wantedPos.X && pos.X + (10 * static_cast<float>(bombStats.bombRadius)) >= wantedPos.X) {
                if (oldPos.X <= wantedPos.X && possDown) {
                    return "DOWN";
                } else if (possLeft || possRight) {
                    if (lastEscape.X == wantedPos.X && lastEscape.Z == wantedPos.Z)
                        return lastChoice;
                    lastEscape = wantedPos;
                    lastChoice = (possLeft && std::rand() % 2 == 0) ? "LEFT" : ((possRight) ? "RIGHT" : "LEFT");
                    return lastChoice;
                } else if (possDown) {
                    lastEscape = wantedPos;
                    lastChoice = "DOWN";
                    return "DOWN";
                } else if (possUp) {
                    lastEscape = wantedPos;
                    lastChoice = "UP";
                    return "UP";
                } else {
                    return "";
                }
            } else if (pos.X >= wantedPos.X && pos.X - (10 * static_cast<float>(bombStats.bombRadius)) <= wantedPos.X) {
                if (oldPos.X >= wantedPos.X && possUp) {
                    return "UP";
                } else if (possLeft || possRight) {
                    if (lastEscape.X == wantedPos.X && lastEscape.Z == wantedPos.Z)
                        return lastChoice;
                    lastEscape = wantedPos;
                    lastChoice = (possLeft && std::rand() % 2 == 0) ? "LEFT" : ((possRight) ? "RIGHT" : "LEFT");
                    return lastChoice;
                } else if (possUp) {
                    lastEscape = wantedPos;
                    lastChoice = "UP";
                    return "UP";
                } else if (possDown) {
                    lastEscape = wantedPos;
                    lastChoice = "DOWN";
                    return "DOWN";
                } else {
                    return "";
                }
            }
        }
    }
    return "";
}

static std::string chooseDirection(ecs::Entity ent, ecs::WorldManager* worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ent).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ent);
    irr::core::vector3d<irr::f32> oldPos = wantedPos;

    wantedPos.X = static_cast<irr::f32>(static_cast<int>(wantedPos.X / 10.f) * 10 + 5);
    wantedPos.Z = static_cast<irr::f32>(static_cast<int>(wantedPos.Z / 10.f) * 10 + 5);

    bool possLeft = canMoveDirection(wantedPos, worldManager, "LEFT", true);
    bool possRight = canMoveDirection(wantedPos, worldManager, "RIGHT", true);
    bool possUp = canMoveDirection(wantedPos, worldManager, "UP", true);
    bool possDown = canMoveDirection(wantedPos, worldManager, "DOWN", true);

    std::string dir;

    dir = escapeFromDie(oldPos, wantedPos, worldManager);
    if (!dir.empty())
        return dir;

    if (aiComp.lastDirection == "LEFT" || aiComp.lastDirection.empty()) {
        if (oldPos.Z >= wantedPos.Z) {
            return "LEFT";
        }
        if (aiComp.lastPos != wantedPos) {
            if ((possUp || possDown) && std::rand() % 2 == 0) {
                aiComp.lastPos = wantedPos;
                return ((possUp && std::rand() % 2 == 0) ? "UP" : ((possDown) ? "DOWN" : "UP"));
            }
        }
        if (possLeft) {
            aiComp.lastPos = wantedPos;
            return "LEFT";
        }
        if (possRight) {
            aiComp.lastPos = wantedPos;
            return "RIGHT";
        }
    } else if (aiComp.lastDirection == "RIGHT") {
        if (oldPos.Z <= wantedPos.Z) {
            return "RIGHT";
        }
        if (aiComp.lastPos != wantedPos) {
            if ((possUp || possDown) && std::rand() % 2 == 0) {
                aiComp.lastPos = wantedPos;
                return ((possUp && std::rand() % 2 == 0) ? "UP" : ((possDown) ? "DOWN" : "UP"));
            }
        }
        if (possRight) {
            aiComp.lastPos = wantedPos;
            return "RIGHT";
        }
        if (possLeft) {
            aiComp.lastPos = wantedPos;
            return "LEFT";
        }
    } else if (aiComp.lastDirection == "UP") {
        if (oldPos.X >= wantedPos.X) {
            return "UP";
        }
        if (aiComp.lastPos != wantedPos) {
            if ((possRight || possLeft) && std::rand() % 2 == 0) {
                aiComp.lastPos = wantedPos;
                return ((possLeft && std::rand() % 2 == 0) ? "LEFT" : ((possRight) ? "RIGHT" : "LEFT"));
            }
        }
        if (possUp) {
            aiComp.lastPos = wantedPos;
            return "UP";
        }
        if (possDown) {
            aiComp.lastPos = wantedPos;
            return "DOWN";
        }
    } else if (aiComp.lastDirection == "DOWN") {
        if (oldPos.X <= wantedPos.X) {
            return "DOWN";
        }
        if (aiComp.lastPos != wantedPos) {
            if ((possRight || possLeft) && std::rand() % 2 == 0) {
                aiComp.lastPos = wantedPos;
                return ((possLeft && std::rand() % 2 == 0) ? "LEFT" : ((possRight) ? "RIGHT" : "LEFT"));
            }
        }
        if (possDown) {
            aiComp.lastPos = wantedPos;
            return "DOWN";
        }
        if (possUp) {
            aiComp.lastPos = wantedPos;
            return "UP";
        }
    }
    return "";
}

static bool isBreakable(
    irr::core::vector3d<irr::f32> wantedPos, ecs::WorldManager* worldManager, const std::string& direction)
{
    if (direction == "LEFT")
        wantedPos.Z -= 10;
    else if (direction == "RIGHT")
        wantedPos.Z += 10;
    else if (direction == "UP")
        wantedPos.X -= 10;
    else if (direction == "DOWN")
        wantedPos.X += 10;

    auto entities = worldManager->getEntities<ecs::component::Breakable>();

    for (const auto& ent : entities) {
        auto pos = worldManager->getComponent<ecs::component::Render3d>(ent).node->getPosition();

        irr::u32 tmpX = pos.X / 5;
        pos.X = tmpX * 5;

        try {
            auto& bombStats = worldManager->getComponent<ecs::component::BombStats>(ent);
            return false;
        } catch (std::exception& e) {
            if (pos.X == wantedPos.X && pos.Z == wantedPos.Z) {
                return true;
            }
        }
    }
    return false;
}

static bool nearBox(ecs::Entity ai, ecs::WorldManager* worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ai).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);

    wantedPos.X = static_cast<irr::f32>(static_cast<int>(wantedPos.X / 10.f) * 10 + 5);
    wantedPos.Z = static_cast<irr::f32>(static_cast<int>(wantedPos.Z / 10.f) * 10 + 5);

    bool ret = isBreakable(wantedPos, worldManager, "LEFT") || isBreakable(wantedPos, worldManager, "RIGHT") ||
        isBreakable(wantedPos, worldManager, "UP") || isBreakable(wantedPos, worldManager, "DOWN");
    return ret;
}

static bool canMove(ecs::Entity ai, ecs::WorldManager* worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ai).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);

    wantedPos.X = static_cast<irr::f32>(static_cast<int>(wantedPos.X / 10.f) * 10 + 5);
    wantedPos.Z = static_cast<irr::f32>(static_cast<int>(wantedPos.Z / 10.f) * 10 + 5);

    bool ret = canMoveDirection(wantedPos, worldManager, "LEFT", true) ||
        canMoveDirection(wantedPos, worldManager, "RIGHT", true) ||
        canMoveDirection(wantedPos, worldManager, "UP", true) ||
        canMoveDirection(wantedPos, worldManager, "DOWN", true);
    return ret;
}

void AI::update()
{
    if (entities.empty())
        return;

    float baseSpeed = 20;
    float multiplicator = baseSpeed / 4;

    for (auto ai : entities) {
        auto& motion = worldManager->getComponent<ecs::component::Motion>(ai);
        auto& node = worldManager->getComponent<ecs::component::Render3d>(ai).node;
        auto& stats = worldManager->getComponent<ecs::component::Stats>(ai);
        auto& animation = worldManager->getComponent<ecs::component::Animation>(ai);
        auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);
        std::string dir = chooseDirection(ai, worldManager);

        if (dir == "UP") {
            motion.direction.X = -1;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, -90, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "UP" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "UP";
        } else if (dir == "DOWN") {
            motion.direction.X = 1;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 90, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "DOWN" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "DOWN";
        } else if (dir == "LEFT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = -1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 180, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "LEFT" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "LEFT";
        } else if (dir == "RIGHT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = 1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 0, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "RIGHT" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "RIGHT";
        } else {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 90, 0));
            animation.currentAnimation = "IDLE";
        }
    }
}