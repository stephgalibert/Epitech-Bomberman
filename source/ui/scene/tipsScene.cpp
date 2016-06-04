/*
** tips.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 04:08:22 2016 Joffrey Escobar
*/

#include "tipsScene.hpp"

tipsScene::tipsScene(ui& ui) : ASubLayout(ui, "tips") {}

tipsScene::~tipsScene() {}

void tipsScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "backButton");
}

void tipsScene::loadScene()
{
  this->_ui.create<rect>("0backgrounDColor")
  .color(0, 22, 30)
  .accros(1920, 1080);

  this->_ui.create<image>("0background")
  .texture(this->_ui.getTexture("background"))
  .alpha(15);

  this->_ui.create<image>("backButton")
  .texture(this->_ui.getTexture("backButton"))
  .at(0, 920);
  this->_ui["backButton"].in("hover")
  .color(170, 245, 245)
  .closeStyle();
}

void tipsScene::updateRuntime()
{
  this->_ui.setStyle("backButton", (this->_ui["backButton"].collision(this->_mousePosition)) ? "hover" : "default");
}

void tipsScene::manageEvent(bbman::InputListener& listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_nextScene = "default";
    }
  }
}
