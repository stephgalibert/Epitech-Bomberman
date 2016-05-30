/*
** text.hpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu May 19 03:26:51 2016 Joffrey Escobar
*/

#ifndef _TEXT_HPP_
# define _TEXT_HPP_

#include "IObject.hpp"

class text : public IObject
{
public:

  text(const std::string& name);
  text(const std::string& name, const std::string& msg,
       irr::gui::IGUIFont *font,
       const irr::core::position2d<irr::s32>& pos,
       const irr::video::SColor& color);
  ~text();

  /* setter */
  void setMsg(const std::string& msg, const std::string& style = "default");
  void setFont(irr::gui::IGUIFont *font, const std::string& style = "default");

  /* fluent */
  text &msg(const std::string &msg);
  text &font(irr::gui::IGUIFont *font);

  /* getter */
  const std::string &getMsg(const std::string& style = "default");

  /* method */
  bool draw(irr::video::IVideoDriver *driver, const std::string& style = "default");
};

#endif
