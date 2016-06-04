/*
** echapScene.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Fri Jun 03 22:23:44 2016 Joffrey Escobar
*/

#include "echapScene.hpp"

echapScene::echapScene(ui& ui) : ASubLayout(ui, "echap") {}

echapScene::~echapScene() {}

void echapScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "echap/labelPause.png", "labelPause");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "echap/menu.png", "menu");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "echap/resume.png", "resume");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "echap/save.png", "save");
}

void echapScene::loadScene()
{
  this->_ui.create<rect>("0backgroundColor")
    .color(0, 22, 30)
    .accros(1920, 1080)
    .alpha(100);

  this->_ui.create<image>("label")
    .texture(this->_ui.getTexture("labelPause"))
    .at(750, 300);

  this->_ui.create<image>("resume")
    .texture(this->_ui.getTexture("resume"))
    .at(825, 450);

  this->_ui.create<image>("menu")
    .texture(this->_ui.getTexture("menu"))
    .at(825, 560);

  this->_ui.create<image>("save")
    .texture(this->_ui.getTexture("save"))
    .at(825, 670);
}

void echapScene::updateRuntime()
{

}

void echapScene::manageEvent(bbman::InputListener &listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["resume"].collision(this->_mousePosition)) {
      this->_resume = true;
      this->_ui.changeScene("game");
    }
    if (this->_ui["save"].collision(this->_mousePosition)) {
      this->_save = true;
      this->_ui.changeScene("game");
    }
    if (this->_ui["menu"].collision(this->_mousePosition)) {
      this->_ui.changeScene("default");
      this->_menu = true;
    }
  }
}

void echapScene::reset(void)
{
  this->_resume = false;
  this->_save = false;
  this->_menu = false;
}

bool echapScene::isResuming(void) const
{
  return (this->_resume);
}

bool echapScene::isSaving(void) const
{
  return (this->_save);
}

bool echapScene::isMenuing(void) const
{
  return (this->_menu);
}
