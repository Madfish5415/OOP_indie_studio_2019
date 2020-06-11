/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PlayerSelector.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_PLAYERSELECTOR_HPP
#define OOP_INDIE_STUDIO_2019_PLAYERSELECTOR_HPP

#include <irrlicht.h>
#include <SFML/Audio.hpp>

#include "../ecs/WorldManager.hpp"
#include "../ecs/component/Player.hpp"
#include "Bomberman.hpp"

namespace scene {

class PlayerSelector {
  public:
    PlayerSelector() = delete;
    ~PlayerSelector() = delete;

  public:
    static void init(ecs::Universe* universe, sf::Time musicTimer);
    static void destroy(ecs::Universe* universe);
    static void addPlayer(ecs::Universe* universe);
    static void removePlayer(ecs::Universe* universe);
    static void changeSkin(ecs::Universe* universe, irr::s32 id);
    static void changeType(ecs::Universe* universe, irr::s32 id);
    static bool checkKeybinding(ecs::Universe* universe);
    static void invalidKeybinding(ecs::Universe* universe);

  public:
    static std::vector<ecs::Entity> playerIds;
    static std::vector<ecs::Entity> playerKeysIds;
    static std::vector<ecs::Entity> playerSkinButtonLeftIds;
    static std::vector<ecs::Entity> playerSkinButtonRightIds;
    static std::vector<ecs::Entity> playerTypeButtonLeftIds;
    static std::vector<ecs::Entity> playerTypeButtonRightIds;
    static std::vector<ecs::Entity> playerCustomButtonIds;
    static std::vector<ecs::Entity> playerType;
    static std::vector<ecs::component::Player> playerComponent;
    static std::vector<bool> typeList;
    static std::array<irr::video::SColor, 4> bombColors;
    static irr::gui::IGUIElement* modal;
};

namespace playerselector {
namespace button {
namespace back {
static const std::string NORMAL = "assets/img/player-selector/button/button-back-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-back-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-back-pressed.png";
} // namespace back
namespace fight {
static const std::string NORMAL = "assets/img/player-selector/button/button-fight-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-fight-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-fight-pressed.png";
} // namespace fight
namespace add {
static const std::string NORMAL = "assets/img/player-selector/button/button-add-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-add-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-add-pressed.png";
} // namespace add
namespace remove {
static const std::string NORMAL = "assets/img/player-selector/button/button-remove-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-remove-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-remove-pressed.png";
} // namespace remove
namespace keys {
static const std::string NORMAL = "assets/img/player-selector/button/button-keys-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-keys-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-keys-pressed.png";
static const std::string BLOCKED = "assets/img/player-selector/button/button-keys-blocked.png";
} // namespace keys
namespace skin {
namespace left {
static const std::string NORMAL = "assets/img/player-selector/button/button-left-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-left-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-left-pressed.png";
} // namespace left
namespace right {
static const std::string NORMAL = "assets/img/player-selector/button/button-right-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-right-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-right-pressed.png";
} // namespace right
namespace left2 {
static const std::string NORMAL = "assets/img/player-selector/button/button-left2-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-left2-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-left2-pressed.png";
} // namespace left
namespace right2 {
static const std::string NORMAL = "assets/img/player-selector/button/button-right2-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-right2-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-right2-pressed.png";
} // namespace right
} // namespace skin
namespace custom {
static const std::string NORMAL = "assets/img/player-selector/button/button-custom-normal.png";
static const std::string HOVER = "assets/img/player-selector/button/button-custom-hover.png";
static const std::string PRESSED = "assets/img/player-selector/button/button-custom-pressed.png";
}
} // namespace button
namespace player {
static const std::string AQUA = "assets/img/player-selector/player/player-aqua.png";
static const std::string BLACK = "assets/img/player-selector/player/player-black.png";
static const std::string BLUE = "assets/img/player-selector/player/player-blue.png";
static const std::string GREEN = "assets/img/player-selector/player/player-green.png";
static const std::string PINK = "assets/img/player-selector/player/player-pink.png";
static const std::string RED = "assets/img/player-selector/player/player-red.png";
static const std::string WHITE = "assets/img/player-selector/player/player-white.png";
static const std::string YELLOW = "assets/img/player-selector/player/player-yellow.png";

static std::map<const std::string, bool> PLAYER_SKINS = {{AQUA, false}, {BLACK, false}, {BLUE, false}, {GREEN, false},
    {PINK, false}, {RED, false}, {WHITE, false}, {YELLOW, false}};

static std::map<const std::string, const std::string> SKIN_TO_MODEL = {{AQUA, scene::bomberman::ninja::AQUA},
    {BLACK, scene::bomberman::ninja::BLACK}, {BLUE, scene::bomberman::ninja::BLUE},
    {GREEN, scene::bomberman::ninja::GREEN}, {PINK, scene::bomberman::ninja::PINK}, {RED, scene::bomberman::ninja::RED},
    {WHITE, scene::bomberman::ninja::WHITE}, {YELLOW, scene::bomberman::ninja::YELLOW}};

} // namespace player
static const std::string BACKGROUND = "assets/img/player-selector/background.jpg";
static const std::string FRAME = "assets/img/player-selector/neon-frame.png";
static const std::string WARNING = "assets/img/player-selector/warning.png";
static const std::string SELECT_PLAYER = "assets/img/player-selector/select-player.png";
static const std::string SELECT_AI = "assets/img/player-selector/select-ai.png";
static const std::string MUSIC = "assets/music/menu/background.ogg";
} // namespace playerselector

} // namespace scene
#endif // OOP_INDIE_STUDIO_2019_PLAYERSELECTOR_HPP
