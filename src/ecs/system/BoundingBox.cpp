/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

#include "../../scene/Bomberman.hpp"
#include "../Universe.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/PlayerId.hpp"
#include "../component/Render3d.hpp"

using namespace ecs::system;

BoundingBox::BoundingBox(ecs::WorldManager *worldManager) : System(worldManager)
{
}

BoundingBox::~BoundingBox() = default;

bool BoundingBox::isCollide(irr::scene::IMeshSceneNode *mesh, size_t id)
{
    auto entities = worldManager->getEntities<ecs::component::Render3d, ecs::component::PlayerId>();

    for (const auto& entity : entities) {
        auto& playerId = worldManager->getComponent<ecs::component::PlayerId>(entity);

        if (playerId.id == id) {
            auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

            return mesh->getTransformedBoundingBox().intersectsWithBox(render3d.node->getTransformedBoundingBox());
        }
    }
    return false;
}

void BoundingBox::update()
{
    for (const auto& entity : entities) {
        auto& boundingBox = worldManager->getComponent<ecs::component::BoundingBox>(entity);

        size_t id = 0;
        for (auto& collision : boundingBox.collision) {
            if (!collision) {
                if (!isCollide(boundingBox.mesh, id)) {
                    scene::Bomberman::metaTriangleSelector[id]->addTriangleSelector(boundingBox.selector);
                    scene::Bomberman::updateCollision(worldManager);
                    collision = true;
                }
            }
            id++;
        }

    }
}
