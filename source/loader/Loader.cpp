//
// Loader.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 25 14:22:45 2016 stephane galibert
// Last update Fri Jun  3 11:52:07 2016 stephane galibert
//

#include "Loader.hpp"

bbman::Loader::Loader(void)
{
  this->_loads["MAP_BEGIN"] =
    std::bind(&bbman::Loader::loadMap, this, std::placeholders::_1,
	      std::placeholders::_2);
  this->_loads["PLAYERS_BEGIN"] =
    std::bind(&bbman::Loader::loadPlayers, this, std::placeholders::_1,
	      std::placeholders::_2);
  this->_loads["BOMBS_BEGIN"] =
    std::bind(&bbman::Loader::loadBombs, this, std::placeholders::_1,
	      std::placeholders::_2);
  this->_loads["TIMEOUT_BEGIN"] =
    std::bind(&bbman::Loader::loadTimeOut, this, std::placeholders::_1,
	      std::placeholders::_2);
}

bbman::Loader::~Loader(void)
{

}

void bbman::Loader::load(Irrlicht &irr, std::string const& filename)
{
  std::string line;
  std::ifstream ifs(filename.c_str(), std::ifstream::in);

  while (std::getline(ifs, line))
    {
      if (this->_loads.find(line) != this->_loads.cend()) {
	this->_loads[line](irr, ifs);
      }
    }
}

bbman::Map<bbman::Cell> const& bbman::Loader::getMap(void) const
{
  return (this->_map);
}

std::vector<bbman::APlayer *> const& bbman::Loader::getPlayers(void) const
{
  return (this->_players);
}

std::list<bbman::IBomb *> const& bbman::Loader::getBombs(void) const
{
  return (this->_bombs);
}

bbman::TimeOut *bbman::Loader::getTimeOut(void) const
{
  return (this->_timeout);
}

void bbman::Loader::loadMap(Irrlicht &irr, std::ifstream &ifs)
{
  std::string line;
  size_t pos = 0;
  size_t x = 0;
  size_t y = 0;

  (void)irr;
  this->_map.load(19, 13);
  while (std::getline(ifs, line) && line != "MAP_END")
    {
      x = 0;
      pos = line.find_first_not_of(" \t");
      while (pos != std::string::npos && y < this->_map.h && x < this->_map.w)
	{
	  this->_map.at(x, y).id = static_cast<ItemID>(line[pos] - 48);
	  pos = line.find_first_not_of(" \t", pos + 1);
	  ++x;
	}
      ++y;
    }
}

void bbman::Loader::loadPlayers(Irrlicht &irr, std::ifstream &ifs)
{
  APlayer *player = NULL;
  PlayerAttr attr;
  std::string name;
  std::string value;
  std::string line;
  size_t pos = 0;
  size_t pos1 = 0;
  size_t pos2 = 0;

  while (std::getline(ifs, line) && line != "PLAYERS_END")
    {
      player = NULL;
      pos = 0;
      pos1 = line.find_first_of(":");
      pos2 = line.find_first_of(";");
      while (pos1 != std::string::npos && pos2 != std::string::npos)
	{
	  name = line.substr(pos, pos1 - pos);
	  value = line.substr(pos1 + 1, pos2 - pos1 - 1);
	  attr.set(&player, irr, name, value);
	  pos = pos2 + 1;
	  pos1 = line.find_first_of(":", pos2);
	  pos2 = line.find_first_of(";", pos2 + 1);
	}
      if (player) {
	this->_players.push_back(player);
      }
    }
}

void bbman::Loader::loadBombs(Irrlicht &irr, std::ifstream &ifs)
{
  IBomb *bomb = NULL;
  BombAttr attr;
  std::string name;
  std::string value;
  std::string line;
  size_t pos = 0;
  size_t pos1 = 0;
  size_t pos2 = 0;

  while (std::getline(ifs, line) && line != "BOMBS_END")
    {
      bomb = NULL;
      pos = 0;
      pos1 = line.find_first_of(":");
      pos2 = line.find_first_of(";");
      while (pos1 != std::string::npos && pos2 != std::string::npos)
	{
	  name = line.substr(pos, pos1 - pos);
	  value = line.substr(pos1 + 1, pos2 - pos1 - 1);
	  attr.set(&bomb, this->_players, irr, name, value);
	  pos = pos2 + 1;
	  pos1 = line.find_first_of(":", pos2);
	  pos2 = line.find_first_of(";", pos2 + 1);
	}
      if (bomb) {
	/*irr::core::vector3df scale(10, 10, 10);
	  irr::core::vector3d<irr::s32> const& pos = bomb->getPosInMap(scale);
	  if (this->_map.at(pos.X, pos.Z).id != ItemID::II_NONE) {*/
	this->_bombs.push_back(bomb);
	//}
      }
    }
}

void bbman::Loader::loadTimeOut(Irrlicht &irr, std::ifstream &ifs)
{
  TimeOutAttr attr;
  std::string name;
  std::string value;
  std::string line;
  size_t pos = 0;
  size_t pos1 = 0;
  size_t pos2 = 0;

  this->_timeout = new TimeOut;
  while (std::getline(ifs, line) && line != "TIMEOUT_END")
    {
      pos = 0;
      pos1 = line.find_first_of(":");
      pos2 = line.find_first_of(";");
      while (pos1 != std::string::npos && pos2 != std::string::npos)
	{
	  name = line.substr(pos, pos1 - pos);
	  value = line.substr(pos1 + 1, pos2 - pos1 - 1);
	  attr.set(this->_timeout, irr, name, value);
	  pos = pos2 + 1;
	  pos1 = line.find_first_of(":", pos2);
	  pos2 = line.find_first_of(";", pos2 + 1);
	}
    }
}
