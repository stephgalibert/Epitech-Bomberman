/*
** gameScene.cpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Mon May 30 17:42:22 2016 Joffrey Escobar
*/

#include "gameScene.hpp"

gameScene::gameScene(ui& ui) : ASubLayout(ui, "game") {}

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
  .msg("03:20")
  .color(255, 255, 255)
  .at(860, 0);

  this->_ui.create<text>("alerte")
  .font(this->_ui.getFont("m26"))
  .msg("0:17")
  .color(255, 75, 75)
  .at(925, 65);

  this->_ui.create<text>("scoreP1")
  .font(this->_ui.getFont("m36"))
  .msg("460")
  .at(150, 55);

  this->_ui.create<text>("scoreP2")
  .font(this->_ui.getFont("m36"))
  .msg("236")
  .at(150, 175);

  this->_ui.create<text>("scoreP3")
  .font(this->_ui.getFont("m36"))
  .msg("117")
  .at(1720, 55);

  this->_ui.create<text>("scoreP4")
  .font(this->_ui.getFont("m36"))
  .msg("203")
  .at(1720, 175);
}

void gameScene::updateRuntime() {}

void gameScene::manageEvent(bbman::InputListener &listener) {}


void gameScene::displayScore(int id, int value)
{

}

void gameScene::displayTimerGlobal(int value)
{

}

void gameScene::displayTimerTimeout(int value)
{

}
