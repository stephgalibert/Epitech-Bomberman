//
// BombManager.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 20:29:19 2016 stephane galibert
// Last update Thu May 12 15:55:39 2016 stephane galibert
//

#include "BombManager.hpp"

bbman::BombManager::BombManager(void)
{
  this->_selectedBomb = std::end(_bombs);
}

bbman::BombManager::~BombManager(void)
{
  for (auto &it : this->_bombs) {
    delete (it);
  }
}

void bbman::BombManager::addBomb(bbman::IBomb *type)
{
  this->_bombs.push_back(type);
  if (this->_bombs.size() == 1) {
    this->_selectedBomb = std::begin(this->_bombs);
  }
}

bbman::IBomb *bbman::BombManager::getSelectedBomb(void) const
{
  return ((*this->_selectedBomb)->clone());
}

void bbman::BombManager::operator++(void)
{
  ++this->_selectedBomb;
  if (this->_selectedBomb == std::end(this->_bombs)) {
    this->_selectedBomb = std::begin(this->_bombs);
  }
}

void bbman::BombManager::operator--(void)
{
  if (this->_selectedBomb == std::begin(this->_bombs)) {
    this->_selectedBomb = std::end(this->_bombs);
    --this->_selectedBomb;
  }
  else {
    --this->_selectedBomb;
  }
}
