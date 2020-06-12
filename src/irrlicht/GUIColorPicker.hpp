/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GUIColorPicker.cpp
*/

#ifndef INDIESTUDIO_GUICOLORPICKER_HPP
#define INDIESTUDIO_GUICOLORPICKER_HPP

#ifndef _WIN32
#include <irrlicht/IGUIElement.h>
#include <irrlicht/S3DVertex.h>
#else
#include <IGUIElement.h>
#include <S3DVertex.h>
#endif

namespace irr {
namespace gui {
class IGUIButton;
class IGUIStaticText;
class IGUIScrollBar;

class GUIColorPicker : public IGUIElement {
  public:
    GUIColorPicker(IGUIEnvironment *environment, IGUIElement *parent, s32 id = 0, int idx = 0) noexcept;
    ~GUIColorPicker() noexcept;

    virtual void setRelativePosition(const core::recti &r);

    virtual bool OnEvent(const SEvent &) noexcept;
    virtual void updateAbsolutePosition();

    virtual void setPickedColor(const video::SColor &) noexcept;
    virtual const video::SColor &getPickedColor() const noexcept;

    virtual void setBackgroundColor(const video::SColor &) noexcept;
    virtual const video::SColor &getBackgroundColor() const noexcept;

    virtual void draw();

  protected:
    bool isGradient, isColor, isInside;
    virtual void recalculatePickedColor() noexcept;
    virtual void createAlphaTexture() noexcept;
    virtual void createGradientTexture() noexcept;

  public:
    int idx;

  protected:
    IGUIButton *close;
    IGUIScrollBar *scroll;
    video::ITexture *img[2];

  protected:
    video::SColor pickcolor, color;
    video::SColor background, white, black, alpha;
    core::recti box, pickbox, gradient;
    core::vector2di pickpos;
    int colorpos;
};
} // namespace gui
} // namespace irr

#endif // INDIESTUDIO_GUICOLORPICKER_HPP
