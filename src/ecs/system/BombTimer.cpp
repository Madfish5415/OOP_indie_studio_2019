/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombTimer
*/

#include "BombTimer.hpp"

#include "../../scene/Bomberman.hpp"
#include "../component/BombStats.hpp"
#include "../component/BombTimer.hpp"
#include "../component/BoundingBox.hpp"
#include "../component/Breakable.hpp"
#include "../component/PlayerIndex.hpp"
#include "../component/Render3d.hpp"
#include "../component/Sound.hpp"
#include "../component/Unbreakable.hpp"

using namespace ecs::system;

BombTimer::BombTimer(ecs::WorldManager* worldManager) : System(worldManager)
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
}

BombTimer::~BombTimer() = default;

void BombTimer::update()
{
    time = worldManager->getUniverse()->getDevice()->getTimer()->getTime();
    std::vector<ecs::Entity> entitiesDelete = {};

    for (const auto& entity : entities) {
        auto& timer = worldManager->getComponent<ecs::component::BombTimer>(entity);

        if (timer.lastUpdate == 0) {
            timer.lastUpdate = time;
        } else {
            timer.elapsed += time - timer.lastUpdate;
            timer.lastUpdate = time;
            if (timer.elapsed >= timer.delay)
                timer.elapsed = timer.delay;
        }

        auto diff = timer.delay - timer.elapsed;

        if (diff <= 300) {
            auto& bombStats = worldManager->getComponent<ecs::component::BombStats>(entity);

            if (!bombStats.explode) {
                bombStats.explode = true;
                BombTimer::explode(worldManager, entity);
            }
        }

        if (diff == 0) {
            auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);
            auto& boundingBox = worldManager->getComponent<ecs::component::BoundingBox>(entity);
            auto smgr = worldManager->getUniverse()->getDevice()->getSceneManager();

            for (auto& metaTriangleSelector : scene::Bomberman::metaTriangleSelector)
                metaTriangleSelector->removeTriangleSelector(boundingBox.selector);
            smgr->addToDeletionQueue(render3d.node);
            smgr->addToDeletionQueue(boundingBox.mesh);
            entitiesDelete.push_back(entity);
        }
    }
    for (auto& entity : entitiesDelete) {
        worldManager->destroyEntity(entity);
    }
}

static void limitToUnbreakable(ecs::WorldManager* worldManager, std::array<int, 4>& radius,
    const irr::core::vector3d<irr::f32>& pos, int maxRadius)
{
    std::vector<ecs::Entity> unbreakableBoxes = worldManager->getEntities<ecs::component::Unbreakable>();

    for (const auto& entity : unbreakableBoxes) {
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        if (render3d.node->isDebugObject())
            continue;

        for (int i = 1; i <= maxRadius; i++) {
            if (render3d.node->getPosition() ==
                irr::core::vector3d<irr::f32>(pos.X + 10 * static_cast<float>(i), 5, pos.Z))
                radius[0] = (radius[0] < i - 1) ? radius[0] : i - 1;
            if (render3d.node->getPosition() ==
                irr::core::vector3d<irr::f32>(pos.X - 10 * static_cast<float>(i), 5, pos.Z))
                radius[1] = (radius[1] < i - 1) ? radius[1] : i - 1;
            if (render3d.node->getPosition() ==
                irr::core::vector3d<irr::f32>(pos.X, 5, pos.Z + 10 * static_cast<float>(i)))
                radius[2] = (radius[2] < i - 1) ? radius[2] : i - 1;
            if (render3d.node->getPosition() ==
                irr::core::vector3d<irr::f32>(pos.X, 5, pos.Z - 10 * static_cast<float>(i)))
                radius[3] = (radius[3] < i - 1) ? radius[3] : i - 1;
        }
    }
}

