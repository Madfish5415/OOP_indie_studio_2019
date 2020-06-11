/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** CountDown.hpp
*/

#ifndef INDIESTUDIO_COUNTDOWN_SCENE_HPP
#define INDIESTUDIO_COUNTDOWN_SCENE_HPP

#include "../ecs/Universe.hpp"
namespace scene {

class CountDown {
  public:
    CountDown() = delete;
    ~CountDown() = delete;

  public:
    static void init(ecs::Universe *universe);
    static void destroy(ecs::Universe *universe);

  public:
    static std::vector<ecs::Entity> images;
};
namespace countdown {
static const std::string THREE = "assets/img/countdown/three.png";
static const std::string TWO = "assets/img/countdown/two.png";
static const std::string ONE = "assets/img/countdown/one.png";
static const std::string GO = "assets/img/countdown/go.png";
static const std::string MUSIC = "assets/music/countdown/countdown.wav";
}
} // namespace scene
#endif // INDIESTUDIO_COUNTDOWN_HPP
