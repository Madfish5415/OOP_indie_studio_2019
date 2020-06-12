/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Settings.hpp
*/

#ifndef INDIESTUDIO_SETTINGS_HPP
#define INDIESTUDIO_SETTINGS_HPP

#include <SFML/Audio.hpp>

#include "../ecs/Universe.hpp"

namespace scene {

class Settings {
  public:
    Settings() = delete;
    ~Settings() = delete;

  public:
    static void init(ecs::Universe *universe, std::shared_ptr<sf::Music> currentMusic);
    static void destroy(ecs::Universe *universe);
    static void updateSoundBar(ecs::Universe *universe);

  public:
    static std::vector<ecs::Entity> buttons;
    static std::vector<ecs::Entity> pushButtons;
    static std::vector<ecs::Entity> images;
    static sf::Music *currentMusic;
    static float soundVolume;
    static float musicVolume;
};

namespace settings {

namespace button {

namespace back {
static const std::string NORMAL = "assets/img/settings/button/button-back-normal.png";
static const std::string HOVER = "assets/img/settings/button/button-back-hover.png";
static const std::string PRESSED = "assets/img/settings/button/button-back-pressed.png";
} // namespace back

namespace plus {
static const std::string NORMAL = "assets/img/settings/button/button-plus-normal.png";
static const std::string HOVER = "assets/img/settings/button/button-plus-hover.png";
static const std::string PRESSED = "assets/img/settings/button/button-plus-pressed.png";
} // namespace plus

namespace minus {
static const std::string NORMAL = "assets/img/settings/button/button-minus-normal.png";
static const std::string HOVER = "assets/img/settings/button/button-minus-hover.png";
static const std::string PRESSED = "assets/img/settings/button/button-minus-pressed.png";
} // namespace minus

} // namespace button

namespace soundbar {
static const std::string sb0 = "assets/img/settings/soundbar0.png";
static const std::string sb10 = "assets/img/settings/soundbar10.png";
static const std::string sb20 = "assets/img/settings/soundbar20.png";
static const std::string sb30 = "assets/img/settings/soundbar30.png";
static const std::string sb40 = "assets/img/settings/soundbar40.png";
static const std::string sb50 = "assets/img/settings/soundbar50.png";
static const std::string sb60 = "assets/img/settings/soundbar60.png";
static const std::string sb70 = "assets/img/settings/soundbar70.png";
static const std::string sb80 = "assets/img/settings/soundbar80.png";
static const std::string sb90 = "assets/img/settings/soundbar90.png";
static const std::string sb100 = "assets/img/settings/soundbar100.png";
} // namespace soundbar

static const std::string BACKGROUND = "assets/img/settings/background.png";
static const std::string MUSICTEXT = "assets/img/settings/music-text.png";
static const std::string SOUNDTEXT = "assets/img/settings/sound-text.png";

static const std::map<float, const std::string> SOUNDBAR = {
    {0, soundbar::sb0},
    {10, soundbar::sb10},
    {20, soundbar::sb20},
    {30, soundbar::sb30},
    {40, soundbar::sb40},
    {50, soundbar::sb50},
    {60, soundbar::sb60},
    {70, soundbar::sb70},
    {80, soundbar::sb80},
    {90, soundbar::sb90},
    {100, soundbar::sb100},
};
} // namespace settings

} // namespace scene
#endif // INDIESTUDIO_SETTINGS_HPP
