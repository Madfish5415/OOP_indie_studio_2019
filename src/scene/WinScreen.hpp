/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WinScreen
*/

#ifndef WINSCREEN_HPP_
#define WINSCREEN_HPP_

#include "../ecs/WorldManager.hpp"
#include "irrlicht.h"

namespace scene {

class WinScreen {
  public:
    WinScreen() = delete;
    ~WinScreen() = delete;

  public:
    static void init(ecs::Universe* universe, const std::string& skinPath);
    static void destroy(ecs::Universe* universe);
};

namespace winscreen {
namespace win {
namespace aqua {
static const std::string PLAYER = "assets/img/win-screen/aqua/aqua.png";
static const std::string TEXT = "assets/img/win-screen/aqua/aqua_textbox.png";
static const std::string WON = "assets/img/win-screen/aqua/aqua_won.png";
}
namespace black {
static const std::string PLAYER = "assets/img/win-screen/black/black.png";
static const std::string TEXT = "assets/img/win-screen/black/black_textbox.png";
static const std::string WON = "assets/img/win-screen/black/black_won.png";
}
namespace blue {
static const std::string PLAYER = "assets/img/win-screen/blue/blue.png";
static const std::string TEXT = "assets/img/win-screen/blue/blue_textbox.png";
static const std::string WON = "assets/img/win-screen/blue/blue_won.png";
}
namespace green {
static const std::string PLAYER = "assets/img/win-screen/green/green.png";
static const std::string TEXT = "assets/img/win-screen/green/green_textbox.png";
static const std::string WON = "assets/img/win-screen/green/green_won.png";
}
namespace pink {
static const std::string PLAYER = "assets/img/win-screen/pink/pink.png";
static const std::string TEXT = "assets/img/win-screen/pink/pink_textbox.png";
static const std::string WON = "assets/img/win-screen/pink/pink_won.png";
}
namespace red {
static const std::string PLAYER = "assets/img/win-screen/red/red.png";
static const std::string TEXT = "assets/img/win-screen/red/red_textbox.png";
static const std::string WON = "assets/img/win-screen/red/red_won.png";
}
namespace white {
static const std::string PLAYER = "assets/img/win-screen/white/white.png";
static const std::string TEXT = "assets/img/win-screen/white/white_textbox.png";
static const std::string WON = "assets/img/win-screen/white/white_won.png";
}
namespace yellow {
static const std::string PLAYER = "assets/img/win-screen/yellow/yellow.png";
static const std::string TEXT = "assets/img/win-screen/yellow/yellow_textbox.png";
static const std::string WON = "assets/img/win-screen/yellow/yellow_won.png";
}
namespace draw {
static const std::string PLAYERS_LEFT = "assets/img/win-screen/draw/draw_left.png";
static const std::string PLAYERS_RIGHT = "assets/img/win-screen/draw/draw_right.png";
static const std::string TEXT = "assets/img/win-screen/draw/draw_textbox.png";
static const std::string WON = "assets/img/win-screen/draw/draw.png";
}
}
namespace slide {
static const std::string BACK = "assets/img/win-screen/slide-back.png";
static const std::string MIDDLE = "assets/img/win-screen/slide-middle.png";
static const std::string FRONT = "assets/img/win-screen/slide-front.png";
};
static const std::string BACKGROUND = "assets/img/win-screen/background.png";
} // namespace winscreen
} // namespace scene
#endif /* !WINSCREEN_HPP_ */