/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Text.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_TEXT_HPP
#define OOP_INDIE_STUDIO_2019_TEXT_HPP

#include <string>

#include "irrlicht.h"

/**
 * @file Text.hpp
 * @brief Text Class
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
 * @class Text
 * @brief A text.
 */
class Text {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param gui : A pointer on the GUI environment.
     * @param text : The text to be displayed.
     * @param rectangle : The size of the text.
     * @param border : Draw text box border.
     * @param wordWrap : The word wrap.
     * @param parent : The parent of the element.
     * @param id : The id of the element.
     * @param fillBackground : True if we need to fill the background.
     */
    Text(irr::gui::IGUIEnvironment* gui = nullptr, const wchar_t* text = L"",
        const irr::core::rect<irr::s32>& rectangle = irr::core::recti(), bool border = false, bool wordWrap = true,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, bool fillBackground = false);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param text : Element to be copied.
     */
    Text(const Text& text);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Text();

  public:
    /**
     * @brief setFont method
     * This method change the font of the text on the button.
     * @param path : Path to the font.
     */
    void setFont(const irr::io::path& path);

  public:
    irr::gui::IGUIEnvironment* gui; /** < A pointer on the GUI environment. */
    irr::gui::IGUIStaticText* text; /** < The text element. */
    irr::gui::IGUIFont* font; /** < The font of the text. */
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_TEXT_HPP
