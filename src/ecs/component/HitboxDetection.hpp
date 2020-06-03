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

class HitboxDetection {
  public:
    explicit HitboxDetection(const std::vector<irr::core::line3df>& rays);
    ~HitboxDetection();

  public:
    std::vector<irr::core::line3df> rays;
};

#endif /* !HITBOXDETECTION_HPP_ */
