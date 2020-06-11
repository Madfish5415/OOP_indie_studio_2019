/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinChecking
*/

#ifndef WINCHECKING_HPP_
#define WINCHECKING_HPP_

#include "../System.hpp"

namespace ecs::system {

class WinChecking : public System {
    public:
        WinChecking(WorldManager *worldManager);
        ~WinChecking() override;

    public:
        void update() override;
};

}

#endif /* !WINCHECKING_HPP_ */
