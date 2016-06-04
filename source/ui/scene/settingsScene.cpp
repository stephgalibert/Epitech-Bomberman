/*
** settingsScene.cpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 03:00:20 2016 Joffrey Escobar
*/

#include "settingsScene.hpp"

settingsScene::settingsScene(ui& ui) : ASubLayout(ui, "settings")
{
  this->_iaLevel = 1;
  this->_music  = 50;
  this->_effect  = 50;
}

settingsScene::~settingsScene() {}

void settingsScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/label_back.png", "labelBack");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "controls/back.png", "back");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/25.png", "25");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/50.png", "50");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/75.png", "75");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/100.png", "100");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/background.png", "labelBackground");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/easy.png", "easy");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/easySelected.png", "easySelected");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/hard.png", "hard");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/hardSelected.png", "hardSelected");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/medium.png", "medium");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/mediumSelected.png", "mediumSelected");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/music.png", "music");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/effect.png", "effect");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "settings/forbidden.png", "forbidden");

  this->_ui.load(ui::FONT, MEDIAPATH "lobby/calibri26.bmp", "calibri26");
  this->_ui.load(ui::FONT, MEDIAPATH "lobby/calibri32.bmp", "calibri36");
}

void settingsScene::loadIA()
{
  this->_ui.create<image>("easy")
  .texture(this->_ui.getTexture("easy"))
  .at(850, 650)
  .in("active")
  .in("hover")
  .color(120, 200, 200)
  .closeStyle();

  this->_ui.create<image>("medium")
  .texture(this->_ui.getTexture("medium"))
  .at(1000, 650)
  .in("active")
  .in("hover")
  .color(120, 200, 200)
  .closeStyle();

  this->_ui.create<image>("hard")
  .texture(this->_ui.getTexture("hard"))
  .at(1211, 650)
  .in("active")
  .in("hover")
  .color(120, 200, 200)
  .closeStyle();

  this->_ui.get<image>("easy")
  .setImage(this->_ui.getTexture("easySelected"), "active");

  this->_ui.get<image>("hard")
  .setImage(this->_ui.getTexture("hardSelected"), "active");

  this->_ui.get<image>("medium")
  .setImage(this->_ui.getTexture("mediumSelected"), "active");

  this->_ui.create<text>("labelHard")
  .font(this->_ui.getFont("calibri36"))
  .msg("hard")
  .color(255, 255, 255)
  .at(1240, 665);

  this->_ui.create<text>("zlabelMedium")
  .font(this->_ui.getFont("calibri36"))
  .msg("medium")
  .color(255, 255, 255)
  .at(1025, 665);

  this->_ui.create<text>("labelEasy")
  .font(this->_ui.getFont("calibri36"))
  .msg("easy")
  .color(255, 255, 255)
  .at(880, 665);

  this->_ui.setStyle("easy", "active");
}

void settingsScene::loadSound()
{
  this->_ui.create<image>("music")
  .texture(this->_ui.getTexture("music"))
  .at(650, 200);
  this->_ui.create<image>("musicForbidden")
  .at(635, 185)
  .in("enable")
  .closeStyle();

  this->_ui.get<image>("musicForbidden")
  .setImage(this->_ui.getTexture("forbidden"), "enable");

  this->_ui.create<image>("music25")
  .texture(this->_ui.getTexture("25"))
  .at(800, 240)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("music50")
  .texture(this->_ui.getTexture("50"))
  .at(830, 224)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("music75")
  .texture(this->_ui.getTexture("75"))
  .at(860, 210)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("music100")
  .texture(this->_ui.getTexture("100"))
  .at(890, 190)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("effect")
  .texture(this->_ui.getTexture("effect"))
  .at(1140, 200);
  this->_ui.create<image>("effectForbidden")
  .at(1125, 175)
  .in("enable")
  .closeStyle();

  this->_ui.get<image>("effectForbidden")
  .setImage(this->_ui.getTexture("forbidden"), "enable");

  this->_ui.create<image>("effect25")
  .texture(this->_ui.getTexture("25"))
  .at(1290, 240)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("effect50")
  .texture(this->_ui.getTexture("50"))
  .at(1320, 224)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("effect75")
  .texture(this->_ui.getTexture("75"))
  .at(1350, 210)
  .in("disable")
  .alpha(100)
  .closeStyle();

  this->_ui.create<image>("effect100")
  .texture(this->_ui.getTexture("100"))
  .at(1380, 190)
  .in("disable")
  .alpha(100)
  .closeStyle();
}

