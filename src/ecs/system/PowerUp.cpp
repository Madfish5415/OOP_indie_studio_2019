/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

#include "PowerUp.hpp"

#include <iostream>

#include "../Universe.hpp"
#include "../WorldManager.hpp"
#include "../component/AI.hpp"
#include "../component/Player.hpp"
#include "../component/PlayerId.hpp"
#include "../component/Render3d.hpp"
#include "../component/Stats.hpp"

using namespace ecs::system;

PowerUp::PowerUp(ecs::WorldManager *worldManager) : System(worldManager)
{
}

PowerUp::~PowerUp() = default;

static bool checkIfCollision(ecs::WorldManager *worldManager, const ecs::Entity& entity, std::vector<ecs::Entity> characterEntities)
{
    for (const auto& characterEntity : characterEntities) {
        irr::scene::ISceneNode * characterNode = worldManager->getComponent<ecs::component::Render3d>(characterEntity).node;
        irr::scene::ISceneNode * powerNode = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        irr::core::vector3df charPos = characterNode->getPosition();
        irr::core::vector3df powerPos = powerNode->getPosition();

        irr::core::vector3df roundedPos = charPos;
        roundedPos.X = static_cast<irr::f32>(charPos.X / 10.f) * 10 + 5;
        roundedPos.Y = charPos.Y;
        roundedPos.Z = static_cast<irr::f32>(charPos.Z / 10.f) * 10 + 5;

        irr::core::vector3df roundedPos2 = powerPos;
        roundedPos2.X = static_cast<irr::f32>(powerPos.X / 10.f) * 10 + 5;
        roundedPos2.Y = powerPos.Y;
        roundedPos2.Z = static_cast<irr::f32>(powerPos.Z / 10.f) * 10 + 5;

        if (roundedPos2.X == roundedPos.X && roundedPos2.Z == roundedPos.Z) {
            auto& characterStats = worldManager->getComponent<ecs::component::Stats>(characterEntity);
            auto& powerUpStats = worldManager->getComponent<ecs::component::Stats>(entity);

            characterStats = characterStats + powerUpStats;
            worldManager->getUniverse()->getDevice()->getSceneManager()->addToDeletionQueue(powerNode);
            return true;
        }
    }
    return false;
}

void PowerUp::update()
{
    auto characters = worldManager->getEntities<ecs::component::PlayerId, ecs::component::Stats>();
    std::vector<ecs::Entity> destroyedEntities;

    for (const auto& entity : entities) {
        auto& powerUpNode = worldManager->getComponent<ecs::component::Render3d>(entity).node;

        if (checkIfCollision(worldManager, entity, characters)) {
            destroyedEntities.push_back(entity);
        }
    }
    for (const auto& entity : destroyedEntities) {
        worldManager->destroyEntity(entity);
    }
}