static void limitToFirstBreakable(
    ecs::WorldManager* worldManager, std::array<int, 4>& radius, const irr::core::vector3d<irr::f32>& pos)
{
    std::vector<ecs::Entity> breakableBoxes = worldManager->getEntities<ecs::component::Breakable>();

    for (const auto& entity : breakableBoxes) {
        auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);

        if (!render3d.node || render3d.node->isDebugObject())
            continue;

        auto boxPos = render3d.node->getPosition();

        if (boxPos == pos)
            continue;

        for (int i = 1; i <= radius[0]; i++) {
            if (boxPos == irr::core::vector3d<irr::f32>(pos.X + 10 * static_cast<float>(i), 5, pos.Z) ||
                boxPos == irr::core::vector3d<irr::f32>(pos.X + 10 * static_cast<float>(i), 4, pos.Z))
                radius[0] = (radius[0] < i) ? radius[0] : i;
        }
        for (int i = 1; i <= radius[1]; i++) {
            if (boxPos == irr::core::vector3d<irr::f32>(pos.X - 10 * static_cast<float>(i), 5, pos.Z) ||
                boxPos == irr::core::vector3d<irr::f32>(pos.X - 10 * static_cast<float>(i), 4, pos.Z))
                radius[1] = (radius[1] < i) ? radius[1] : i;
        }
        for (int i = 1; i <= radius[2]; i++) {
            if (boxPos == irr::core::vector3d<irr::f32>(pos.X, 5, pos.Z + 10 * static_cast<float>(i)) ||
                boxPos == irr::core::vector3d<irr::f32>(pos.X, 4, pos.Z + 10 * static_cast<float>(i)))
                radius[2] = (radius[2] < i) ? radius[2] : i;
        }
        for (int i = 1; i <= radius[3]; i++) {
            if (boxPos == irr::core::vector3d<irr::f32>(pos.X, 5, pos.Z - 10 * static_cast<float>(i)) ||
                boxPos == irr::core::vector3d<irr::f32>(pos.X, 4, pos.Z - 10 * static_cast<float>(i)))
                radius[3] = (radius[3] < i) ? radius[3] : i;
        }
    }
}

void BombTimer::explode(ecs::WorldManager* worldManager, const ecs::Entity& entity)
{
    auto& stat = worldManager->getComponent<ecs::component::BombStats>(entity);
    auto& render3d = worldManager->getComponent<ecs::component::Render3d>(entity);
    auto& sound = worldManager->getComponent<ecs::component::Sound>(entity);
    auto& playerIndex = worldManager->getComponent<ecs::component::PlayerIndex>(entity);
    const auto& pos = render3d.node->getPosition();
    std::array<int, 4> radius = {static_cast<int>(stat.bombRadius), static_cast<int>(stat.bombRadius),
        static_cast<int>(stat.bombRadius), static_cast<int>(stat.bombRadius)};

    limitToUnbreakable(worldManager, radius, pos, static_cast<int>(stat.bombRadius));
    if (!stat.wallPass)
        limitToFirstBreakable(worldManager, radius, pos);

    for (int i = 0; i <= radius[0]; i++) {
        scene::Bomberman::createExplosion(worldManager, 1000,
            irr::core::vector3d<irr::f32>(pos.X + 10.f * static_cast<float>(i), 5.f, pos.Z), playerIndex.idx);
    }
    for (int i = 0; i <= radius[1]; i++) {
        scene::Bomberman::createExplosion(worldManager, 1000,
            irr::core::vector3d<irr::f32>(pos.X - 10.f * static_cast<float>(i), 5.f, pos.Z), playerIndex.idx);
    }
    for (int i = 0; i <= radius[2]; i++) {
        scene::Bomberman::createExplosion(worldManager, 1000,
            irr::core::vector3d<irr::f32>(pos.X, 5.f, pos.Z + 10.f * static_cast<float>(i)), playerIndex.idx);
    }
    for (int i = 0; i <= radius[3]; i++) {
        scene::Bomberman::createExplosion(worldManager, 1000,
            irr::core::vector3d<irr::f32>(pos.X, 5.f, pos.Z - 10.f * static_cast<float>(i)), playerIndex.idx);
    }
    sound.soundsToPlay.emplace_back("explosion");
}