std::vector<std::pair<std::string, int> > const settingsScene::getVolume(void) const
{
  std::vector<std::pair<std::string, int> > volume;
  volume.push_back(std::make_pair("music", this->_music));
  volume.push_back(std::make_pair("effect", this->_effect));
  return (volume);
}

int settingsScene::getIADifficulty(void) const
{
  return (this->_iaLevel);
}

void settingsScene::loadScene()
{
  this->_ui.create<rect>("0backgroundColor")
  .color(0, 22, 30)
  .accros(1920, 1080);

  this->_ui.create<image>("Abackground")
  .texture(this->_ui.getTexture("background"))
  .alpha(15);

  this->_ui.create<image>("backText")
  .texture(this->_ui.getTexture("back"))
  .at(0, 900);

  this->_ui.create<image>("AlabelBackground")
  .texture(this->_ui.getTexture("labelBackground"));

  this->loadIA();
  this->loadSound();
}

void settingsScene::updateRuntime()
{
  this->_ui.setStyle("music25", "default");
  this->_ui.setStyle("music50", "default");
  this->_ui.setStyle("music75", "default");
  this->_ui.setStyle("music100", "default");
  this->_ui.setStyle("effect25", "default");
  this->_ui.setStyle("effect50", "default");
  this->_ui.setStyle("effect75", "default");
  this->_ui.setStyle("effect100", "default");
  this->_ui.setStyle("musicForbidden", "default");
  this->_ui.setStyle("effectForbidden", "default");

  this->_ui.setStyle("easy", this->_ui["easy"].collision(this->_mousePosition) ? "hover" : "default");
  this->_ui.setStyle("hard", this->_ui["hard"].collision(this->_mousePosition) ? "hover" : "default");
  this->_ui.setStyle("medium", this->_ui["medium"].collision(this->_mousePosition) ? "hover" : "default");
  if (this->_iaLevel == 1)
    this->_ui.setStyle("easy", "active");
  else if (this->_iaLevel == 2)
    this->_ui.setStyle("medium", "active");
  else
    this->_ui.setStyle("hard", "active");

  if (this->_music < 100){
    this->_ui.setStyle("music100", "disable");
  }
  if (this->_music < 75) {
    this->_ui.setStyle("music75", "disable");
  }
  if (this->_music < 50) {
    this->_ui.setStyle("music50", "disable");
  }
  if (this->_music < 25) {
    this->_ui.setStyle("music25", "disable");
  }
  if (this->_effect < 100){
    this->_ui.setStyle("effect100", "disable");
  }
  if (this->_effect < 75) {
    this->_ui.setStyle("effect75", "disable");
  }
  if (this->_effect < 50) {
    this->_ui.setStyle("effect50", "disable");
  }
  if (this->_effect < 25) {
    this->_ui.setStyle("effect25", "disable");
  }
  if (this->_effect == 0) {
    this->_ui.setStyle("effectForbidden", "enable");
  }
  if (this->_music == 0) {
    this->_ui.setStyle("musicForbidden", "enable");
  }
}

void settingsScene::manageEvent(bbman::InputListener& listener)
{
  this->_mousePosition = listener.getPosition();
  if (listener.getState()) {
    if (this->_ui["backText"].collision(listener.getPosition())) {
      this->_nextScene = "default";
      this->_ui.changeScene("default");
    }
    if (this->_ui["easy"].collision(this->_mousePosition))
      this->_iaLevel = 1;
    if (this->_ui["medium"].collision(this->_mousePosition))
      this->_iaLevel = 2;
    if (this->_ui["hard"].collision(this->_mousePosition))
      this->_iaLevel = 3;
    if (this->_ui["music25"].collision(this->_mousePosition))
      this->_music = 25;
    if (this->_ui["music50"].collision(this->_mousePosition))
      this->_music = 50;
    if (this->_ui["music75"].collision(this->_mousePosition))
      this->_music = 75;
    if (this->_ui["music100"].collision(this->_mousePosition))
      this->_music = 100;
    if (this->_ui["effect25"].collision(this->_mousePosition))
      this->_effect = 25;
    if (this->_ui["effect50"].collision(this->_mousePosition))
      this->_effect = 50;
    if (this->_ui["effect75"].collision(this->_mousePosition))
      this->_effect = 75;
    if (this->_ui["effect100"].collision(this->_mousePosition))
      this->_effect = 100;
    if (this->_ui["music"].collision(this->_mousePosition))
      this->_music = 0;
    if (this->_ui["effect"].collision(this->_mousePosition))
      this->_effect = 0;

  }
}
