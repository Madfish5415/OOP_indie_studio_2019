/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** TimerRender.cpp
*/

#include "TimerRender.hpp"

#ifdef _WIN32
#include <stdexcept>
#endif

#include "../../scene/GameHud.hpp"
#include "../Universe.hpp"
#include "../component/Blink.hpp"
#include "../component/Image.hpp"
#include "../component/Timer.hpp"
#include "../component/TimerRender.hpp"
#include "../event/TimerEnd.hpp"

using namespace ecs::system;

TimerRender::TimerRender(ecs::WorldManager* worldManager) : System(worldManager)
{
}

TimerRender::~TimerRender() = default;

void TimerRender::update()
{
    auto driver = worldManager->getUniverse()->getDevice()->getVideoDriver();

    for (const auto& entity : entities) {
        auto& timerRender = worldManager->getComponent<ecs::component::TimerRender>(entity);
        auto& image = worldManager->getComponent<ecs::component::Image>(entity);

        auto& timer = worldManager->getComponent<ecs::component::Timer>(timerRender.owner);

        auto diff = timer.delay - timer.elapsed;
        int seconds = static_cast<int>(static_cast<float>(diff) / 1000.f);
        int minutes = static_cast<int>(seconds / 60);
        seconds = seconds % 60;

        if (diff <= 10000) {
            try {
                worldManager->getComponent<ecs::component::Blink>(entity);
            } catch (std::exception &e) {
                auto blinkEntities = worldManager->getEntities<ecs::component::Blink>();

                for(const auto& ent : blinkEntities) {
                    auto& blink = worldManager->getComponent<ecs::component::Blink>(ent);
                    blink.millisecond = 500;
                }
                worldManager->addComponent(entity, ecs::component::Blink(500));
            }
        }
        if (diff == 0) {
            ecs::event::TimerEnd timerEnd;
            worldManager->publish(timerEnd);
        }

        if (timerRender.position == 0) {
            auto texture = driver->getTexture(
                scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(minutes / 10) % 10)
                    .c_str());
            image.image->setImage(texture);
        } else if (timerRender.position == 1) {
            auto texture = driver->getTexture(scene::gamehud::number::INT_TO_IMG.at(minutes % 10).c_str());
            image.image->setImage(texture);
        } else if (timerRender.position == 2) {
            auto texture = driver->getTexture(
                scene::gamehud::number::INT_TO_IMG.at(static_cast<int>(seconds / 10) % 10)
                    .c_str());
            image.image->setImage(texture);
        } else if (timerRender.position == 3) {
            auto texture = driver->getTexture(scene::gamehud::number::INT_TO_IMG.at(seconds % 10).c_str());
            image.image->setImage(texture);
        }
    }
}
