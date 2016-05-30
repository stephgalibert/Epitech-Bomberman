/*
** rect.cpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 21 01:35:30 2016 Joffrey Escobar
*/

#include "rect.hpp"

rect::rect(const std::string& name) : IObject(name) {}

rect::rect(const std::string                     & name,
           const irr::core::position2d<irr::s32> & pos,
           const irr::core::dimension2d<irr::s32>& dimension,
           const irr::video::SColor              & color)
  : IObject(pos, color, name)
{
  this->_style["default"]._dimension = dimension;
}

rect::~rect() {}

#include <iostream>

bool rect::draw(irr::video::IVideoDriver *driver, const std::string& style)
{
  if (driver) {
    driver->draw2DRectangle(this->_style[style]._color,
                            irr::core::rect<irr::s32>(this->_style[style]._pos.X,
                                                      this->_style[style]._pos.Y,
                                                      this->_style[style]._pos.X +
                                                      this->_style[style]._dimension.Width,
                                                      this->_style[style]._pos.Y +
                                                      this->_style[style]._dimension.Height));
  }
  return true;
}
