/*
** rect.hpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 21 01:35:13 2016 Joffrey Escobar
*/

#ifndef _RECT_HPP_
# define _RECT_HPP_

#include "IObject.hpp"

class rect : public IObject
{
public:

  rect(const std::string& name);
  rect(const std::string                     & name,
       const irr::core::position2d<irr::s32> & pos,
       const irr::core::dimension2d<irr::s32>& dimension,
       const irr::video::SColor              & color);
  ~rect();

  /* method */
  bool draw(irr::video::IVideoDriver *driver, const std::string &style = "default");
};

#endif
