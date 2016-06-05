/*
** rankingScene.cpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 03:27:43 2016 Joffrey Escobar
*/

#include "rankingScene.hpp"

rankingScene::rankingScene(ui& ui) : ASubLayout(ui, "ranking") {}

rankingScene::~rankingScene() {}

void rankingScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "backButton");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "ranking/highscores.png", "label");

  this->_ui.load(ui::FONT, MEDIAPATH "lobby/calibri26.bmp", "calibri26");
}

void rankingScene::createLabel(int id, const std::string &score)
{
  this->_ui.create<text>("labeL" + std::to_string(id))
  .font(this->_ui.getFont("calibri26"))
  .msg(score)
  .at(575, 335 + 48 * id);
}

void rankingScene::loadScene()
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

  this->_ui.create<image>("labelHighscore")
  .texture(this->_ui.getTexture("label"));
  this->loadScoreFromFile();
}

void rankingScene::loadScoreFromFile()
{
  std::ifstream rankingStream(FILE_NAME);
  std::string   line;
  int   i = 0;

  if (rankingStream.is_open()) {
    while (std::getline(rankingStream, line) && i < 10) {
      this->createLabel(i++, line);
    }
    rankingStream.close();
  }
}

void rankingScene::updateRuntime()
{
  this->_ui.setStyle("backButton", (this->_ui["backButton"].collision(this->_mousePosition)) ? "hover" : "default");
}

void rankingScene::manageEvent(bbman::InputListener& listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()){
    if (this->_ui["backButton"].collision(listener.getPosition())) {
      this->_nextScene = "default";
    }
  }
}
