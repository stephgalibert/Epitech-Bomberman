//
// BombManager.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 20:29:19 2016 stephane galibert
// Last update Mon May 30 17:44:29 2016 stephane galibert
//

#include "BombManager.hpp"

bbman::BombManager::BombManager(void)
{
  this->_selectedBomb = this->_bombs.end();
}

bbman::BombManager::~BombManager(void)
{
  for (auto &it : this->_bombs) {
    delete (it.second.second);
  }
}

void bbman::BombManager::addBomb(bbman::IBomb *type)
{
  size_t bombID = type->getBombID();
  if (this->_bombs.find(bombID) != this->_bombs.cend()) {
    ++this->_bombs[bombID].first;
    delete (type);
  }
  else {
    this->_bombs.insert(std::make_pair(bombID, std::make_pair(1, type)));
  }
  if (this->_selectedBomb == this->_bombs.end()) {
    this->_selectedBomb = this->_bombs.begin();
  }
}

bbman::IBomb *bbman::BombManager::getSelectedBomb(void)
{
  if (this->_selectedBomb != this->_bombs.end()) {
    if (this->_selectedBomb->second.first > 0) {
      --this->_selectedBomb->second.first;
      return (this->_selectedBomb->second.second->clone());
    }
  }
  return (NULL);
}

void bbman::BombManager::operator++(void)
{
  ++this->_selectedBomb;
  if (this->_selectedBomb == this->_bombs.end()) {
    this->_selectedBomb = this->_bombs.begin();
  }
}

void bbman::BombManager::operator--(void)
{
  if (this->_selectedBomb == this->_bombs.begin()) {
    this->_selectedBomb = this->_bombs.end();
    --this->_selectedBomb;
  }
  else {
    --this->_selectedBomb;
  }
}

std::map<size_t, std::pair<size_t, bbman::IBomb *> > const&
bbman::BombManager::getBombs(void) const
{
  return (this->_bombs);
}


std::map<size_t, std::pair<size_t, bbman::IBomb *> >::iterator const&
bbman::BombManager::getCurrent(void) const
{
  return (this->_selectedBomb);
}

std::ostream &bbman::operator<<(std::ostream &flux, bbman::BombManager const& bm)
{
  //std::vector<bbman::IBomb *> const& bombs = bm.getBombs();
  std::map<size_t, std::pair<size_t, IBomb *> > const& bombs = bm.getBombs();
  for (auto it : bombs) {
    flux << "bm.id:" << it.second.second->getBombID() << ";bm.n:-1;";
    //flux << "bm:" << it->getBombID() << " " <<
  }
  return (flux);
}
