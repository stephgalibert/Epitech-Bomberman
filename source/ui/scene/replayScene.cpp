/*
** replayScene.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 03:57:38 2016 Joffrey Escobar
*/

#include "replayScene.hpp"

replayScene::replayScene(ui& ui) : ASubLayout(ui, "replay")
{
  this->_hasSave = false;
}

replayScene::~replayScene() {}

void replayScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "backButton");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "replay/main.png", "main");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "replay/button.png", "button");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "replay/nosave.png", "nosave");

  this->_ui.load(ui::FONT, MEDIAPATH "hud/megatron36.bmp", "megatron36");
}

void replayScene::loadScene()
{
  int value;

  this->_hasSave = false;
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

  this->_ui.create<image>("main")
  .texture(this->_ui.getTexture("main"))
  .at(400, 150)
  .in("nosave").closeStyle();
  this->_ui.get<image>("main").setImage(this->_ui.getTexture("nosave"), "nosave");
  this->_ui.create<image>("button")
    .texture(this->_ui.getTexture("button"))
    .at(1200, 375)
    .in("hover")
      .color(200, 200, 200)
    .in("nosave").closeStyle();
  this->_ui.get<image>("button").setImage(NULL, "nosave");

  if (this->_info.parse("./save.txt")){
    this->_hasSave = true;

    value = this->_info.getTimer();

    this->_ui.create<text>("nbPlayer")
    .font(this->_ui.getFont("megatron36"))
    .msg(std::to_string(this->_info.getNbPlayers()))
    .at(600, 395);

    this->_ui.create<text>("timer")
    .font(this->_ui.getFont("megatron36"))
    .msg(((value / 60 < 10) ? "0" : "") + std::to_string(value / 60) + ":" + ((value % 60 < 10) ? "0" : "") + std::to_string(value % 60))
    .at(600, 575);
  } else {
    this->_ui.setStyle("main", "nosave");
    this->_ui.setStyle("button", "nosave");
  }
}

void replayScene::updateRuntime()
{
  if (this->_hasSave)
    this->_ui.setStyle("button", (this->_ui["button"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("backButton", (this->_ui["backButton"].collision(this->_mousePosition)) ? "hover" : "default");
}

void replayScene::manageEvent(bbman::InputListener& listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_nextScene = "default";
    }
    else if (this->_ui["button"].collision(listener.getPosition())) {
      if (this->_hasSave) {
	this->_nextScene = "game";
	this->_name = "./save.txt";
      }
    }
  }
}

std::string const& replayScene::getSaveName(void) const
{
  return (this->_name);
}

void replayScene::resetSaveName(void)
{
  this->_name = "";
}
