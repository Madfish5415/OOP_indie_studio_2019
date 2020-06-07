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
    static void init(ecs::Universe *universe, std::vector<ecs::component::Player> players, std::vector<std::string> paths);
    static void reset();
    static void destroy(ecs::Universe *universe);
};

namespace bomberman {
namespace ninja {
static const std::string NINJA = "media/ninja/ninja.b3d";
static const std::string AQUA = "media/ninja/aqua.png";
static const std::string BLACK = "media/ninja/black.png";
static const std::string BLUE = "media/ninja/blue.jpg";
static const std::string GREEN = "media/ninja/green.jpg";
static const std::string PINK = "media/ninja/pink.png";
static const std::string RED = "media/ninja/red.jpg";
static const std::string WHITE = "media/ninja/white.png";
static const std::string YELLOW = "media/ninja/yellow.jpg";

static std::map<const std::string, bool> PLAYER_SKINS = {{AQUA, false}, {BLACK, false}, {BLUE, false}, {GREEN, false},
                                                         {PINK, false}, {RED, false}, {WHITE, false}, {YELLOW, false}};
}
namespace map {
static const std::string GROUND = "media/map/min_grass.png";
static const std::string WALL = "media/map/min_brick.png";
static const std::string BOX = "media/map/box.jpg";
}
}

}

#endif // OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
