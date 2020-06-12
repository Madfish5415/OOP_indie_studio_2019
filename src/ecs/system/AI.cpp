/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** AI.cpp
*/

#include <iostream>

#include <irrlicht.h>

#include "../system/Player.hpp"
#include "../../scene/Bomberman.hpp"

#include "../component/Stats.hpp"
#include "../component/AI.hpp"
#include "../component/Player.hpp"
#include "../component/BombStats.hpp"
#include "../component/Motion.hpp"
#include "../component/Render3d.hpp"
#include "../component/Animation.hpp"
#include "../component/BombTimer.hpp"
#include "../component/Owner.hpp"
#include "../component/Breakable.hpp"
#include "../component/Unbreakable.hpp"

#include "AI.hpp"

using namespace ecs::system;

AI::AI(ecs::WorldManager* worldManager) : ecs::System(worldManager)
{
}

AI::~AI() = default;

bool AI::alreadyExist(const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> bombs = worldManager->getEntities<ecs::component::BombTimer, ecs::component::BombStats, ecs::component::Owner>();

    for (const auto& entity : bombs) {
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        auto newPos = pos;
        newPos.X = static_cast<irr::f32>(pos.X / 10.f) * 10 + 5;
        newPos.Y = 4;
        newPos.Z = static_cast<irr::f32>(pos.Z / 10.f) * 10 + 5;
        if (render3d.node->getPosition() == newPos) {
            return true;
        }
    }
    return false;
}

void AI::plantBomb(ecs::Entity ai, ecs::WorldManager *worldManager)
{
    std::vector<ecs::Entity> bombs = worldManager->getEntities<ecs::component::BombStats,
        ecs::component::BombTimer, ecs::component::Owner>();
    int bombNbr = 0;

    for (const auto& bomb : bombs) {
        auto& owner = worldManager->getComponent<ecs::component::Owner>(bomb);
        if (owner.entity == ai)
            bombNbr++;
    }

    auto& stat = worldManager->getComponent<ecs::component::Stats>(ai);
    auto& render3d = worldManager->getComponent<ecs::component::Render3d>(ai);

    if (bombNbr < stat.maxBomb && !alreadyExist(render3d.node->getPosition())) {
        scene::Bomberman::createBomb(worldManager, ai, stat.bombRadius, stat.wallPass, render3d.node->getPosition());
    }
}

