/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_BUTTON_COMP_HPP
#define OOP_INDIE_STUDIO_2019_BUTTON_COMP_HPP

#include <irrlicht.h>

#include <memory>
#include <string>

/**
 * @file Button.hpp
 * @brief Button Class
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
 * @class Button
 * @brief A button.
 */
class Button {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param gui : A pointer on the GUI environment.
     * @param rect : The rect of the button.
     * @param parent : The parent of the button.
     * @param id : The id of the button.
     * @param text : The text to display on the button.
     * @param tooltipText : The tooltipText to display on the button.
     */
    Button(irr::gui::IGUIEnvironment* gui = nullptr, irr::core::rect<irr::s32>* rect = nullptr,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, const wchar_t* text = nullptr,
        const wchar_t* tooltipText = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param button : Element to be copied.
     */
    Button(const Button& button);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Button();

  public:
    /**
     * @brief setFont method
     * This method change the font of the text on the button.
     * @param path : Path to the font.
     */
    void setFont(const irr::io::path& path);
    /**
     * @brief setImage method
     * This method change the normal image of the button.
     * @param image : The image.
     */
    void setImage(irr::video::ITexture* image);
    /**
     * @brief setHoverImage method
     * This method change the hover image of the button.
     * @param image : The image.
     */
    void setHoverImage(irr::video::ITexture* image);
    /**
     * @brief setPressedImage method
     * This method change the pressed image of the button.
     * @param image : The image.
     */
    void setPressedImage(irr::video::ITexture* image);

  public:
    irr::gui::IGUIEnvironment* gui; /** < A pointer on the GUI environment. */
    std::shared_ptr<irr::core::rect<irr::s32>> rect; /** < The rect of the button. */
    irr::gui::IGUIElement* parent; /** < The button's parent. */
    irr::s32 id; /** < The button's id. */
    const wchar_t* text; /** < The button's text. */
    const wchar_t* tooltipText; /** < The tooltip Text. */
    irr::gui::IGUIButton* button; /** < The button. */
    irr::gui::IGUIFont* font; /** < The font. */
    irr::video::ITexture* normalImage; /** < The normal image. */
    irr::video::ITexture* hoverImage; /** < The hover image. */
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_BUTTON_COMP_HPP
