/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Input.hpp
*/

#ifndef INDIESTUDIO_INPUT_HPP
#define INDIESTUDIO_INPUT_HPP

#include "../Event.hpp"

namespace ecs::event {

class Input : public ecs::Event {
  public:
    explicit Input(std::string input);
    ~Input() override;

  public:
    std::string input;
};

} // namespace event

#endif // INDIESTUDIO_INPUT_HPP
