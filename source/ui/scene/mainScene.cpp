/*
** mainScene.cpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 28 23:40:30 2016 Joffrey Escobar
*/

#include "mainScene.hpp"

mainScene::mainScene(ui &ui) : ASubLayout(ui, "default") {}

mainScene::~mainScene() {}

void mainScene::loadRessources()
{
  this->_ui.load(ui::TEXTURE, MEDIAPATH "mode/background.png", "background");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/alveole.png", "alveole");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/astuce.png", "astuce");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/credit.png", "credit");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/exit.png", "exit");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/gamepad.png", "gamepad");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/pause.png", "pause");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/play.png", "play");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/rank.png", "rank");
  this->_ui.load(ui::TEXTURE, MEDIAPATH "main/settings.png", "settings");

  this->_ui.load(ui::FONT, MEDIAPATH "main/tron36.bmp", "mainFont36");
  this->_ui.load(ui::FONT, MEDIAPATH "main/tron48.bmp", "mainFont48");
}

void mainScene::displayIcon()
{
  this->_ui.create<image>("logoPlay")
  .texture(this->_ui.getTexture("play"))
  .at(780, 450);

  this->_ui.create<image>("logoPause")
  .texture(this->_ui.getTexture("pause"))
  .at(780, 210);

  this->_ui.create<image>("logoSettings")
  .texture(this->_ui.getTexture("settings"))
  .at(775, 710);

  this->_ui.create<image>("logoCredit")
  .texture(this->_ui.getTexture("credit"))
  .at(990, 585);

  this->_ui.create<image>("logoControls")
  .texture(this->_ui.getTexture("gamepad"))
  .at(545, 585);

  this->_ui.create<image>("logoRanking")
  .texture(this->_ui.getTexture("rank"))
  .at(543, 330);

  this->_ui.create<image>("logoTips")
  .texture(this->_ui.getTexture("astuce"))
  .at(993, 330);
}

void mainScene::createLabel()
{
  this->_ui.create<text>("label")
  .font(this->_ui.getFont("mainFont48"))
  .accros(500, 500)
  .color(0, 200, 200)
  .at(655, 910);
  this->_ui["label"].in("play").in("settings").in("binding").in("tips").in("credit").in("ranking").in("replay").closeStyle();
  this->_ui.get<text>("label").setMsg("   Play", "play");
  this->_ui.get<text>("label").setMsg("Settings", "settings");
  this->_ui.get<text>("label").setMsg("Controls", "binding");
  this->_ui.get<text>("label").setMsg("   Tips", "tips");
  this->_ui.get<text>("label").setMsg("  Credit", "credit");
  this->_ui.get<text>("label").setMsg(" Ranking", "ranking");
  this->_ui.get<text>("label").setMsg(" Replay", "replay");
}

void mainScene::createAlveole(int x, int y, const std::string &name)
{
  this->_ui.create<image>("alveole" + name)
  .texture(this->_ui.getTexture("alveole"))
  .at(x, y);

  this->_ui["alveole" + name].in("hover")
  .color(0, 240, 240)
  .closeStyle();
}

void mainScene::loadScene()
{
  this->_ui.create<image>("Abackground")
  .texture(this->_ui.getTexture("background"))
  .alpha(15);

  this->createAlveole(700, 400, "Play");
  this->createAlveole(480, 520, "Controls");
  this->createAlveole(480, 270, "Ranking");
  this->createAlveole(700, 150, "Pause");
  this->createAlveole(700, 650, "Settings");
  this->createAlveole(920, 530, "Credit");
  this->createAlveole(920, 280, "Tips");

  this->_ui.create<image>("exit")
  .texture(this->_ui.getTexture("exit"))
  .at(1750, 0);

  this->_ui["exit"].in("hover")
  .color(0, 250, 250)
  .closeStyle();

  displayIcon();
  createLabel();
}

void mainScene::manageEvent(InputListener &listener)
{
  if (GETSTATE){
    if (this->_ui["exit"].collision(GETPOSITION))
      this->setReturnMsg("EXIT");

    if (this->_ui["logoSettings"].collision(GETPOSITION)){
      this->_nextScene = "settings";
    }

    if (this->_ui["logoPlay"].collision(GETPOSITION))
      this->_nextScene = "game";
    }
}

void mainScene::updateRuntime()
{
  //reset
  this->_ui.setStyle("label", "default");

  //display label
  this->_ui.setStyle("label", ((this->_ui["logoPlay"]     .collision(GETPOSITION)) ? "play"     : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoPause"]    .collision(GETPOSITION)) ? "replay"   : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoSettings"] .collision(GETPOSITION)) ? "settings" : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoCredit"]   .collision(GETPOSITION)) ? "credit"   : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoControls"] .collision(GETPOSITION)) ? "binding"  : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoRanking"]  .collision(GETPOSITION)) ? "ranking"  : this->_ui.getStyle("label")));
  this->_ui.setStyle("label", ((this->_ui["logoTips"]     .collision(GETPOSITION)) ? "tips"     : this->_ui.getStyle("label")));

  //enable hover
  this->_ui.setStyle("alveolePlay", ((this->_ui["logoPlay"].collision(GETPOSITION)) ?      "hover" : "default"));
  this->_ui.setStyle("alveolePause", ((this->_ui["logoPause"].collision(GETPOSITION)) ?     "hover" : "default"));
  this->_ui.setStyle("alveoleSettings", ((this->_ui["logoSettings"].collision(GETPOSITION)) ?  "hover" : "default"));
  this->_ui.setStyle("alveoleCredit", ((this->_ui["logoCredit"].collision(GETPOSITION)) ?    "hover" : "default"));
  this->_ui.setStyle("alveoleControls", ((this->_ui["logoControls"].collision(GETPOSITION)) ?  "hover" : "default"));
  this->_ui.setStyle("alveoleTips", ((this->_ui["logoTips"].collision(GETPOSITION)) ?      "hover" : "default"));
  this->_ui.setStyle("alveoleRanking", ((this->_ui["logoRanking"].collision(GETPOSITION)) ?   "hover" : "default"));
  this->_ui.setStyle("exit",     ((this->_ui["exit"].collision(GETPOSITION)) ?          "hover" : "default"));
}
