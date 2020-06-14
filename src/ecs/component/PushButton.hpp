/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushPushButton.hpp
*/

#ifndef INDIESTUDIO_PUSHPushButton_HPP
#define INDIESTUDIO_PUSHPushButton_HPP

#include <irrlicht.h>

#include <memory>
#include <string>

/**
 * @file PushButton.hpp
 * @brief PushButton Class
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
 * @class PushButton
 * @brief A push button.
 */
class PushButton {
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
    PushButton(irr::gui::IGUIEnvironment* gui = nullptr, irr::core::rect<irr::s32>* rect = nullptr,
        irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, const wchar_t* text = nullptr,
        const wchar_t* tooltipText = nullptr);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param PushButton : Element to be copied.
     */
    PushButton(const PushButton& PushButton);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~PushButton();

  public:
    /**
     * @brief setFont method
     * This method change the font of the text on the button.
     * @param path : Path to the font.
     */
    void setFont(const irr::io::path& path);
    /**
     * @brief setText method
     * This method change the text on the button.
     * @param text : The text.
     */
    void setText(const std::wstring& text);
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

#endif // INDIESTUDIO_PUSHPushButton_HPP
