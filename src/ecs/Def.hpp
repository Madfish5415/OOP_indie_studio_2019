/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** def.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_DEF_HPP
#define OOP_INDIE_STUDIO_2019_DEF_HPP

#include <bitset>

/**
 * @file Def.hpp
 * @brief Def File
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs
 */
namespace ecs {

using Entity = unsigned int; /** < Using Entity as unsigned int.*/
const Entity MAX_ENTITIES = 1000; /** < Defined the max number of entities for the project.*/

using ComponentType = unsigned int; /** < Using ComponentType as unsigned int.*/
const ComponentType MAX_COMPONENTS = 64; /** < Defined the max number of components for an entity for the project.*/

using Signature = std::bitset<MAX_COMPONENTS>; /** < Using Signature as std::bitset<MAX_COMPONENTS>.*/
} // namespace ecs

/**
 * @enum BUTTON_ID
 * @brief Enum of button ids.
 */
enum BUTTON_ID {
    GUI_MENU_PLAY = 201, /** < Play menu button id.*/
    GUI_MENU_QUIT, /** < Quit menu button id.*/
    GUI_MENU_HTP, /** < How to play menu button id.*/
    GUI_MENU_SETTINGS, /** < Option menu button id.*/

    GUI_SELECT_MENU, /** < Back to the menu */
    GUI_SELECT_FIGHT, /** < Start the game with selected parameters.*/
    GUI_SELECT_ADD_PLAYER, /** < Add player.*/
    GUI_SELECT_REMOVE_PLAYER, /** < Remove player.*/

    GUI_SELECT_SKIN_P1_LEFT, /** < Button skin change left Player 1.*/
    GUI_SELECT_SKIN_P1_RIGHT, /** < Button skin change right Player 1.*/
    GUI_SELECT_SKIN_P2_LEFT, /** < Button skin change left Player 2.*/
    GUI_SELECT_SKIN_P2_RIGHT, /** < Button skin change right Player 2.*/
    GUI_SELECT_SKIN_P3_LEFT, /** < Button skin change left Player 3.*/
    GUI_SELECT_SKIN_P3_RIGHT, /** < Button skin change right Player 3.*/
    GUI_SELECT_SKIN_P4_LEFT, /** < Button skin change left Player 4.*/
    GUI_SELECT_SKIN_P4_RIGHT, /** < Button skin change right Player 4.*/

    GUI_SELECT_TYPE_P1_LEFT, /** < Button skin change left Player 1.*/
    GUI_SELECT_TYPE_P1_RIGHT, /** < Button skin change right Player 1.*/
    GUI_SELECT_TYPE_P2_LEFT, /** < Button skin change left Player 2.*/
    GUI_SELECT_TYPE_P2_RIGHT, /** < Button skin change right Player 2.*/
    GUI_SELECT_TYPE_P3_LEFT, /** < Button skin change left Player 3.*/
    GUI_SELECT_TYPE_P3_RIGHT, /** < Button skin change right Player 3.*/
    GUI_SELECT_TYPE_P4_LEFT, /** < Button skin change left Player 4.*/
    GUI_SELECT_TYPE_P4_RIGHT, /** < Button skin change right Player 4.*/

    GUI_SELECT_KB_P1, /** < Open Player 1 keybinding window */
    GUI_SELECT_KB_P2, /** < Open Player 2 keybinding window */
    GUI_SELECT_KB_P3, /** < Open Player 3 keybinding window */
    GUI_SELECT_KB_P4, /** < Open Player 4 keybinding window */

    GUI_SELECT_KB_UP, /** < Change UP Key code.*/
    GUI_SELECT_KB_DOWN, /** < Change DOWN Key code.*/
    GUI_SELECT_KB_LEFT, /** < Change LEFT Key code.*/
    GUI_SELECT_KB_RIGHT, /** < Change RIGHT Key code.*/
    GUI_SELECT_KB_ACTION, /** < Change BOMB Key code.*/
    GUI_SELECT_KB_BACK, /** < Back to the player selector */

    GUI_GAME_PAUSE, /** < Open the menu pause */

    GUI_PAUSE_RESUME, /** < Resume the party */
    GUI_PAUSE_SETTINGS, /** < Resume the party */
    GUI_PAUSE_MENU, /** < Back to the menu */

    GUI_SETTINGS_MUSIC_VOL_MINUS, /** < Lower the music volume.*/
    GUI_SETTINGS_MUSIC_VOL_PLUS, /** < Turn up the music volume.*/
    GUI_SETTINGS_SOUND_VOL_MINUS, /** < Lower the sound volume.*/
    GUI_SETTINGS_SOUND_VOL_PLUS, /** < Turn up the sound volume.*/
    GUI_SETTINGS_BACK /** < Back to the menu.*/
};

#endif // OOP_INDIE_STUDIO_2019_DEF_HPP