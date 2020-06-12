/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** PushPushButton.hpp
*/

#ifndef INDIESTUDIO_PUSHPushButton_HPP
#define INDIESTUDIO_PUSHPushButton_HPP

#include <string>
#include <memory>

#include <irrlicht.h>

namespace ecs::component {

class PushButton {
  public:
    PushButton(irr::gui::IGUIEnvironment* gui = nullptr, irr::core::rect<irr::s32>* rect = nullptr,
           irr::gui::IGUIElement* parent = nullptr, irr::s32 id = -1, const wchar_t* text = nullptr,
           const wchar_t* tooltipText = nullptr);
    PushButton(const PushButton& PushButton);
    ~PushButton();

    void setFont(const irr::io::path& path);
    void setText(const std::wstring& text);
    void setImage(irr::video::ITexture* image);
    void setHoverImage(irr::video::ITexture* image);
    void setPressedImage(irr::video::ITexture* image);

  public:
    irr::gui::IGUIEnvironment* gui;
    std::shared_ptr<irr::core::rect<irr::s32>> rect;
    irr::gui::IGUIElement* parent;
    irr::s32 id;
    const wchar_t* text;
    const wchar_t* tooltipText;
    irr::gui::IGUIButton* button;
    irr::gui::IGUIFont* font;
    irr::video::ITexture *normalImage;
    irr::video::ITexture *hoverImage;
};

} // namespace ecs::component

#endif // INDIESTUDIO_PUSHPushButton_HPP
