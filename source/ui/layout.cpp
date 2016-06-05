/*
** layout.cpp for UI in /home/escoba_j/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 02:13:53 2016 Joffrey Escobar
*/

#include "layout.hpp"

layout::layout(irr::IrrlichtDevice *device)
{
  this->_ui          = new ui(device);
  this->_device       = device;
  this->_currentScene = "main";
  this->loadScene();
  this->_ui->changeScene("splashArt");
}

layout::~layout() {}

void layout::loadScene()
{
  this->_scene["default"]   = new mainScene(*this->_ui);
  this->_scene["settings"]  = new settingsScene(*this->_ui);
  this->_scene["controls"]  = new controlsScene(*this->_ui);
  this->_endGame = new endGameScene(*this->_ui);
  this->_scene["endGame"]   = this->_endGame;
  this->_echap              = new echapScene(*this->_ui);
  this->_scene["echap"]     = this->_echap;
  this->_scene["credit"]    = new creditScene(*this->_ui);
  this->_scene["ranking"]   = new rankingScene(*this->_ui);
  this->_scene["splashArt"] = new splashArtScene(*this->_ui);
  this->_replay = new replayScene(*this->_ui);
  this->_scene["replay"]    = this->_replay;

  this->_scene["tips"]      = new tipsScene(*this->_ui);
  this->_scene["lobby"]     = new lobbyScene(*this->_ui);
  this->_game               = new gameScene(*this->_ui);
  this->_scene["game"]      = this->_game;
}

const std::string& layout::display()
{
  if (this->_currentScene == "main") {
    this->_currentScene = "splashArt";
    this->_scene[this->_currentScene]->initScene();
    this->_scene[this->_currentScene]->loadRessources();
    this->_scene[this->_currentScene]->loadScene();
  } else if (this->_currentScene != this->_ui->getScene()) {
    this->_currentScene = this->_ui->getScene();
    this->_scene[this->_currentScene]->initScene();
    this->_scene[this->_currentScene]->loadRessources();
    this->_scene[this->_currentScene]->loadScene();
  }
  return this->_scene[this->_currentScene]->display();
}

void layout::input(bbman::InputListener& listener)
{
  if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    this->_scene[this->_currentScene]->manageEvent(listener);
  }
}

void layout::setGamepads(irr::core::array<irr::SJoystickInfo>const& jinfo)
{
  lobbyScene *lobby = dynamic_cast<lobbyScene *>(this->_scene.at("lobby"));

  if (lobby) {
    lobby->setGamepad(jinfo.size());
  } else {
    throw std::runtime_error("can not cast asublayout to lobbyscene");
  }
}

std::vector<int>const& layout::getDevices(void) const
{
  lobbyScene *lobby = dynamic_cast<lobbyScene *>(this->_scene.at("lobby"));

  if (lobby) {
    return lobby->getUsed();
  } else {
    throw std::runtime_error("can not cast asublayout to lobbyscene");
  }
}

bool layout::isGameStarted(void) const
{
  if (!getSaveName().empty()) {
    return (true);
  } else if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    return (this->_scene.at(this->_currentScene)->isGameStarted());
  }
  return (false);
}

void layout::backToMenu(void)
{
  this->_scene.at("lobby")->setStartGame(false);
  this->_scene.at("default")->setNextScene("default");
  this->_ui->changeScene("default");
}

bool layout::isInGame(void) const
{
  return (this->_currentScene != "lobby" && this->_currentScene != "default");
}

std::vector<std::pair<std::string, int> >const layout::getVolume(void) const
{
  settingsScene *set = dynamic_cast<settingsScene *>(this->_scene.at("settings"));

  if (set) {
    return set->getVolume();
  } else {
    throw std::runtime_error("can not cast asublayout to setscene");
  }
}

void layout::resetPauseMenu(void)
{
  this->_echap->reset();
}

bool layout::isResuming(void) const
{
  return this->_echap->isResuming();
}

bool layout::isSaving(void) const
{
  return this->_echap->isSaving();
}

bool layout::isMenuing(void) const
{
  return this->_echap->isMenuing();
}

int layout::getIADifficulty(void) const
{
  settingsScene *set = dynamic_cast<settingsScene *>(this->_scene.at("settings"));

  if (set) {
    return set->getIADifficulty();
  } else {
    throw std::runtime_error("can not cast asublayout to setscene");
  }
}

void layout::displayPauseMenu(void)
{
  if (this->_currentScene == "echap") {
    this->_ui->changeScene("game");
  } else {
    this->_ui->changeScene("echap");
  }
}

bool layout::isClosed(void)
{
  if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    return this->_scene.at(this->_currentScene)->isClosed();
  }
  return false;
}

void layout::setScore(int id, int value)
{
  this->_game->displayScore(id, value);
}

void layout::setTimerGlobal(int value)
{
  this->_game->displayTimerGlobal(value);
}

void layout::setTimerTimeout(int value)
{
  this->_game->displayTimerTimeout(value);
}

void layout::loadHUD(void)
{
  this->_currentScene = "game";
  this->_scene[this->_currentScene]->loadRessources();
  this->_scene[this->_currentScene]->initScene();
  this->_scene[this->_currentScene]->loadScene();
}

void layout::setDraw(void)
{
  this->_endGame->setDraw();
}

void layout::setVictory(void)
{
  this->_endGame->setVictory();
}

void layout::loadEndScene(void)
{
  this->_ui->changeScene("endGame");
  this->_currentScene = "endGame";
  this->_scene[this->_currentScene]->loadRessources();
  this->_scene[this->_currentScene]->initScene();
  this->_scene[this->_currentScene]->loadScene();
}

std::string const& layout::getSaveName(void) const
{
  return (this->_replay->getSaveName());
}

void layout::resetSaveName(void)
{
  this->_replay->resetSaveName();
}
