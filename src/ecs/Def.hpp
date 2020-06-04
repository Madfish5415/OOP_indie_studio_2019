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
const ComponentType MAX_COMPONENTS = 32; /** < Defined the max number of components for an entity for the project.*/

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
    GUI_MENU_OPT, /** < Option menu button id.*/
    GUI_SELECT_VALID, /** < Start the game with selected parameters.*/

    GUI_SELECT_P1, /** < Add player 1.*/
    GUI_SELECT_P2, /** < Add player 2.*/
    GUI_SELECT_P3, /** < Add player 3.*/
    GUI_SELECT_P4, /** < Add player 4.*/

    GUI_SELECT_KB_P1_UP, /** < Change UP Key code for P1.*/
    GUI_SELECT_KB_P1_DOWN, /** < Change DOWN Key code for P1.*/
    GUI_SELECT_KB_P1_LEFT, /** < Change LEFT Key code for P1.*/
    GUI_SELECT_KB_P1_RIGHT, /** < Change RIGHT Key code for P1.*/
    GUI_SELECT_KB_P1_BOMB, /** < Change BOMB Key code for P1.*/

    GUI_SELECT_KB_P2_UP, /** < Change UP Key code for P2.*/
    GUI_SELECT_KB_P2_DOWN, /** < Change DOWN Key code for P2.*/
    GUI_SELECT_KB_P2_LEFT, /** < Change LEFT Key code for P2.*/
    GUI_SELECT_KB_P2_RIGHT, /** < Change RIGHT Key code for P2.*/
    GUI_SELECT_KB_P2_BOMB, /** < Change BOMB Key code for P2.*/

    GUI_SELECT_KB_P3_UP, /** < Change UP Key code for P3.*/
    GUI_SELECT_KB_P3_DOWN, /** < Change DOWN Key code for P3.*/
    GUI_SELECT_KB_P3_LEFT, /** < Change LEFT Key code for P3.*/
    GUI_SELECT_KB_P3_RIGHT, /** < Change RIGHT Key code for P3.*/
    GUI_SELECT_KB_P3_BOMB, /** < Change BOMB Key code for P3.*/

    GUI_SELECT_KB_P4_UP, /** < Change UP Key code for P4.*/
    GUI_SELECT_KB_P4_DOWN, /** < Change DOWN Key code for P4.*/
    GUI_SELECT_KB_P4_LEFT, /** < Change LEFT Key code for P4.*/
    GUI_SELECT_KB_P4_RIGHT, /** < Change RIGHT Key code for P4.*/
    GUI_SELECT_KB_P4_BOMB /** < Change BOMB Key code for P4.*/
};

#endif // OOP_INDIE_STUDIO_2019_DEF_HPP