/*
** text.cpp for 06.2DGraphics in /home/escoba_j/Downloads/irrlicht-1.8.3/examples/06.2DGraphics/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu May 19 20:35:13 2016 Joffrey Escobar
*/

#include "text.hpp"

text::text(const std::string& name) : IObject(name)
{
  this->_style["default"]._font = NULL;
}

text::text(const std::string& name, const std::string& msg,
           irr::gui::IGUIFont *font,
           const irr::core::position2d<irr::s32>& pos,
           const irr::video::SColor& color) : IObject(pos, color, name)
{
  this->_style["default"]._font = font;
  this->_style["default"]._msg  = msg;
}

text::~text() {}

#include <iostream>
void text::setMsg(const std::string& msg, const std::string& style)
{
  this->_style[style]._msg = msg;
}

void text::setFont(irr::gui::IGUIFont *font, const std::string& style)
{
  this->_style[style]._font = font;
}

text &text::msg(const std::string &msg)
{
  this->_style[this->_currentStyle]._msg = msg;
  return *this;
}

text &text::font(irr::gui::IGUIFont *font)
{
  this->_style[this->_currentStyle]._font = font;
  return *this;
}

const std::string &text::getMsg(const std::string& style)
{
  return this->_style[style]._msg;
}

bool text::draw(irr::video::IVideoDriver *driver, const std::string& style)
{
  if (this->_style[style]._font) {
    this->_style[style]._font->draw(this->_style[style]._msg.c_str(), irr::core::rect<irr::s32>
                        (this->_style[style]._pos.X, this->_style[style]._pos.Y, 0, 0), this->_style[style]._color);
    return true;
  }
  return false;
}
