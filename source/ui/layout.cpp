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
  this->_ui           = new ui(device);
  this->_device       = device;
  this->_currentScene = "main";
  this->loadScene();
}

layout::~layout() {}

void layout::loadScene()
{
  this->_scene["default"] = new mainScene(*this->_ui);
  this->_scene["settings"] = new settingsScene(*this->_ui);
  this->_scene["game"] = new gameScene(*this->_ui);
  this->_scene["controls"] = new controlsScene(*this->_ui);
  this->_scene["lobby"] = new lobbyScene(*this->_ui);
}

const std::string &layout::display()
{
  if (this->_currentScene != this->_ui->getScene()) {
    this->_currentScene = this->_ui->getScene();
    this->_scene[this->_currentScene]->loadRessources();
    this->_scene[this->_currentScene]->initScene();
    this->_scene[this->_currentScene]->loadScene();
  }
  return this->_scene[this->_currentScene]->display();
}

void layout::input(bbman::InputListener &listener) {
  if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    this->_scene[this->_currentScene]->manageEvent(listener);
  }
}

void layout::setGamepads(irr::core::array<irr::SJoystickInfo> const& jinfo)
{
  lobbyScene *lobby = dynamic_cast<lobbyScene *>(this->_scene.at("lobby"));
  if (lobby) {
    lobby->setGamepad(jinfo.size());
  }
  else {
    throw std::runtime_error("can not cast asublayout to lobbyscene");
  }
}

std::vector<int> const& layout::getDevices(void) const
{
  lobbyScene *lobby = dynamic_cast<lobbyScene *>(this->_scene.at("lobby"));
  if (lobby) {
    return (lobby->getUsed());
  }
  else {
    throw std::runtime_error("can not cast asublayout to lobbyscene");
  }
}

bool layout::isGameStarted(void) const
{
  if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    return this->_scene.at(this->_currentScene)->isGameStarted();
  }
  return false;
}

void layout::backToMenu(void)
{
  this->_scene.at("lobby")->setStartGame(false);
  this->_scene.at("default")->setNextScene("default");
  this->_ui->changeScene("default");
}

bool layout::isClosed(void)
{
  if (this->_scene.find(this->_currentScene) != this->_scene.cend()) {
    return this->_scene.at(this->_currentScene)->isClosed();
  }
  return false;
}
