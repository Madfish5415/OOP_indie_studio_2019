/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** StatRender.cpp
*/

#include "StatRender.hpp"

#include "../../scene/GameHud.hpp"
#include "../Universe.hpp"
#include "../component/Image.hpp"
#include "../component/StatRender.hpp"
#include "../component/Stats.hpp"

ecs::system::StatRender::StatRender(ecs::WorldManager* worldManager) : System(worldManager)
{
}

ecs::system::StatRender::~StatRender() = default;

void ecs::system::StatRender::update()
{
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    for (const auto& entity : entities) {
        auto& statRender = worldManager->getComponent<ecs::component::StatRender>(entity);
        auto& image = worldManager->getComponent<ecs::component::Image>(entity);
        auto& stat = worldManager->getComponent<ecs::component::Stats>(statRender.owner);

        if (statRender.type == "bombRadius") {
            if (image.pathTexture == scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.bombRadius)))
                continue;

            auto texture =
                driver->getTexture(scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.bombRadius)).c_str());

            image.pathTexture = scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.bombRadius));
            image.image->setImage(texture);
        } else if (statRender.type == "maxBomb") {
            if (image.pathTexture == scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.maxBomb)))
                continue;

            auto texture =
                driver->getTexture(scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.moveSpeed)).c_str());

            image.pathTexture = scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.maxBomb));
            image.image->setImage(texture);
        } else if (statRender.type == "moveSpeed") {
            if (image.pathTexture == scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.moveSpeed)))
                continue;

            auto texture =
                driver->getTexture(scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.moveSpeed)).c_str());

            image.pathTexture = scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(stat.moveSpeed));
            image.image->setImage(texture);
        }
    }
}