/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Settings.hpp
*/

#ifndef INDIESTUDIO_SETTINGS_HPP
#define INDIESTUDIO_SETTINGS_HPP

#include <SFML/System/Time.hpp>

#include "../ecs/Universe.hpp"

namespace scene {

class Settings {
  public:
    Settings() = delete;
    ~Settings() = delete;

  public:
    static void init(ecs::Universe *universe);
    static void destroy(ecs::Universe *universe);

  public:
    static std::vector<ecs::Entity> buttons;
    static std::vector<ecs::Entity> pushButtons;
    static std::vector<ecs::Entity> images;
    static float soundVolume;
    static float musicVolume;
};

namespace settings {
namespace button {
namespace back {
static const std::string NORMAL = "assets/img/settings/button/button-back-normal.png";
static const std::string HOVER = "assets/img/settings/button/button-back-hover.png";
static const std::string PRESSED = "assets/img/settings/button/button-back-pressed.png";
}
namespace vsync {
static const std::string NORMAL = "";
static const std::string PRESSED = "";
} // namespace vsync
namespace plus {
static const std::string NORMAL = "";
static const std::string HOVER = "";
static const std::string PRESSED = "";
} // namespace plus
namespace minus {
static const std::string NORMAL = "";
static const std::string HOVER = "";
static const std::string PRESSED = "";
} // namespace minus
} // namespace button
static const std::string BACKGROUND = "assets/img/settings/background.png";
} // namespace settings
} // namespace scene
#endif // INDIESTUDIO_SETTINGS_HPP
