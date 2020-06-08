/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUp
*/

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

static bool isCollision(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two) {
   irr::core::aabbox3df b1 = one->getBoundingBox ();
   irr::core::aabbox3df b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return (b1.intersectsWithBox( b2 ));
}

static bool checkIfCollision(ecs::WorldManager *worldManager, const ecs::Entity& entity, std::vector<ecs::Entity> characterEntities)
{
    for (const auto& characterEntity : characterEntities) {
        irr::scene::ISceneNode *character_node = worldManager->getComponent<ecs::component::Render3d>(characterEntity).node;
        irr::scene::ISceneNode *power_node = worldManager->getComponent<ecs::component::Render3d>(entity).node;
        irr::core::aabbox3df b1 = character_node->getBoundingBox ();
        irr::core::aabbox3df b2 = power_node->getBoundingBox ();

        character_node->getRelativeTransformation().transformBoxEx(b1);
        power_node->getRelativeTransformation().transformBoxEx(b2);

        if (b1.intersectsWithBox(b2)) {
            auto& characterStats = worldManager->getComponent<ecs::component::Stats>(characterEntity);
            auto& powerUpStats = worldManager->getComponent<ecs::component::Stats>(entity);

            characterStats = characterStats + powerUpStats;
            power_node->remove();
            worldManager->destroyEntity(entity);
            return true;
        }
    }
    return false;
}

void PowerUp::update()
{
    auto playerEntities = worldManager->getEntities<ecs::component::Player>();
    auto botEntities = worldManager->getEntities<ecs::component::AI>();

    for (const auto& entity : entities) {
        auto& powerUpNode = worldManager->getComponent<ecs::component::Render3d>(entity).node;

        if (!checkIfCollision(worldManager, entity, playerEntities)) {
            checkIfCollision(worldManager, entity, botEntities);
        }
    }
}