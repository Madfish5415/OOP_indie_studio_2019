/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** CountDown.cpp
*/

#include "CountDown.hpp"

#include "../ecs/component/Image.hpp"
#include "../ecs/component/Music.hpp"
#include "../ecs/component/Timer.hpp"
#include "../ecs/system/Music.hpp"
#include "../ecs/system/Render.hpp"
#include "../ecs/system/CountDown.hpp"

std::vector<ecs::Entity> scene::CountDown::images = {};

void scene::CountDown::init(ecs::Universe *universe)
{
    auto worldManager = universe->createWorldManager("CountDown");
    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    worldManager->registerComponent<ecs::component::Image>();
    worldManager->registerComponent<ecs::component::Timer>();
    worldManager->registerComponent<ecs::component::Music>();

    worldManager->registerSystem<ecs::system::Render>();
    worldManager->registerSystem<ecs::system::CountDown>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Image>());
        worldManager->setSystemSignature<ecs::system::CountDown>(signature);
    }
    worldManager->registerSystem<ecs::system::Music>();
    {
        ecs::Signature signature;

        signature.set(worldManager->getComponentType<ecs::component::Music>());
        worldManager->setSystemSignature<ecs::system::Music>(signature);
    }
    ecs::Entity countDown = worldManager->createEntity();
    worldManager->addComponent(countDown, ecs::component::Image(gui, driver, countdown::THREE, new irr::core::position2d<irr::s32>(0, 0)));
    worldManager->addComponent(countDown, ecs::component::Timer(1000));
    scene::CountDown::images.push_back(countDown);

    ecs::Entity music = worldManager->createEntity();
    worldManager->addComponent(music, ecs::component::Music(scene::countdown::MUSIC));
}
void scene::CountDown::destroy(ecs::Universe *universe)
{
    for (auto& entity : scene::CountDown::images) {
        auto& img = universe->getWorldManager("CountDown")->getComponent<ecs::component::Image>(entity);
        img.image->remove();
    }

    universe->deleteWorldManager("CountDown");
    images.clear();
}
