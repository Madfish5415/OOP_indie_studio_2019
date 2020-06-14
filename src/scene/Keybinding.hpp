/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Kebinding.hpp
*/

#ifndef INDIESTUDIO_KEBINDING_HPP
#define INDIESTUDIO_KEBINDING_HPP

#include <irrlicht.h>

#include <map>
#include <string>

#include "../ecs/Universe.hpp"
#include "../ecs/component/Player.hpp"

/**
 * @file Keybinding.hpp
 * @brief Keybinding Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace scene
 */
namespace scene {

/**
 * @class Keybinding
 * @brief Handle the Keybinding scene.
 */
class Keybinding {
  public:
    /**
     * @brief Constructor
     * Delete to avoid the construction of the class.
     */
    Keybinding() = delete;
    /**
     * @brief Destructor
     * Delete to avoid the destruction of the class.
     */
    ~Keybinding() = delete;

  public:
    /**
     * @brief init method
     * This method create the whole Keybinding scene.
     * @param universe : A pointer on the universe.
     * @param pathTexture : The current skin of the player.
     * @param ply : A pointer to a player component that contains the last player's key assignment.
     */
    static void init(ecs::Universe* universe, const std::string& pathTexture, ecs::component::Player* ply);
    /**
     * @brief destroy method
     * This method destroy the whole Keybinding scene.
     * @param universe : A pointer on the universe.
     */
    static void destroy(ecs::Universe* universe);

  public:
    static ecs::component::Player*
        player; /** < A pointer to a player component that contains the last player's key assignment. */
    static std::vector<ecs::Entity> buttons; /** < List of all used buttons on this scene. */
    static std::vector<ecs::Entity> pushButtons; /** < List of all used push buttons on this scene. */
    static std::vector<ecs::Entity> images; /** < List of all used images on this scene. */
};

namespace keybinding {

namespace button {

namespace key {
const std::string NORMAL = "assets/img/keybinding/button/button-key-normal.png";
const std::string PRESSED = "assets/img/keybinding/button/button-key-pressed.png";
} // namespace key

namespace back {
const std::string NORMAL = "assets/img/keybinding/button/button-back-normal.png";
const std::string HOVER = "assets/img/keybinding/button/button-back-hover.png";
const std::string PRESSED = "assets/img/keybinding/button/button-back-pressed.png";
} // namespace back

} // namespace button

const std::string BACKGROUND = "assets/img/keybinding/background-keys.png";
const std::string BLACKFILTER = "assets/img/keybinding/black-filter.png";
const std::string FONT = "assets/font/keybinding/karmatic_arcadev2.xml";
} // namespace keybinding

static std::map<irr::EKEY_CODE, std::wstring> KEYBINDING_MAP = {{irr::EKEY_CODE::KEY_DELETE, L"DLT"},
    {irr::EKEY_CODE::KEY_TAB, L"TAB"}, {irr::EKEY_CODE::KEY_KEY_A, L"A"}, {irr::EKEY_CODE::KEY_KEY_B, L"B"},
    {irr::EKEY_CODE::KEY_KEY_C, L"C"}, {irr::EKEY_CODE::KEY_KEY_D, L"D"}, {irr::EKEY_CODE::KEY_KEY_E, L"E"},
    {irr::EKEY_CODE::KEY_KEY_F, L"F"}, {irr::EKEY_CODE::KEY_KEY_G, L"G"}, {irr::EKEY_CODE::KEY_KEY_H, L"H"},
    {irr::EKEY_CODE::KEY_KEY_I, L"I"}, {irr::EKEY_CODE::KEY_KEY_J, L"J"}, {irr::EKEY_CODE::KEY_KEY_K, L"K"},
    {irr::EKEY_CODE::KEY_KEY_L, L"L"}, {irr::EKEY_CODE::KEY_KEY_M, L"M"}, {irr::EKEY_CODE::KEY_KEY_N, L"N"},
    {irr::EKEY_CODE::KEY_KEY_O, L"O"}, {irr::EKEY_CODE::KEY_KEY_P, L"P"}, {irr::EKEY_CODE::KEY_KEY_Q, L"Q"},
    {irr::EKEY_CODE::KEY_KEY_R, L"R"}, {irr::EKEY_CODE::KEY_KEY_S, L"S"}, {irr::EKEY_CODE::KEY_KEY_T, L"T"},
    {irr::EKEY_CODE::KEY_KEY_U, L"U"}, {irr::EKEY_CODE::KEY_KEY_V, L"V"}, {irr::EKEY_CODE::KEY_KEY_W, L"W"},
    {irr::EKEY_CODE::KEY_KEY_X, L"X"}, {irr::EKEY_CODE::KEY_KEY_Y, L"Y"}, {irr::EKEY_CODE::KEY_KEY_Z, L"Z"},
    {irr::EKEY_CODE::KEY_LSHIFT, L"SHF"}, {irr::EKEY_CODE::KEY_RSHIFT, L"SHF"}, {irr::EKEY_CODE::KEY_SPACE, L"SPC"},
    {irr::EKEY_CODE::KEY_LCONTROL, L"CTR"}, {irr::EKEY_CODE::KEY_MULTIPLY, L"*"}, {irr::EKEY_CODE::KEY_NUMLOCK, L"LCK"},
    {irr::EKEY_CODE::KEY_NUMPAD1, L"1"}, {irr::EKEY_CODE::KEY_NUMPAD2, L"2"}, {irr::EKEY_CODE::KEY_NUMPAD3, L"3"},
    {irr::EKEY_CODE::KEY_NUMPAD4, L"4"}, {irr::EKEY_CODE::KEY_NUMPAD5, L"5"}, {irr::EKEY_CODE::KEY_NUMPAD6, L"6"},
    {irr::EKEY_CODE::KEY_NUMPAD7, L"7"}, {irr::EKEY_CODE::KEY_NUMPAD8, L"8"}, {irr::EKEY_CODE::KEY_NUMPAD9, L"9"},
    {irr::EKEY_CODE::KEY_NUMPAD0, L"0"}, {irr::EKEY_CODE::KEY_DOWN, L"DWN"}, {irr::EKEY_CODE::KEY_UP, L"UP"},
    {irr::EKEY_CODE::KEY_LEFT, L"LFT"}, {irr::EKEY_CODE::KEY_RIGHT, L"RIG"}, {irr::EKEY_CODE::KEY_F1, L"F1"},
    {irr::EKEY_CODE::KEY_F2, L"F2"}, {irr::EKEY_CODE::KEY_F3, L"F3"}, {irr::EKEY_CODE::KEY_F4, L"F4"},
    {irr::EKEY_CODE::KEY_F5, L"F5"}, {irr::EKEY_CODE::KEY_F6, L"F6"}, {irr::EKEY_CODE::KEY_F7, L"F7"},
    {irr::EKEY_CODE::KEY_F8, L"F8"}, {irr::EKEY_CODE::KEY_F9, L"F9"}, {irr::EKEY_CODE::KEY_F10, L"F10"},
    {irr::EKEY_CODE::KEY_F11, L"F11"}, {irr::EKEY_CODE::KEY_F12, L"F12"}};
} // namespace scene

#endif // INDIESTUDIO_KEBINDING_HPP
