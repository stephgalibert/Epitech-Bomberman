/*
** gameScene.cpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Mon May 30 17:42:22 2016 Joffrey Escobar
*/

#include "gameScene.hpp"

gameScene::gameScene(ui& ui) : ASubLayout(ui, "game") {
}

gameScene::~gameScene() {}

void gameScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "hud/bleu.png", "bleu");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "hud/green.png", "green");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "hud/orange.png", "orange");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "hud/purple.png", "purple");

  this->_ui.load(ui::FONT, MEDIAPATH "hud/megatron26.bmp", "m26");
  this->_ui.load(ui::FONT, MEDIAPATH "hud/megatron26.bmp", "m36");
  this->_ui.load(ui::FONT, MEDIAPATH "hud/megatronC20.bmp", "mc20");
  this->_ui.load(ui::FONT, MEDIAPATH "hud/megatronC48.bmp", "mc48");
}

void gameScene::loadScene()
{
  this->loadRessources();
  this->_ui.create<image>("persoGreen")
  .texture(this->_ui.getTexture("green"))
  .at(25, 150);

  this->_ui.create<image>("persoPurple")
  .texture(this->_ui.getTexture("purple"))
  .at(25, 25);

  this->_ui.create<image>("persoBleu")
  .texture(this->_ui.getTexture("bleu"))
  .at(1800, 25);

  this->_ui.create<image>("persoOrange")
  .texture(this->_ui.getTexture("orange"))
  .at(1800, 150);

  this->_ui.create<text>("mainTimer")
  .font(this->_ui.getFont("mc48"))
  .msg("00:00")
  .color(255, 255, 255)
  .at(860, 0);

  this->_ui.create<text>("alerte")
  .font(this->_ui.getFont("m26"))
  .msg("0:00")
  .color(255, 75, 75)
  .at(925, 65);

  this->_ui.create<text>("scoreP0")
  .font(this->_ui.getFont("m36"))
  .msg("0")
  .at(150, 55);

  this->_ui.create<text>("scoreP1")
  .font(this->_ui.getFont("m36"))
  .msg("0")
  .at(150, 175);

  this->_ui.create<text>("scoreP2")
  .font(this->_ui.getFont("m36"))
  .msg("0")
  .at(1720, 55);

  this->_ui.create<text>("scoreP3")
  .font(this->_ui.getFont("m36"))
  .msg("0")
  .at(1720, 175);
}

void gameScene::updateRuntime() {}

void gameScene::manageEvent(bbman::InputListener& listener) {(void)listener;}

void gameScene::displayScore(int id, int value)
{
  if (id < 0 || id > 3)
    return;
  this->_ui.get<text>("scoreP" + std::to_string(id)).msg(std::to_string(value));
}

void gameScene::displayTimerGlobal(int value)
{
  this->_ui.get<text>("mainTimer")
    .msg(((value / 60 < 10) ? "0" : "") + std::to_string(value / 60) + ":" + ((value % 60 < 10) ? "0" : "") + std::to_string(value % 60));
}

void gameScene::displayTimerTimeout(int value)
{
  if (value >= 0) {
    if (value <= 10) {
      if (value % 2) {
        this->_ui["alerte"].color(255, 100, 100);
      } else {
        this->_ui["alerte"].color(255, 15, 15);
      }
    }
    this->_ui.get<text>("alerte")
    .msg(std::to_string(value / 60) + ":" + ((value % 60 < 10) ? "0" : "") + std::to_string(value % 60));
  } else {
    this->_ui.get<text>("alerte")
    .msg("0:00");
  }
}