static bool canMoveDirection(irr::core::vector3d<irr::f32> wantedPos, ecs::WorldManager *worldManager, std::string direction)
{
    if (wantedPos.X < 0 || wantedPos.Z < 0)
        return false;
    auto ents = worldManager->getEntities<ecs::component::Breakable>();
    auto entsUnbrk = worldManager->getEntities<ecs::component::Unbreakable>();
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

    for (const auto& ent : ents) {
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto& pos = render.node->getPosition();
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    for (const auto& ent : entsUnbrk) {
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto& pos = render.node->getPosition();
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    return true;
}

static std::string tryEscape(ecs::Entity ai, irr::core::vector3d<irr::f32> oldPos, ecs::WorldManager *worldManager)
{
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);

    if (aiComp.lastDirection == "UP") {
        if (canMoveDirection(oldPos, worldManager, "UP")) {
            std::cout << "UP" << std::endl;
            return "UP";
        }
        if (canMoveDirection(oldPos, worldManager, "RIGHT")) {
            std::cout << "RIGHT" << std::endl;
            return "RIGHT";
        }
        if (canMoveDirection(oldPos, worldManager, "LEFT")) {
            std::cout << "LEFT" << std::endl;
            return "LEFT";
        }
        if (canMoveDirection(oldPos, worldManager, "DOWN")) {
            std::cout << "DOWN" << std::endl;
            return "DOWN";
        }
    }
    if (aiComp.lastDirection == "DOWN") {
        if (canMoveDirection(oldPos, worldManager, "DOWN")) {
            std::cout << "DOWN" << std::endl;
            return "DOWN";
        }
        if (canMoveDirection(oldPos, worldManager, "UP")) {
            std::cout << "UP" << std::endl;
            return "UP";
        }
        if (canMoveDirection(oldPos, worldManager, "RIGHT")) {
            std::cout << "RIGHT" << std::endl;
            return "RIGHT";
        }
        if (canMoveDirection(oldPos, worldManager, "LEFT")) {
            std::cout << "LEFT" << std::endl;
            return "LEFT";
        }
    }
    if (aiComp.lastDirection == "RIGHT") {
        if (canMoveDirection(oldPos, worldManager, "RIGHT")) {
            std::cout << "RIGHT" << std::endl;
            return "RIGHT";
        }
        if (canMoveDirection(oldPos, worldManager, "DOWN")) {
            std::cout << "DOWN" << std::endl;
            return "DOWN";
        }
        if (canMoveDirection(oldPos, worldManager, "UP")) {
            std::cout << "UP" << std::endl;
            return "UP";
        }
        if (canMoveDirection(oldPos, worldManager, "LEFT")) {
            std::cout << "LEFT" << std::endl;
            return "LEFT";
        }
    }
    if (aiComp.lastDirection == "LEFT") {
        if (canMoveDirection(oldPos, worldManager, "LEFT")) {
            std::cout << "LEFT" << std::endl;
            return "LEFT";
        }
        if (canMoveDirection(oldPos, worldManager, "RIGHT")) {
            std::cout << "RIGHT" << std::endl;
            return "RIGHT";
        }
        if (canMoveDirection(oldPos, worldManager, "DOWN")) {
            std::cout << "DOWN" << std::endl;
            return "DOWN";
        }
        if (canMoveDirection(oldPos, worldManager, "UP")) {
            std::cout << "UP" << std::endl;
            return "UP";
        }
    }
    return "";
}

static std::string escape(ecs::Entity ai, ecs::WorldManager *worldManager, std::string direction)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ai).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);
    irr::core::vector3d<irr::f32> oldPos = wantedPos;
    irr::u32 tmpX = wantedPos.X / 10;
    wantedPos.X = tmpX * 10;
    wantedPos.X += 5;

    irr::u32 tmpZ = wantedPos.Z / 10;
    wantedPos.Z = tmpZ * 10;
    wantedPos.Z += 5;

    if (direction == "LEFT")
        wantedPos.Z -= 10;
    else if (direction == "RIGHT")
        wantedPos.Z += 10;
    else if (direction == "UP")
        wantedPos.X -= 10;
    else if (direction == "DOWN")
        wantedPos.X += 10;

    std::cout << "LA" << std::endl;
    auto entities = worldManager->getEntities<ecs::component::BombStats>();
    if (entities.empty()) {
        std::cout << "Osef1" << std::endl;
        return "";
    }
    for (const auto& bomb : entities) {
        auto& bombPos = worldManager->getComponent<ecs::component::Render3d>(bomb).node->getPosition();
        if (bombPos.Z != wantedPos.Z || bombPos.X != wantedPos.X)
            continue;
        auto& stat = worldManager->getComponent<ecs::component::BombStats>(bomb);
        if (stat.wallPass) {
            if ((bombPos.X < wantedPos.X && (bombPos.X + (10 * stat.bombRadius)) > wantedPos.X) || (bombPos.X > wantedPos.X && (bombPos.X + (10 * stat.bombRadius)) < wantedPos.X)) {
                std::string dir = tryEscape(ai, oldPos, worldManager);
                if (!dir.empty())
                    return dir;
            }
            else if ((bombPos.Z < wantedPos.Z && (bombPos.Z + (10 * stat.bombRadius)) > wantedPos.Z) || (bombPos.Z > wantedPos.Z && (bombPos.Z + (10 * stat.bombRadius)) < wantedPos.Z)) {
                std::string dir = tryEscape(ai, oldPos, worldManager);
                if (!dir.empty())
                    return dir;
            }
        } else {
            auto breakable = worldManager->getEntities<ecs::component::Breakable>();
            for (const auto& entBrk : breakable) {
                if (bomb == entBrk)
                    continue;
                auto& entPos = worldManager->getComponent<ecs::component::Render3d>(entBrk).node->getPosition();
                if (entPos.X == wantedPos.X) {
                    if ((entPos.Z > (bombPos.Z + 10 * stat.bombRadius) && entPos.Z < wantedPos.Z) ||
                        (entPos.Z < (bombPos.Z + 10 * stat.bombRadius) && entPos.Z > wantedPos.Z)) {
                        std::string dir = tryEscape(ai, oldPos, worldManager);
                        if (!dir.empty())
                            return dir;
                    }
                }
                if (entPos.Z == wantedPos.Z) {
                    if ((entPos.X > (bombPos.X + 10 * stat.bombRadius) && entPos.X < wantedPos.X) ||
                        (entPos.X < (bombPos.X + 10 * stat.bombRadius) && entPos.X > wantedPos.X)) {
                        std::string dir = tryEscape(ai, oldPos, worldManager);
                        if (!dir.empty())
                            return dir;
                    }
                }
            }
            return tryEscape(ai, oldPos, worldManager);
        }
    }
    std::cout << "Osef2" << std::endl;
    return "";
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
            std::string ret = escape(ent, worldManager, "LEFT");
            if (ret != "")
                return ret;
            return "LEFT";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possUp && possDown) {
                irr::u32 rd = rand() % 3;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "UP");
                    if (ret != "")
                        return ret;
                    return "UP";
                } else if (rd == 1 ) {
                    std::string ret = escape(ent, worldManager, "DOWN");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            } else if (possUp ) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    std::string ret = escape(ent, worldManager, "UP");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "UP";
                }
            } else if (possDown ) {
                irr::u32 rd = rand() % 2;
                if (rd == 0) {
                    std::string ret = escape(ent, worldManager, "DOWN");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            }
        }
        if (possLeft ) {
            std::string ret = escape(ent, worldManager, "LEFT");
            if (ret != "")
                return ret;
            aiComp.lastPos = wantedPos;
            return "LEFT";
        }
        if (possRight ) {
            std::string ret = escape(ent, worldManager, "RIGHT");
            if (ret != "")
                return ret;
            aiComp.lastPos = wantedPos;
            return "RIGHT";
        }
        return "";
    }

    if (aiComp.lastDirection == "RIGHT") {
        if (oldPos.Z <= wantedPos.Z ) {
            std::string ret = escape(ent, worldManager, "RIGHT");
            if (ret != "")
                return ret;
            return "RIGHT";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possUp && possDown) {
                irr::u32 rd = rand() % 3;
                if (rd == 0 ) {
                    std::string ret = escape(ent, worldManager, "UP");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "UP";
                } else if (rd == 1 ) {
                    std::string ret = escape(ent, worldManager, "DOWN");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            }
            if (possUp && !possDown) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "UP");
                    if (ret != "")
                        return ret;
                    return "UP";
                }
            }
            if (possDown && !possUp) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    std::string ret = escape(ent, worldManager, "DOWN");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "DOWN";
                }
            }
        }
        if (possRight ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "RIGHT");
            if (ret != "")
                return ret;
            return "RIGHT";
        }
        if (possLeft ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "LEFT");
            if (ret != "")
                return ret;
            return "LEFT";
        }
        return "";
    }

    if (aiComp.lastDirection == "UP") {
        if (oldPos.X >= wantedPos.X ) {
            std::string ret = escape(ent, worldManager, "UP");
            if (ret != "")
                return ret;
            return "UP";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possRight && possLeft) {
                irr::u32 rd = rand() % 3;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "RIGHT");
                    if (ret != "")
                        return ret;
                    return "RIGHT";
                } else if (rd == 1 ) {
                    std::string ret = escape(ent, worldManager, "LEFT");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
            }
            if (possRight && !possLeft) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    std::string ret = escape(ent, worldManager, "RIGHT");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "RIGHT";
                }
            }
            if (possLeft && !possRight) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    std::string ret = escape(ent, worldManager, "LEFT");
                    if (ret != "")
                        return ret;
                    aiComp.lastPos = wantedPos;
                    return "LEFT";
                }
            }
        }
        if (possUp ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "UP");
            if (ret != "")
                return ret;
            return "UP";
        }
        if (possDown ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "DOWN");
            if (ret != "")
                return ret;
            return "DOWN";
        }
        return "";
    }

    if (aiComp.lastDirection == "DOWN") {
        if (oldPos.X <= wantedPos.X ) {
            std::string ret = escape(ent, worldManager, "DOWN");
            if (ret != "")
                return ret;
            return "DOWN";
        }
        if (aiComp.lastPos != wantedPos) {
            if (possLeft && possRight) {
                irr::u32 rd = rand() % 3;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "LEFT");
                    if (ret != "")
                        return ret;
                    return "LEFT";
                }
                else if (rd == 1 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "RIGHT");
                    if (ret != "")
                        return ret;
                    return "RIGHT";
                }
            }
            if (possLeft && !possRight) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "LEFT");
                    if (ret != "")
                        return ret;
                    return "LEFT";
                }
            }
            if (possRight && !possLeft) {
                irr::u32 rd = rand() % 2;
                if (rd == 0 ) {
                    aiComp.lastPos = wantedPos;
                    std::string ret = escape(ent, worldManager, "RIGHT");
                    if (ret != "")
                        return ret;
                    return "RIGHT";
                }
            }
        }
        if (possDown ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "DOWN");
            if (ret != "")
                return ret;
            return "DOWN";
        }
        if (possUp ) {
            aiComp.lastPos = wantedPos;
            std::string ret = escape(ent, worldManager, "UP");
            if (ret != "")
                return ret;
            return "UP";
        }
        return "";
    }
    return "";
}

