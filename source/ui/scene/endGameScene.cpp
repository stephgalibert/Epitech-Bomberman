/*
** endGameScene.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun Jun 05 09:19:16 2016 Joffrey Escobar
*/

#include "endGameScene.hpp"

endGameScene::endGameScene(ui& ui) : ASubLayout(ui, "endGame") {}

endGameScene::~endGameScene() {}

void endGameScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "endgame/victory.png", "victory");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "endgame/draw.png", "draw");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "endgame/menu.png", "menu");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "endgame/replay.png", "replay");
}

void endGameScene::loadScene()
{
  this->_ui.create<image>("statue")
  .at(700, 0)
  .in("victory").in("draw").closeStyle();

  this->_ui.get<image>("statue").setImage(this->_ui.getTexture("victory"), "victory");
  this->_ui.get<image>("statue").setImage(this->_ui.getTexture("draw"), "draw");

  this->_ui.create<image>("menuButton")
  .texture(this->_ui.getTexture("menu"))
  .at(1500, 800)
  .in("hover")
  .color(200, 200, 200)
  .closeStyle();
}

void endGameScene::updateRuntime()
{
  this->_ui.setStyle("menuButton", (this->_ui["menuButton"].collision(this->_mousePosition)) ? "hover" : "default");
}


void endGameScene::setDraw()
{
  this->_ui.setStyle("statue", "draw");
}

void endGameScene::setVictory()
{
  this->_ui.setStyle("statue", "victory");
}

void endGameScene::manageEvent(bbman::InputListener& listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["menuButton"].collision(listener.getPosition())) {
      this->_nextScene = "default";
    }
  }
}
