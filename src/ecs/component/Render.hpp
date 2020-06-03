/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Render.hpp
*/

#ifndef INDIESTUDIO_COMP_RENDER_HPP
#define INDIESTUDIO_COMP_RENDER_HPP

namespace ecs::component {

class Render {
  public:
    Render(const char& sprite = 'P');
    Render(const Render& render);
    ~Render();

  public:
    char sprite;
};

} // namespace ecs::component

#endif // INDIESTUDIO_COMP_RENDER_HPP
