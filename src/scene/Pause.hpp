/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Pause.hpp
*/

#ifndef INDIESTUDIO_PAUSE_HPP
#define INDIESTUDIO_PAUSE_HPP

#include <irrlicht.h>

#include "../ecs/WorldManager.hpp"

namespace scene {

class Pause {
  public:
    Pause() = delete;
    ~Pause() = delete;

  public:
    static void init(ecs::Universe* universe);
    static void destroy(ecs::Universe* universe);

  public:
    static std::vector<ecs::Entity> buttons;
    static std::vector<ecs::Entity> images;
};

namespace pause {

namespace button {

namespace resume {
const std::string NORMAL = "assets/img/pause/button/button-resume-normal.png";
const std::string HOVER = "assets/img/pause/button/button-resume-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-resume-pressed.png";
} // namespace resume

namespace settings {
const std::string NORMAL = "assets/img/pause/button/button-settings-normal.png";
const std::string HOVER = "assets/img/pause/button/button-settings-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-settings-pressed.png";
} // namespace settings

namespace menu {
const std::string NORMAL = "assets/img/pause/button/button-menu-normal.png";
const std::string HOVER = "assets/img/pause/button/button-menu-hover.png";
const std::string PRESSED = "assets/img/pause/button/button-menu-pressed.png";
} // namespace menu

} // namespace button

static const std::string BACKGROUND = "assets/img/pause/pause.png";

} // namespace pause

} // namespace scene

#endif // INDIESTUDIO_PAUSE_HPP
