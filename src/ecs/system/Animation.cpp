/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#include "Animation.hpp"

#include "../component/Animation.hpp"
#include "../component/Render3d.hpp"

using namespace ecs::system;

Animation::Animation(ecs::WorldManager* worldManager) : ecs::System(worldManager)
{
}

Animation::~Animation() = default;

void Animation::update()
{
    for (const auto& entity : entities) {
        const auto& animation = worldManager->getComponent<ecs::component::Animation>(entity);
        const auto& node =
            (irr::scene::IAnimatedMeshSceneNode*)worldManager->getComponent<ecs::component::Render3d>(entity).node;
        if (!animation.currentAnimation.empty() &&
            (node->getFrameNr() < animation.animationRange.at(animation.currentAnimation).first ||
                node->getFrameNr() > animation.animationRange.at(animation.currentAnimation).second)) {
            node->setFrameLoop(animation.animationRange.at(animation.currentAnimation).first,
                animation.animationRange.at(animation.currentAnimation).second);
            node->setCurrentFrame(animation.animationRange.at(animation.currentAnimation).first);
        }
    }
}