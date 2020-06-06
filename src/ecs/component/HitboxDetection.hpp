/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** HitboxDetection
*/

#ifndef HITBOXDETECTION_HPP_
#define HITBOXDETECTION_HPP_

#include <irrlicht.h>

#include <vector>

namespace ecs::component {

class HitboxDetection {
  public:
    explicit HitboxDetection(const std::vector<irr::core::line3df>& rays = std::vector<irr::core::line3df>());
    HitboxDetection(const HitboxDetection& transform);
    ~HitboxDetection();

  public:
    std::vector<irr::core::line3df> rays;
};

} // namespace ecs::component
#endif /* !HITBOXDETECTION_HPP_ */
