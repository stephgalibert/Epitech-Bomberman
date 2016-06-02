/*
** IObject.cpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu May 19 18:47:19 2016 Joffrey Escobar
*/

#include <iostream>
#include "IObject.hpp"

IObject::IObject(const std::string& name)
{
  this->_currentStyle                     = "default";
  this->_style[this->_currentStyle]._name = name;
  this->_style[this->_currentStyle]._color.set(255, 255, 255, 255);
}

IObject::IObject(const irr::core::position2d<irr::s32>& pos,
                 const irr::video::SColor& color, const std::string& name)
{
  this->_currentStyle = "default";
  this->_style[this->_currentStyle]._pos.set(pos);
  this->_style[this->_currentStyle]._color.set(color.getAlpha(), color.getRed(),
                                               color.getGreen(), color.getRed());
  this->_style[this->_currentStyle]._name = name;
}

IObject::~IObject() {}

void IObject::setPosition(int x, int y, const std::string& style)
{
  this->_style[style]._pos.set(x, y);
}

void IObject::setPosition(const irr::core::position2d<irr::s32>& pos, const std::string& style)
{
  this->_style[style]._pos.set(pos);
}

void IObject::setColor(const irr::video::SColor& color, const std::string& style)
{
  this->_style[style]._color.set(color.getAlpha(), color.getRed(),
                                 color.getGreen(), color.getRed());
}

void IObject::setColor(int alpha, int r, int g, int b, const std::string& style)
{
  this->_style[style]._color.set(alpha, r, g, b);
}

void IObject::setDimension(int width, int height, const std::string& style)
{
  this->_style[style]._dimension.set(width, height);
}

void IObject::setDimension(const irr::core::position2d<irr::s32>& dimension, const std::string& style)
{
  this->_style[style]._dimension = dimension;
}

void IObject::setName(const std::string& name, const std::string& style)
{
  this->_style[style]._name = name;
}

void IObject::setAlpha(int alpha, const std::string& style)
{
  this->_style[style]._color.setAlpha(alpha);
}

IObject& IObject::in(const std::string& style)
{
  if (this->_style.find(style) == this->_style.end()) {
    this->createStyle(style);
  }
  this->_currentStyle = style;
  return *this;
}

IObject& IObject::at(int x, int y)
{
  this->_style[this->_currentStyle]._pos.set(x, y);
  return *this;
}

IObject& IObject::x(int x)
{
  this->_style[this->_currentStyle]._pos.X = x;
  return *this;
}

IObject& IObject::y(int y)
{
  this->_style[this->_currentStyle]._pos.Y = y;
  return *this;
}

IObject& IObject::accros(int width, int height)
{
  this->_style[this->_currentStyle]._dimension.set(width, height);
  return *this;
}

IObject& IObject::width(int width)
{
  this->_style[this->_currentStyle]._dimension.Width = width;
  return *this;
}

IObject& IObject::height(int height)
{
  this->_style[this->_currentStyle]._dimension.Height = height;
  return *this;
}

IObject& IObject::color(int r, int g, int b)
{
  this->_style[this->_currentStyle]._color.setRed(r);
  this->_style[this->_currentStyle]._color.setGreen(g);
  this->_style[this->_currentStyle]._color.setBlue(b);
  return *this;
}

IObject& IObject::r(int r)
{
  this->_style[this->_currentStyle]._color.setRed(r);
  return *this;
}

IObject& IObject::g(int g)
{
  this->_style[this->_currentStyle]._color.setGreen(g);
  return *this;
}

IObject& IObject::b(int b)
{
  this->_style[this->_currentStyle]._color.setBlue(b);
  return *this;
}

IObject& IObject::alpha(int alpha)
{
  this->_style[this->_currentStyle]._color.setAlpha(alpha);
  return *this;
}

IObject& IObject::closeStyle()
{
  this->_currentStyle = "default";
  return *this;
}

const irr::core::position2d<irr::s32>& IObject::getPosition(const std::string& style)
{
  return this->_style[style]._pos;
}

const irr::video::SColor& IObject::getColor(const std::string& style)
{
  return this->_style[style]._color;
}

const irr::core::dimension2d<irr::s32>& IObject::getDimension(const std::string& style)
{
  return this->_style[style]._dimension;
}

const std::string& IObject::getName(const std::string& style)
{
  return this->_style[style]._name;
}

int IObject::getAlpha(const std::string& style)
{
  return this->_style[style]._color.getAlpha();
}

bool IObject::collision(irr::core::position2d<irr::s32>pos)
{
  if (pos.X < this->_style["default"]._pos.X || pos.Y<this->_style["default"]._pos.Y ||
                                                      pos.X>this->_style["default"]._pos.X + this->_style["default"]._dimension.Width ||
      pos.Y > this->_style["default"]._pos.Y + this->_style["default"]._dimension.Height) {
    return false;
  } else {
    return true;
  }
}

void IObject::createStyle(const std::string& name)
{
  this->_style[name] = this->_style["default"];
}
