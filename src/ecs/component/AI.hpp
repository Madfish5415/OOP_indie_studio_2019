/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#ifndef OOP_INDIE_STUDIO_2019_AI_HPP_
#define OOP_INDIE_STUDIO_2019_AI_HPP_

#include <irrlicht.h>

#include <string>

namespace ecs::component {

class AI {
  public:
    AI();
    AI(const AI& ai);
    virtual ~AI();

  public:
    std::string lastDirection;
    irr::core::vector3d<irr::f32> lastPos;
    irr::core::vector3d<irr::f32> lastEscape;
    std::string lastChoice;
};

} // namespace ecs::component

#endif /* !OOP_INDIE_STUDIO_2019_AI_HPP_ */
