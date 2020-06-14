/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image.hpp
*/

#ifndef OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP
#define OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP

#include <memory>
#include <string>

#include "irrlicht.h"

/**
 * @file Image.hpp
 * @brief Image Class
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
 * @class Image
 * @brief An image.
 */
class Image {
  public:
    /**
     * @brief Constructor
     * Default constructor.
     * @param gui : A pointer on the GUI environment.
     * @param driver : A pointer on the video driver.
     * @param pathTexture : The path to the texture of the image.
     * @param position : The position of the image.
     * @param useAlphaChannelOfTexture : True if we need to use the transparency.
     * @param parent : The parent of the element.
     * @param id : The id of the element.
     */
    Image(irr::gui::IGUIEnvironment* gui = nullptr, irr::video::IVideoDriver* driver = nullptr,
        const std::string& pathTexture = "", irr::core::position2d<irr::s32>* position = nullptr,
        bool useAlphaChannelOfTexture = true, irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1);
    /**
     * @brief Copy Constructor
     * Default copy constructor.
     * @param image : Element to be copied.
     */
    Image(const Image& image);
    /**
     * @brief Destructor
     * Default destructor.
     */
    virtual ~Image();

  public:
    irr::gui::IGUIEnvironment* gui; /** < A pointer on the GUI environment. */
    irr::video::IVideoDriver* driver; /** < A pointer on the video driver. */
    irr::gui::IGUIImage* image; /** < The image. */
    std::string pathTexture; /** < A path to the texture of the image. */
    std::shared_ptr<irr::core::position2d<irr::s32>> position; /** < The position of the image. */
    bool useAlphaChannelOfTexture; /** < True if we need to use the transparency. */
    irr::gui::IGUIElement* parent; /** < The parent of the element. */
    irr::s32 id; /** < The id of the element. */
};

} // namespace ecs::component

#endif // OOP_INDIE_STUDIO_2019_IMAGE_COMP_HPP
