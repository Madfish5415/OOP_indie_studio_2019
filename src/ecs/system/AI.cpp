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

static bool canMoveDirection(const irr::core::vector3d<irr::f32>& wantedPos, ecs::WorldManager *worldManager)
{
    if (wantedPos.X < 0 || wantedPos.Z < 0) {
        return false;
    }
    auto entities = worldManager->getEntities<ecs::component::Render3d>();

    auto player = worldManager->getEntities<ecs::component::Player>();
    bool stop = false;

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
        std::cout << "[" << wantedPos.X << "] [" << wantedPos.Z << "]" << std::endl;
        std::cout << "[" << pos.X << "] [" << pos.Z << "]" << std::endl;
        std::cout << std::endl;
        if (pos.X == wantedPos.X && pos.Z == wantedPos.Z)
            return false;
    }
    std::cout << "FIN BOUCLE" << std::endl;
    return true;
}

static std::string chooseDirection(ecs::Entity ent, ecs::WorldManager *worldManager)
{
    irr::core::vector3d<irr::f32> wantedPos = worldManager->getComponent<ecs::component::Render3d>(ent).node->getPosition();
    auto& aiComp = worldManager->getComponent<ecs::component::AI>(ent);

    irr::u32 tmpX = wantedPos.X / 10;
    wantedPos.X = tmpX * 10;
    wantedPos.X += 5;

    irr::u32 tmpZ = wantedPos.Z / 10;
    wantedPos.Z = tmpZ * 10;
    wantedPos.Z += 5;

    if (aiComp.lastDirection == "LEFT" || aiComp.lastDirection.empty()) {
        wantedPos.Z -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "LEFT";
        wantedPos.Z += 10;
        wantedPos.X -= 10;
        if (canMoveDirection(wantedPos, worldManager)) {
            return "UP";
        }
        wantedPos.X += 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "DOWN";
        else
            std::cout << "Can'to go down from left move" << std::endl;
        wantedPos.X -= 10;
        wantedPos.Z += 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "RIGHT";
    }
    if (aiComp.lastDirection == "RIGHT") {
        wantedPos.Z += 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "RIGHT";
        wantedPos.Z -= 10;
        wantedPos.X -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "UP";
        wantedPos.X += 20;
        if (canMoveDirection(wantedPos, worldManager))
            return "DOWN";
        else
            std::cout << "Can't go down from right" << std::endl;
        wantedPos.X -= 10;
        wantedPos.Z -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "LEFT";
    }

    if (aiComp.lastDirection == "UP") {
        wantedPos.X -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "UP";
        wantedPos.X += 10;
        wantedPos.Z -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "LEFT";
        wantedPos.Z += 20;
        if (canMoveDirection(wantedPos, worldManager))
            return "RIGHT";
        wantedPos.Z -= 10;
        wantedPos.X += 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "DOWN";
    }

    if (aiComp.lastDirection == "DOWN") {
        wantedPos.X += 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "DOWN";
        wantedPos.X -= 10;
        wantedPos.Z -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "LEFT";
        wantedPos.Z += 20;
        if (canMoveDirection(wantedPos, worldManager))
            return "RIGHT";
        wantedPos.Z -= 10;
        wantedPos.X -= 10;
        if (canMoveDirection(wantedPos, worldManager))
            return "UP";


    }



//    wantedPos.Z -= 10;
//
//    if (canMoveDirection(wantedPos, worldManager)) {
//        std::cout << "JE PEUX GAUCHE" << std::endl;
//        return "LEFT";
//    }
//    else
//        std::cout << "NON PAS A GAUCHE BG" << std::endl;
//    wantedPos.Z += 20;
//    if (canMoveDirection(wantedPos, worldManager)) {
//        std::cout << "JE PEUX DROITE" << std::endl;
//        return "RIGHT";
//    }
//    wantedPos.Z -= 10;
//    wantedPos.X -= 10;
//    if (canMoveDirection(wantedPos, worldManager)) {
//        std::cout << "JE PEUX HAUT" << std::endl;
//        return "UP";
//    }
//    wantedPos.X += 20;
//    if (canMoveDirection(wantedPos, worldManager)) {
//        std::cout << "JE PEUX BAS" << std::endl;
//        return "DOWN";
//    }
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