static bool isBreakable(irr::core::vector3d<irr::f32> wantedPos, ecs::WorldManager *worldManager, const std::string& direction)
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
        auto& render = worldManager->getComponent<ecs::component::Render3d>(ent);
        auto pos = render.node->getPosition();

        irr::u32 tmpX = pos.X / 5;
        pos.X = tmpX * 5;

        irr::u32 tmpZ = pos.Z / 5;
        pos.Z = tmpZ * 5;
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z) {
           return true;
        }
    }
    return false;
}

static bool nearBox(ecs::Entity ai, ecs::WorldManager *worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos =
        worldManager->getComponent<ecs::component::Render3d>(ai).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ai);
    irr::u32 tmpX = wantedPos.X / 10;
    wantedPos.X = tmpX * 10;
    wantedPos.X += 5;

    irr::u32 tmpZ = wantedPos.Z / 10;
    wantedPos.Z = tmpZ * 10;
    wantedPos.Z += 5;

    bool ret = isBreakable(wantedPos, worldManager, "LEFT") || isBreakable(wantedPos, worldManager, "RIGHT") || isBreakable(wantedPos, worldManager, "UP") || isBreakable(wantedPos, worldManager, "DOWN");
    return ret;
}

void AI::update()
{
    if (entities.empty())
        return;

    irr::f32 tileSize = 10.0;
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
        }
        else if (dir == "DOWN") {
            motion.direction.X = 1;
            motion.direction.Y = 0;
            motion.direction.Z = 0;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 90, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "DOWN" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "DOWN";
        }
        else if (dir == "LEFT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = -1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 180, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "LEFT" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "LEFT";
        }
        else if (dir == "RIGHT") {
            motion.direction.X = 0;
            motion.direction.Y = 0;
            motion.direction.Z = 1;
            motion.movementSpeed = baseSpeed + (multiplicator * stats.moveSpeed);
            node->setRotation(irr::core::vector3df(0, 0, 0));
            animation.currentAnimation = "WALKING";
            if (aiComp.lastDirection != "RIGHT" && nearBox(ai, worldManager))
                plantBomb(ai, worldManager);
            aiComp.lastDirection = "RIGHT";
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