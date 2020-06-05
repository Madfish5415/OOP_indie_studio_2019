/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_CORE_HPP
#define OOP_INDIE_STUDIO_2019_CORE_HPP

#include "../ecs/Universe.hpp"

namespace core {
    class Core {
      public:
        Core();
        ~Core();

        void init();
        void run();

      private:
        std::unique_ptr<ecs::Universe> _universe;
    };
}

#endif // OOP_INDIE_STUDIO_2019_CORE_HPP
