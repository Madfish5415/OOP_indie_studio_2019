/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** HowToPlay.hpp
*/

#ifndef INDIESTUDIO_HOWTOPLAY_HPP
#define INDIESTUDIO_HOWTOPLAY_HPP

#include <SFML/Audio.hpp>

#include "../ecs/Universe.hpp"

namespace scene {

class HowToPlay {
    HowToPlay() = delete;
    ~HowToPlay() = delete;

  public:
    static void init(ecs::Universe *universe, sf::Time musicTimer);
    static void destroy(ecs::Universe *universe);
};

namespace howtoplay {

namespace button {

namespace back {
static const std::string NORMAL = "assets/img/how-to-play/button/button-back-normal.png";
static const std::string HOVER = "assets/img/how-to-play/button/button-back-hover.png";
static const std::string PRESSED = "assets/img/how-to-play/button/button-back-pressed.png";
} // namespace back

} // namespace button

static const std::string BACKGROUND = "assets/img/how-to-play/background.png";
} // namespace howtoplay

} // namespace scene

#endif // INDIESTUDIO_HOWTOPLAY_HPP
