/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Countdown
*/

#include "Countdown.hpp"

#include <iostream>

#include "../../scene/CountDown.hpp"
#include "../component/Image.hpp"
#include "../component/Timer.hpp"

using namespace ecs::system;

Countdown::Countdown(ecs::WorldManager* worldManager) : System(worldManager)
{
}

Countdown::~Countdown() = default;

void Countdown::update()
{
    for (const auto& entity : entities) {
        auto& image = worldManager->getComponent<ecs::component::Image>(entity);
        try {
            auto& timer = worldManager->getComponent<ecs::component::Timer>(entity);

            if (timer.elapsed == timer.delay) {
                irr::u32 idx = scene::CountDown::images.size();

                worldManager->removeComponent<ecs::component::Timer>(entity);
                image.image->setVisible(false);
                if (idx < 4) {
                    ecs::Entity newCount = worldManager->createEntity();
                    auto gui = worldManager->getUniverse()->getDevice()->getGUIEnvironment();
                    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

                    worldManager->addComponent(newCount, ecs::component::Timer(1000));
                    if (idx == 1) {
                        worldManager->addComponent(newCount,
                            ecs::component::Image(
                                gui, driver, scene::countdown::TWO, new irr::core::position2d<irr::s32>(0, 0)));
                    } else if (idx == 2) {
                        worldManager->addComponent(newCount,
                            ecs::component::Image(
                                gui, driver, scene::countdown::ONE, new irr::core::position2d<irr::s32>(0, 0)));
                    } else {
                        worldManager->addComponent(newCount,
                            ecs::component::Image(
                                gui, driver, scene::countdown::GO, new irr::core::position2d<irr::s32>(0, 0)));
                    }
                    irr::gui::IGUIInOutFader* fader = gui->addInOutFader();
                    fader->setColor(irr::video::SColor(0, 0, 0, 0));
                    fader->fadeIn(1000);
                    scene::CountDown::images.push_back(newCount);
                    scene::CountDown::faders.push_back(fader);
                } else {
                    for (const auto& elem : scene::CountDown::images) {
                        auto& imageCmp = worldManager->getComponent<ecs::component::Image>(elem);
                        imageCmp.image->remove();
                    }
                    for (const auto& elem : scene::CountDown::faders) {
                        elem->remove();
                    }
                    scene::CountDown::images.clear();
                    scene::CountDown::faders.clear();
                    worldManager->getUniverse()->setCurrentWorldManager("Bomberman");
                }
            }
        } catch (std::exception& e) {
            continue;
        }
    }
}