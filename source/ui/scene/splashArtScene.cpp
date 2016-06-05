/*
** splashArt.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 04:08:22 2016 Joffrey Escobar
*/

#include "splashArtScene.hpp"

splashArtScene::splashArtScene(ui& ui) : ASubLayout(ui, "splashArt")
{
  this->_time = 0;
}

splashArtScene::~splashArtScene() {}

void splashArtScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "splashArt/logo.png", "splashArt");
}

void splashArtScene::loadScene()
{
  this->_ui.changeScene("splashArt");
  this->_ui.create<rect>("background")
  .color(0, 0, 0)
  .accros(1920, 1080);

  this->_ui.create<image>("splashArt")
  .texture(this->_ui.getTexture("splashArt"));
}

void splashArtScene::updateRuntime()
{
  if (this->_time++ >= 170) {
    this->_nextScene = "default";
  }
}

void splashArtScene::manageEvent(bbman::InputListener& listener) {}
