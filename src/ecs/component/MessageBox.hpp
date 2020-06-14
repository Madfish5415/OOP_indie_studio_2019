/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MessageBox.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP
#define OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP

#include <irrlicht.h>

/**
 * @file MessageBox.hpp
 * @brief MessageBox Class
 * @author Lucas.M
 * @version 1.0
 * @date 14 june 2020
 */

/**
 * @namespace ecs
 * @namespace component
 */
namespace ecs::component {

/**
 * @class MessageBox
 * @brief A MessageBox.
 */
class MessageBox {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param gui : A pointer on the GUI environment.
     * @param caption : The caption.
     * @param text : The text.
     * @param modal : If true, all events were blocked.
     * @param flags : Irrlicht flags.
     * @param parent : The parent of the element.
     * @param id : The id of the element.
     * @param image : The image to be displayed.
     */
    MessageBox(irr::gui::IGUIEnvironment* gui = nullptr, const wchar_t* caption = nullptr,
        const wchar_t* text = nullptr, bool modal = true, irr::s32 flags = irr::gui::EMBF_OK,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, irr::video::ITexture* image = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param messageBox1 : Element to be copied.
     */
    MessageBox(const MessageBox& messageBox1);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~MessageBox();

  public:
    irr::gui::IGUIEnvironment* gui; /** < A pointer on the GUI environment. */
    irr::gui::IGUIWindow* messageBox; /** < The message box. */
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_MESSAGEBOX_HPP
