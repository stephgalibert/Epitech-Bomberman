/*
** IObject.hpp for UI in /home/escoba_j/06.2DGraphics/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu May 19 03:10:53 2016 Joffrey Escobar
*/

#ifndef _IOBJECT_HPP_
# define _IOBJECT_HPP_

#include <string>
#include <map>
#include <irrlicht.h>

class IObject
{
public:

  IObject(const std::string& name);
  IObject(const irr::core::position2d<irr::s32>& pos,
          const irr::video::SColor& color, const std::string& name);
  ~IObject();

  /* setter */
  void setPosition(const irr::core::position2d<irr::s32>& pos,
                   const std::string                    & style = "default");
  void setPosition(int x, int y, const std::string& style = "default");
  void setColor(const irr::video::SColor& color, const std::string& style = "default");
  void setColor(int alpha, int r, int g, int b, const std::string& style = "default");
  void setDimension(int width, int lenght, const std::string& style = "default");
  void setDimension(const irr::core::position2d<irr::s32>& dimension,
                    const std::string                    & style = "default");
  void setName(const std::string& name, const std::string& style = "default");
  void setAlpha(int alpha, const std::string& style = "default");

  /* fluent */
  IObject& in(const std::string& style);
  IObject& at(int x, int y);
  IObject& x(int x);
  IObject& y(int y);
  IObject& accros(int width, int height);
  IObject& width(int width);
  IObject& height(int height);
  IObject& color(int r, int g, int b);
  IObject& r(int r);
  IObject& g(int g);
  IObject& b(int b);
  IObject& alpha(int alpha);
  IObject& closeStyle();

  /* getter */
  const irr::core::position2d<irr::s32>&  getPosition(const std::string& style = "default");
  const irr::video::SColor&               getColor(const std::string& style = "default");
  const irr::core::dimension2d<irr::s32>& getDimension(const std::string& style = "default");
  const std::string&                      getName(const std::string& style = "default");
  int                                     getAlpha(const std::string& style = "default");

  /* converter */
  //rect &toText();

  /* methode */
  bool         collision(irr::core::position2d<irr::s32>pos);
  virtual bool draw(irr::video::IVideoDriver *driver,
                    const std::string       & style = "default") = 0;
  void         createStyle(const std::string& name);

protected:

  typedef struct                    style
  {
    std::string                     _name;
    irr::core::position2d<irr::s32> _pos;
    irr::core::dimension2d<irr::s32>_dimension;
    irr::video::SColor              _color;
    irr::gui::IGUIFont             *_font;
    std::string                     _msg;
    irr::video::ITexture           *_image;
  }                                style;

  std::map<std::string, style> _style;
  std::string                  _currentStyle;
};

#endif /* _IOBJECT_HPP_ */
