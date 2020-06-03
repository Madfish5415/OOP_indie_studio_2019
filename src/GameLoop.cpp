/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** GameLoop.cpp
*/

#include "GameLoop.hpp"
#include <iostream>

#include "ecs/component/Player.hpp"
#include "ecs/component/Position.hpp"
#include "ecs/component/Render.hpp"
#include "ecs/component/Velocity.hpp"
#include "ecs/system/Motion.hpp"
#include "ecs/system/Render.hpp"
#include "ecs/system/Player.hpp"

GameLoop::GameLoop() : _worldManager(std::make_unique<ecs::WorldManager>())
{
}

GameLoop::~GameLoop() = default;

void GameLoop::init()
{
    ecs::Entity player = _worldManager->createEntity();

    _worldManager->registerComponent<ecs::component::Player>();
    _worldManager->registerComponent<ecs::component::Position>();
    _worldManager->registerComponent<ecs::component::Velocity>();
    _worldManager->registerComponent<ecs::component::Render>();

    _worldManager->registerSystem<ecs::system::Motion>();
    {
        ecs::Signature signature;

        signature.set(_worldManager->getComponentType<ecs::component::Position>());
        signature.set(_worldManager->getComponentType<ecs::component::Velocity>());
        _worldManager->setSystemSignature<ecs::system::Motion>(signature);
    }

    _worldManager->registerSystem<ecs::system::Player>();
    {
        ecs::Signature signature;

        signature.set(_worldManager->getComponentType<ecs::component::Player>());
        signature.set(_worldManager->getComponentType<ecs::component::Velocity>());
        _worldManager->setSystemSignature<ecs::system::Player>(signature);
    }

    _worldManager->registerSystem<ecs::system::Render>();
    {
        ecs::Signature signature;

        signature.set(_worldManager->getComponentType<ecs::component::Render>());
        signature.set(_worldManager->getComponentType<ecs::component::Position>());
        _worldManager->setSystemSignature<ecs::system::Render>(signature);
    }

    _worldManager->addComponent<ecs::component::Player>(player, ecs::component::Player());
    _worldManager->addComponent<ecs::component::Position>(player, ecs::component::Position());
    _worldManager->addComponent<ecs::component::Velocity>(player, ecs::component::Velocity());
    _worldManager->addComponent<ecs::component::Render>(player, ecs::component::Render());
}

static void eventReceiver(ecs::WorldManager *worldManager)
{
    std::string buffer;

    std::cin >> buffer;
    ecs::event::Input input(buffer);

    worldManager->publish(input);
}

void GameLoop::run()
{
    while (1) {
        eventReceiver(_worldManager.get());
        // _worldManager->updateSystem();
        _worldManager->getSystem<ecs::system::Motion>()->update();
        _worldManager->getSystem<ecs::system::Render>()->update();
    }
}
