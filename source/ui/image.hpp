/*
** image.hpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Fri May 20 18:28:35 2016 Joffrey Escobar
*/

#ifndef _IMAGE_HPP_
# define _IMAGE_HPP_

#include "IObject.hpp"

class image : public IObject
{
public:

  image(const std::string& name);
  image(const std::string& name, irr::video::ITexture *image,
        const irr::core::position2d<irr::s32>& pos);
  ~image();

  /* setter */
  void setImage(irr::video::ITexture *image, const std::string &style = "default");

  /* fluent */
  IObject &texture(irr::video::ITexture *image);

  /* getter */
  irr::video::ITexture* getImage(const std::string &style = "default");

  /* method */
  bool draw(irr::video::IVideoDriver *driver, const std::string &style = "default");
};

#endif
