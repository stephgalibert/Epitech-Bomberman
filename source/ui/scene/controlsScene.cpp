/*
** controls.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Tue May 31 18:12:50 2016 Joffrey Escobar
*/

#include "controlsScene.hpp"

controlsScene::controlsScene(ui& ui) : ASubLayout(ui, "controls") {}

controlsScene::~controlsScene() {}

void controlsScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "backButton");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/controls.png", "controlsPanel");
}

void controlsScene::loadScene()
{
  this->_ui.create<rect>("0backgroundColor")
    .color(0, 22, 30)
    .accros(1920, 1080);

  this->_ui.create<image>("Abackground")
    .texture(this->_ui.getTexture("background"))
    .alpha(15);

  this->_ui.create<image>("controlsPanel")
    .texture(this->_ui.getTexture("controlsPanel"));

  this->_ui.create<image>("backButton")
    .texture(this->_ui.getTexture("backButton"))
    .at(0, 920);

  this->_ui["backButton"].in("hover")
    .color(170, 245, 245)
    .closeStyle();
}

void controlsScene::updateRuntime() {}

void controlsScene::manageEvent(bbman::InputListener &listener)
{
  this->_ui.setStyle("backButton", "default");
  if (listener.getState()){
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_ui.changeScene("default");
    }
  } else if (this->_nextScene == this->_ui.getScene()) {
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_ui.setStyle("backButton", "hover");
    }
  }
}
