/*
** EPITECH PROJECT, 2020
** IndieStudio
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
    static void init(ecs::Universe* universe, std::vector<ecs::component::Player> players,
        std::vector<std::string> paths, std::vector<bool> playerType);
    static void reset();
    static void destroy(ecs::Universe* universe);
    static void createBomb(ecs::WorldManager* worldManager, ecs::Entity playerId, size_t bombRadius, bool wallPass,
        const irr::core::vector3d<irr::f32>& pos);
    static void updateCollision(ecs::WorldManager* worldManager);
    static void createPowerUp(ecs::Universe* universe, irr::core::vector3df position);
    static void createExplosion(ecs::WorldManager* worldManager, irr::u32 delay, const irr::core::vector3df& pos);

  public:
    static std::vector<ecs::Entity> playerIds;
    static std::array<irr::scene::IMetaTriangleSelector*, 4> metaTriangleSelector;
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
} // namespace ninja

namespace bomb {
static const std::string BOMB = "media/bomb/Bomb.obj";
static const std::string TEXTURE = "media/bomb/bomb-neon.png";
} // namespace bomb

namespace map {
static const std::string GROUND = "media/map/neon-ground.png";
static const std::string WALL = "media/map/neon-brick.png";
static const std::string BOX = "media/map/neon-crate.png";
static const std::string BOUNDING_BOX = "media/map/boundingBox.png";
} // namespace map

namespace powerUp {
static const std::string MAX_SPEED = "media/power-up/max-speed.png";
static const std::string BOMB_RADIUS = "media/power-up/bomb-radius.png";
static const std::string MAX_BOMB = "media/power-up/max-bomb.png";
static const std::string WALL_PASS = "media/power-up/wall-pass.png";
} // namespace powerUp

namespace bomb {
static const std::string EXPLOSION = "media/map/portal7.bmp";
} // namespace bomb
} // namespace bomberman
} // namespace scene

#endif // OOP_INDIE_STUDIO_2019_BOMBERMAN_HPP
