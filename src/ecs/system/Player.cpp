/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Player.cpp
*/

#include "Player.hpp"

#include <iostream>

#include "../WorldManager.hpp"
#include "../component/Player.hpp"
#include "../component/Velocity.hpp"

using namespace ecs::system;

Player::Player(ecs::WorldManager* worldManager) : System(worldManager)
{
    worldManager->subscribe(*this, &Player::receiveInput);
}

Player::~Player() = default;

void Player::receiveInput(ecs::event::Input& event)
{
    for (const auto& entity : entities) {
        auto& velocity = worldManager->getComponent<ecs::component::Velocity>(entity);
        auto& player = worldManager->getComponent<ecs::component::Player>(entity);

        for (auto& c : event.input) {
            if (player.up == toupper(c))
                velocity.y -= 1;
            if (player.down == toupper(c))
                velocity.y += 1;
            if (player.left == toupper(c))
                velocity.x -= 1;
            if (player.right == toupper(c))
                velocity.x += 1;
            if (player.bomb == toupper(c))
                std::cout << "Une bombe est posée\n" << std::endl;
        }
    }
}

void Player::update()
{
}