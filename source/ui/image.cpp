/*
** image.cpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Fri May 20 18:26:46 2016 Joffrey Escobar
*/

#include "image.hpp"

image::image(const std::string& name) : IObject(name)
{
  this->_style["default"]._image = NULL;
}

image::image(const std::string& name, irr::video::ITexture *image,
             const irr::core::position2d<irr::s32>& pos)
  : IObject(pos, irr::video::SColor(255, 255, 255, 255), name)
{
  this->_style["default"]._dimension = image->getSize();
  this->_style["default"]._image     = image;
}

image::~image() {}

/* setter */
#include <iostream>
void image::setImage(irr::video::ITexture *image, const std::string& style)
{
  this->_style[style]._image     = image;
  if (image) {
    this->_style[style]._dimension = image->getSize();
  }
}

IObject &image::texture(irr::video::ITexture *image)
{
  this->_style[this->_currentStyle]._image     = image;
  if (image)
    this->_style[this->_currentStyle]._dimension = image->getSize();
  return *this;
}

/* getter */
irr::video::ITexture * image::getImage(const std::string& style)
{
  return this->_style[style]._image;
}

bool image::draw(irr::video::IVideoDriver *driver, const std::string& style)
{
  if (this->_style[style]._image) {
    driver->draw2DImage(this->_style[style]._image, this->_style[style]._pos,
                        irr::core::rect<irr::s32>(0, 0, this->_style[style]._dimension.Width,
                                                  this->_style[style]._dimension.Height),
                        0, this->_style[style]._color, true);
    return true;
  }
  return false;
}
