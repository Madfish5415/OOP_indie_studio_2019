/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Key
*/

#ifndef OOP_INDIE_STUDIO_2019_KEY_HPP_
#define OOP_INDIE_STUDIO_2019_KEY_HPP_

#include <irrlicht.h>

#include "../Event.hpp"

namespace ecs::event {

class Key : public ecs::Event {
  public:
    Key(const irr::EKEY_CODE &keycode, bool isPressed);
    ~Key() override;

  public:
    irr::EKEY_CODE keycode;
    bool pressed;
};

}

#endif /* !KEY_HPP_ */
