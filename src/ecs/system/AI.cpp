/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI.cpp
*/

#include <iostream>

#include <irrlicht.h>

#include "../component/Stats.hpp"
#include "../component/AI.hpp"
#include "../component/Player.hpp"
#include "../component/BombStats.hpp"
#include "../component/Motion.hpp"
#include "../component/Render3d.hpp"
#include "../component/Animation.hpp"

#include "AI.hpp"

using namespace ecs::system;

AI::AI(ecs::WorldManager* worldManager) : ecs::System(worldManager)
{
}

AI::~AI() = default;

static bool canMoveDirection(irr::core::vector3d<irr::f32> wantedPos, ecs::WorldManager *worldManager, std::string direction)
{
    if (wantedPos.X < 0 || wantedPos.Z < 0)
        return false;
    auto entities = worldManager->getEntities<ecs::component::Render3d>();

    auto player = worldManager->getEntities<ecs::component::Player>();
    bool stop = false;


    if (direction == "LEFT")
        wantedPos.Z -= 10;
    else if (direction == "RIGHT")
        wantedPos.Z += 10;
    else if (direction == "UP")
        wantedPos.X -= 10;
    else if (direction == "DOWN")
        wantedPos.X += 10;
    for (auto ent : entities) {
        for (auto p : player)
            if (p == ent)
               stop = true;
        if (stop) {
            stop = false;
            continue;
        }
        auto render = worldManager->getComponent<ecs::component::Render3d>(ent);
        try {
            auto ai = worldManager->getComponent<ecs::component::AI>(ent);
            continue;
        } catch (std::exception &e) {}
        auto pos = render.node->getPosition();


        irr::u32 tmpX = pos.X / 5;
        pos.X = tmpX * 5;

        irr::u32 tmpZ = pos.Z / 5;
        pos.Z = tmpZ * 5;
//        std::cout << "[" << wantedPos.X << "] [" << wantedPos.Z << "]" << std::endl;
//        std::cout << "[" << pos.X << "] [" << pos.Z << "]" << std::endl;
//        std::cout << std::endl;
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    std::cout << "FIN BOUCLE" << std::endl;
    return true;
}

static std::string chooseDirection(ecs::Entity ent, ecs::WorldManager *worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ent).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ent);
    irr::core::vector3d<irr::f32> oldPos = wantedPos;
    irr::u32 tmpX = wantedPos.X / 10;
    wantedPos.X = tmpX * 10;
    wantedPos.X += 5;

    irr::u32 tmpZ = wantedPos.Z / 10;
    wantedPos.Z = tmpZ * 10;
    wantedPos.Z += 5;

    bool possLeft = canMoveDirection(wantedPos, worldManager, "LEFT");
    bool possRight = canMoveDirection(wantedPos, worldManager, "RIGHT");
    bool possUp = canMoveDirection(wantedPos, worldManager, "UP");
    bool possDown = canMoveDirection(wantedPos, worldManager, "DOWN");


    if (aiComp.lastDirection == "LEFT" || aiComp.lastDirection.empty()) {
        if (oldPos.Z >= wantedPos.Z) {
            return "LEFT";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possUp && possDown) {
                irr::u32 rd = rand() % 3;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "UP";
                } else if (rd == 1) {
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            } else if (possUp) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "UP";
                }
            } else if (possDown) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
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
    }

    if (aiComp.lastDirection == "RIGHT") {
        if (oldPos.Z <= wantedPos.Z) {
            return "RIGHT";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possUp && possDown) {
                irr::u32 rd = rand() % 3;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "UP";
                } else if (rd == 1) {
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            }
            if (possUp && !possDown) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "UP";
                }
            }
            if (possDown && !possUp) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
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
    }

    if (aiComp.lastDirection == "UP") {
        if (oldPos.X >= wantedPos.X) {
            return "UP";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possRight && possLeft) {
                irr::u32 rd = rand() % 3;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "RIGHT";
                } else if (rd == 1) {
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
            }
            if (possRight && !possLeft) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "RIGHT";
                }
            }
            if (possLeft && !possRight) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
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
    }

    if (aiComp.lastDirection == "DOWN") {
        if (oldPos.X <= wantedPos.X) {
            return "DOWN";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possLeft && possRight) {
                irr::u32 rd = rand() % 3;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
                else if (rd == 1) {
                    aiComp.lastPos = wantedPos;
                    return "RIGHT";
                }
            }
            if (possLeft && !possRight) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
            }
            if (possRight && !possLeft) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    aiComp.lastPos = wantedPos;
                    return "RIGHT";
                }
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

#include <iostream>

void AI::update()
{
    if (entities.empty())
        return;

    //auto bombs = worldManager->getEntities<ecs::component::BombStats>();
    irr::f32 tileSize = 10.0;
    float baseSpeed = 20;
    float multiplicator = baseSpeed / 4;

    for (auto &ai : entities) {
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
            aiComp.lastDirection = "UP";
            node->setRotation(irr::core::vector3df(0, -90, 0));
            animation.currentAnimation = "WALKING";
        }
        else if (dir == "DOWN") {
            motion.direction.X = 1;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            aiComp.lastDirection = "DOWN";
            node->setRotation(irr::core::vector3df(0, 90, 0));
            animation.currentAnimation = "WALKING";
        }
        else if (dir == "LEFT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = -1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            aiComp.lastDirection = "LEFT";
            node->setRotation(irr::core::vector3df(0, 180, 0));
            animation.currentAnimation = "WALKING";
        }
        else if (dir == "RIGHT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = 1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            aiComp.lastDirection = "RIGHT";
            node->setRotation(irr::core::vector3df(0, 0, 0));
            animation.currentAnimation = "WALKING";
        }
        else {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 90, 0));
            animation.currentAnimation = "IDLE";
        }

    }
}