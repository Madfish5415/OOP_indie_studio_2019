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
static const std::string THREE = "";
static const std::string TWO = "";
static const std::string ONE = "";
static const std::string GO = "";
static const std::string MUSIC = "";
}
} // namespace scene
#endif // INDIESTUDIO_COUNTDOWN_HPP
