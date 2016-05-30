/*
** ASubLayout.cpp for UI  in /home/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 28 23:26:59 2016 Joffrey Escobar
*/

#include "ASubLayout.hpp"

ASubLayout::ASubLayout(ui& ui, std::string name) : _ui(ui), _name(name), _nextScene(name) {}

ASubLayout::~ASubLayout() {}

void               ASubLayout::setReturnMsg(const std::string& msg)
{
  this->_returnMsg = msg;
}

const std::string &ASubLayout::getName()
{
  return this->_name;
}

void ASubLayout::initScene()
{
  this->_nextScene = this->_name;
}

const std::string &ASubLayout::display()
{
  this->_returnMsg = "";
  this->updateRuntime();
  this->_ui.display();
  if (this->_nextScene != this->_ui.getScene()) {
    this->_ui.changeScene(this->_nextScene);
  }
  return this->_returnMsg;
}
