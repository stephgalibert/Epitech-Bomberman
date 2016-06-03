/*
** lobbyScene.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/uia
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu Jun 02 14:53:12 2016 Joffrey Escobar
*/

#include "lobbyScene.hpp"

lobbyScene::lobbyScene(ui& ui) : ASubLayout(ui, "lobby")
{
    this->_gamepad = 0;

    this->_selecter.push_back("Keyboard 1");
    this->_selecter.push_back("Keyboard 2");
    this->_selecter.push_back(" Gamepad 1");
    this->_selecter.push_back(" Gamepad 2");

    this->_used.push_back(-1);
    this->_used.push_back(-1);
    this->_used.push_back(-1);
    this->_used.push_back(-1);
}

lobbyScene::~lobbyScene() {}

void lobbyScene::createPlayerLabel(int x, int id)
{
  this->_ui.create<image>("labelPlayer" + std::to_string(id))
  .texture(this->_ui.getTexture("labelPerso"))
  .at(100 + x, 100);
  this->_ui.create<image>("1LabelControler" + std::to_string(id))
  .texture(this->_ui.getTexture("labelControler"))
  .at(100 + x, 750);
  this->_ui.create<image>("player" + std::to_string(id))
  .texture(this->_ui.getTexture("perso" + std::to_string(id)))
  .at(175 + x, 150);
  this->_ui.create<image>("buttonDown" + std::to_string(id))
  .texture(this->_ui.getTexture("buttonDown"))
  .at(120 + x, 765);
  this->_ui.create<image>("buttonUp" + std::to_string(id))
  .texture(this->_ui.getTexture("buttonUp"))
  .at(410 + x, 765);
  this->_ui.create<text>("mode" + std::to_string(id))
  .msg("      IA")
  .font(this->_ui.getFont("calibri26"))
  .at(200 + x, 757);

  this->_ui["buttonDown" + std::to_string(id)].in("hover")
    .alpha(200)
    .closeStyle();
  this->_ui["buttonUp" + std::to_string(id)].in("hover")
    .alpha(200)
    .closeStyle();
}

void lobbyScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/buttonDown.png", "buttonDown");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/buttonUp.png", "buttonUp");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "backButton");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/labelControler.png", "labelControler");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/labelPerso.png", "labelPerso");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/bleu.png", "perso0");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/orange.png", "perso1");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/green.png", "perso2");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/purple.png", "perso3");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "lobby/playButton.png", "playButton");

  this->_ui.load(ui::FONT, MEDIAPATH "lobby/calibri26.bmp", "calibri26");
  this->_ui.load(ui::FONT, MEDIAPATH "lobby/calibri32.bmp", "calibri36");
}

void lobbyScene::loadScene()
{
  this->_nextScene = this->_name;
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

  this->_ui.create<image>("playButton")
    .texture(this->_ui.getTexture("playButton"))
    .at(1400, 920);

  this->_ui["playButton"].in("hover")
    .color(170, 245, 245)
    .closeStyle();

  this->createPlayerLabel(0, 0);
  this->createPlayerLabel(450, 1);
  this->createPlayerLabel(900, 2);
  this->createPlayerLabel(1350, 3);
}

void lobbyScene::updateRuntime()
{
  this->_ui.setStyle("backButton", (this->_ui["backButton"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("playButton", (this->_ui["playButton"].collision(this->_mousePosition)) ? "hover" : "default");

  this->_ui.setStyle("buttonUp0", (this->_ui["buttonUp0"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonDown0", (this->_ui["buttonDown0"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonUp1", (this->_ui["buttonUp1"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonDown1", (this->_ui["buttonDown1"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonUp2", (this->_ui["buttonUp2"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonDown2", (this->_ui["buttonDown2"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonUp3", (this->_ui["buttonUp3"].collision(this->_mousePosition)) ? "hover" : "default");
  this->_ui.setStyle("buttonDown3", (this->_ui["buttonDown3"].collision(this->_mousePosition)) ? "hover" : "default");
}

void lobbyScene::prevChoice(int id)
{
  int tmp;

  tmp = this->_used[id];
  if (tmp <= 0) {
    this->_used[id] = -1;
    this->_ui.get<text>("mode" + std::to_string(id))
    .msg("       IA");
    return;
  }
  for (int i = tmp; i >= 0 ; i--) {
    if (std::find(this->_used.begin(), this->_used.end(), i) == this->_used.end()) {
      this->_used[id] = i;
      this->_ui.get<text>("mode" + std::to_string(id))
      .msg(this->_selecter[this->_used[id]]);
      return;
    }
  }
  this->_used[id] = -1;
  this->_ui.get<text>("mode" + std::to_string(id))
  .msg("        IA");
}

void lobbyScene::nextChoice(int id)
{
  int tmp;

  tmp = this->_used[id];
  for (int i = tmp + 1; i < 2 + this->_gamepad; i++) {
    if (std::find(this->_used.begin(), this->_used.end(), i) == this->_used.end()) {
      this->_used[id] = i;
      this->_ui.get<text>("mode" + std::to_string(id))
      .msg(this->_selecter[this->_used[id]]);
      return;
    }
  }
}

std::vector<int> const& lobbyScene::getUsed(void) const
{
  return (this->_used);
}

void lobbyScene::setGamepad(int pad)
{
  this->_gamepad = pad;
}

void lobbyScene::manageEvent(bbman::InputListener &listener) {
  this->_ui.setStyle("backButton", "default");
  this->_ui.setStyle("playButton", "default");

  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_nextScene = "default";
    }
    if (this->_ui["playButton"].collision(listener.getPosition())) {
      this->_nextScene = "game";
      this->_startGame = true;
    }
    for (uint64_t i = 0; i < 4; i++) {
      if (this->_ui["buttonUp" + std::to_string(i)].collision(listener.getPosition())) {
        this->nextChoice(i);
      }
      if (this->_ui["buttonDown" + std::to_string(i)].collision(listener.getPosition())) {
        this->prevChoice(i);
      }
    }
  }
}
