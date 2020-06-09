/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#include <iostream>

#include "PowerUp.hpp"

#include "../WorldManager.hpp"
#include "../Universe.hpp"
#include "../component/Render3d.hpp"
#include "../component/AI.hpp"
#include "../component/Player.hpp"
#include "../component/Stats.hpp"

using namespace ecs::system;

PowerUp::PowerUp(ecs::WorldManager *worldManager) : System(worldManager)
{
}

PowerUp::~PowerUp() = default;

static bool checkIfCollision(ecs::WorldManager *worldManager, const ecs::Entity& entity, std::vector<ecs::Entity> characterEntities)
{
    for (const auto& characterEntity : characterEntities) {
        irr::scene::ISceneNode *character_node = worldManager->getComponent<ecs::component::Render3d>(characterEntity).node;
        irr::scene::ISceneNode *power_node = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        irr::core::vector3df charPos = character_node->getPosition();
        irr::core::aabbox3df b1 = irr::core::aabbox3df(irr::core::vector3df(charPos.X - 4, charPos.Y, charPos.Z - 4), irr::core::vector3df(charPos.X + 4, charPos.Y + 17, charPos.Z + 4));
        irr::core::aabbox3df b2 = power_node->getBoundingBox();

        power_node->getRelativeTransformation().transformBoxEx(b2);
        if (b1.intersectsWithBox(b2)) {
            auto& characterStats = worldManager->getComponent<ecs::component::Stats>(characterEntity);
            auto& powerUpStats = worldManager->getComponent<ecs::component::Stats>(entity);

            characterStats = characterStats + powerUpStats;
            power_node->remove();
            return true;
        }
    }
    return false;
}

void PowerUp::update()
{
    auto playerEntities = worldManager->getEntities<ecs::component::Player>();
    auto botEntities = worldManager->getEntities<ecs::component::AI>();
    std::vector<ecs::Entity> destroyedEntities;

    for (const auto& entity : entities) {
        auto& powerUpNode = worldManager->getComponent<ecs::component::Render3d>(entity).node;

        if (!checkIfCollision(worldManager, entity, playerEntities)) {
            if (checkIfCollision(worldManager, entity, botEntities)) {
                destroyedEntities.push_back(entity);
            }
        }
        else {
            destroyedEntities.push_back(entity);
        }
    }
    for (const auto& entity : destroyedEntities) {
        worldManager->destroyEntity(entity);
    }
}