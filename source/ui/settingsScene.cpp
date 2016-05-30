/*
** settingsScene.cpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 03:00:20 2016 Joffrey Escobar
*/

#include "settingsScene.hpp"

settingsScene::settingsScene(ui& ui) : ASubLayout(ui, "settings") {}

settingsScene::~settingsScene() {}

void settingsScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/label_back.png", "labelBack");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/back.png", "back");
  this->_ui.load(ui::FONT, MEDIAPATH "main/tron48.bmp", "tron48");
}

void settingsScene::loadScene()
{
  this->_ui.create<image>("backBackground")
  .texture(this->_ui.getTexture("labelBack"))
  .at(0, 920);

  this->_ui.create<image>("backText")
  .texture(this->_ui.getTexture("back"))
  .color(0, 0, 0)
  .at(100, 970);
}

void settingsScene::updateRuntime() {}

void settingsScene::manageEvent(bbman::InputListener &listener)
{
  if (listener.getState()){
    if (this->_ui["backBackground"].collision(listener.getPosition())){
      this->_nextScene = "default";
    }
  }
}
