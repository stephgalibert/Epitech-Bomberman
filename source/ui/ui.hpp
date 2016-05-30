/*
** ui.hpp for UI in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu May 19 02:26:10 2016 Joffrey Escobar
*/

#ifndef _UI_HPP_
#define _UI_HPP_

#include <map>
#include <string>
#include <iostream>
#include <irrlicht.h>
#include "image.hpp"
#include "rect.hpp"
#include "text.hpp"
#include "listener.hpp"

class ui
{
public:

  typedef enum  resource
  {
    TEXTURE,
    FONT
  }             resource;

  ui(irr::IrrlichtDevice *device);
  ~ui();

  template<class T>
  T& create(const std::string& name, const std::string& scene = "")
  {
    T *newItem = new T(name);

    if (scene.size()) {
      this->_entities[scene][name].object  = newItem;
      this->_entities[scene][name].index   = 0;
      this->_entities[scene][name].display = "default";
    } else {
      this->_entities[this->_currentScene][name].object  = newItem;
      this->_entities[this->_currentScene][name].index   = 0;
      this->_entities[this->_currentScene][name].display = "default";
    }
    return *newItem;
  }

  template<class T>
  T& get(const std::string& name, const std::string& scene = "")
  {
    T *e;

    if (scene.size()) {
      e = (T *)this->_entities[scene][name].object;
    } else {
      e = (T *)this->_entities[this->_currentScene][name].object;
    }
    return *e;
  }

  bool                  load(resource resource, const std::string& pathname, const std::string& name);

  irr::video::ITexture* getTexture(const std::string& name);
  irr::gui::IGUIFont*   getFont(const std::string& name);

  void                  changeScene(const std::string& scene);
  const std::string&    getScene(void);

  IObject&              operator[](const std::string& key);

  void                  setStyle(const std::string& object, const std::string& style, const std::string& scene = "");
  const std::string&    getStyle(const std::string& object);

  void                  display(std::string scene);
  void                  display(void);

private:

  typedef struct  container
  {
    std::string display;
    IObject    *object;
    int         index;
  }               container;

  irr::video::IVideoDriver *_driver;
  irr::IrrlichtDevice *_device;

  std::map<std::string, std::map<std::string, container> > _entities;
  std::string _currentScene;

  std::map<std::string, irr::video::ITexture *>_texture;
  std::map<std::string, irr::gui::IGUIFont *>_font;
};

#endif // ifndef _UI_HPP_
