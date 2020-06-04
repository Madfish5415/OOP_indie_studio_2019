/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.cpp
*/

#include "Image.hpp"

#include "../System.hpp"
#include "../component/Image.hpp"

using namespace ecs::system;

Image::Image(irr::video::IVideoDriver *driver, ecs::WorldManager *worldManager) : driver(driver), ecs::System(worldManager);
{
}

Image::~Image() = default;

void Image::update()
{
    for (const auto& entity : entities) {
        const auto& image = worldManager->getComponent<ecs::component::Image>(entity);
        driver->draw2DImage(image.texture, image.position, image.rect, image.clipRect, image.scolor, image.useAlphaChannelOfTexture);
    }
}