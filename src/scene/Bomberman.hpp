/*
** EPITECH PROJECT, 2020
** helloIRR
** File description:
** Bomberman.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
#define OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP

#include <vector>

#include "../ecs/Universe.hpp"
#include "../ecs/component/Player.hpp"

namespace scene {

class Bomberman {
  public:
    Bomberman() = delete;
    ~Bomberman() = delete;

  public:
    static void init(ecs::Universe *universe, std::vector<ecs::component::Player> player, std::vector<std::string> path);
    static void reset();
};

namespace bomberman {
namespace ninja {
const std::string AQUA = "media/ninja/aqua.jpg";
const std::string BLACK = "media/ninja/black.jpg";
const std::string BLUE = "media/ninja/blue.jpg";
const std::string GREEN = "media/ninja/green.jpg";
const std::string PINK = "media/ninja/pink.jpg";
const std::string RED = "media/ninja/red.jpg";
const std::string WHITE = "media/ninja/white.jpg";
const std::string YELLOW = "media/ninja/yellow.jpg";
}
}


}

#endif // OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
