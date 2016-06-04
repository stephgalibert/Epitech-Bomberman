//
// SaveInfo.cpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun Jun  5 01:00:43 2016 stephane galibert
// Last update Sun Jun  5 01:30:06 2016 stephane galibert
//

#include "SaveInfo.hpp"

bbman::SaveInfo::SaveInfo(void)
{
  this->_infos["GAME_BEGIN"] =
    std::bind(&bbman::SaveInfo::infoTimer, this, std::placeholders::_1);
  this->_infos["PLAYERS_BEGIN"] =
    std::bind(&bbman::SaveInfo::infoNbPlayers, this, std::placeholders::_1);
  this->_timer = 0;
  this->_nbPlayers = 0;
}

bbman::SaveInfo::~SaveInfo(void)
{

}

bool bbman::SaveInfo::parse(std::string const& filename)
{
  std::string line;
  std::ifstream ifs(filename.data());

  if (ifs) {
    while (std::getline(ifs, line)) {
      if (this->_infos.find(line) != this->_infos.cend()) {
	this->_infos[line](ifs);
      }
    }
    return true;
  }
  return false;
}

irr::f32 bbman::SaveInfo::getTimer(void) const
{
  return (this->_timer);
}

size_t bbman::SaveInfo::getNbPlayers(void) const
{
  return (this->_nbPlayers);
}

void bbman::SaveInfo::infoTimer(std::ifstream &ifs)
{
  std::string name;
  std::string value;
  std::string line;
  size_t pos = 0;
  size_t pos1 = 0;
  size_t pos2 = 0;

  while (std::getline(ifs, line) && line != "GAME_END")
    {
      pos = 0;
      pos1 = line.find_first_of(":");
      pos2 = line.find_first_of(";");
      while (pos1 != std::string::npos && pos2 != std::string::npos)
	{
	  name = line.substr(pos, pos1 - pos);
	  value = line.substr(pos1 + 1, pos2 - pos1 - 1);
	  this->_timer = std::atof(value.data());
	  pos = pos2 + 1;
	  pos1 = line.find_first_of(":", pos2);
	  pos2 = line.find_first_of(";", pos2 + 1);
	}
    }
}

void bbman::SaveInfo::infoNbPlayers(std::ifstream &ifs)
{
  std::string line;

  this->_nbPlayers = 0;
  while (std::getline(ifs, line) && line != "PLAYERS_END")
    {
      ++this->_nbPlayers;
    }
}
