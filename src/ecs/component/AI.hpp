/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#ifndef OOP_INDIE_STUDIO_2019_AI_HPP_
#define OOP_INDIE_STUDIO_2019_AI_HPP_

#include <string>

namespace ecs::component {

class AI {
  public:
    AI();
    ~AI();

  public:
    std::string lastDirection;
};

} // namespace ecs::component

#endif /* !OOP_INDIE_STUDIO_2019_AI_HPP_ */
