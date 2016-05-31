/*
** ui.cpp for ui in /home/escoba_j/class
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 21 23:34:31 2016 Joffrey Escobar
*/

#include "ui.hpp"

ui::ui(irr::IrrlichtDevice *device)
{
  this->_device = device;
  this->_driver = NULL;
  if (this->_device) {
    this->_driver = this->_device->getVideoDriver();
  }

  if (this->_driver) {
    this->_driver->getMaterial2D(). TextureLayer[0].BilinearFilter = true;
    this->_driver->getMaterial2D(). AntiAliasing                   = irr::video::EAAM_FULL_BASIC;
  }
  this->_currentScene = "default";
}

ui::~ui() {}

bool ui::load(ui::resource resource, const std::string& pathname, const std::string& name)
{
  switch (resource) {
  case TEXTURE:

    if ((this->_texture[name] = this->_driver->getTexture(pathname.c_str())) == NULL) {
      return false;
    }
    return true;

    break;

  case FONT:

    if ((this->_font[name] = this->_device->getGUIEnvironment()->getFont(pathname.c_str())) == NULL) {
      return false;
    }
    return true;

    break;

  default:
    return false;

    break;
  }
}

irr::video::ITexture * ui::getTexture(const std::string& name)
{
  if (this->_texture.find(name) == this->_texture.end()) {
    return NULL;
  } else {
    return this->_texture[name];
  }
}

irr::gui::IGUIFont * ui::getFont(const std::string& name)
{
  if (this->_font.find(name) == this->_font.end()) {
    return NULL;
  } else {
    return this->_font[name];
  }
}

void ui::changeScene(const std::string& scene)
{
  this->_currentScene = scene;
}

const std::string     &ui::getScene(void)
{
  return this->_currentScene;
}

IObject& ui::operator[](const std::string& key)
{
  if (this->_entities[this->_currentScene].find(key) != this->_entities[this->_currentScene].end()) {
    return *this->_entities[this->_currentScene][key].object;
  }
  IObject *t = new text("undefined");
  return *t;
}

void ui::display(void)
{
  for (auto const& it : this->_entities[this->_currentScene]) {
    it.second.object->draw(this->_driver, it.second.display);
  }
}

void ui::display(std::string scene)
{
  for (auto const& it : this->_entities[scene]) {
    it.second.object->draw(this->_driver, it.second.display);
  }
}

void ui::setStyle(const std::string& object, const std::string& style, const std::string& scene)
{
  if (scene.size()) {
    this->_entities[scene][object].display = style;
  } else {
    this->_entities[this->_currentScene][object].display = style;
  }
}

const std::string& ui::getStyle(const std::string& object)
{
  return this->_entities[this->_currentScene][object].display;
}
