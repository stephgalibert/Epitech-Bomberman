//
// BombAttr.cpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 26 11:32:16 2016 stephane galibert
// Last update Sun Jun  5 13:39:03 2016 stephane galibert
//

#include "BombAttr.hpp"

bbman::BombAttr::BombAttr(void)
{
  this->_attrs["BID"] =
    std::bind(&bbman::BombAttr::setBombID, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_attrs["timer"] =
    std::bind(&bbman::BombAttr::setTimer, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_attrs["pos"] =
    std::bind(&bbman::BombAttr::setPosition, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_attrs["owner"] =
    std::bind(&bbman::BombAttr::setOwner, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_attrs["explosed"] =
    std::bind(&bbman::BombAttr::setExplosed, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_attrs["lol"] =
    std::bind(&bbman::BombAttr::setLol, this, std::placeholders::_1,
	      std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
}

bbman::BombAttr::~BombAttr(void)
{

}

void bbman::BombAttr::set(bbman::IBomb **bombs, std::vector<APlayer *> &players,
			  Irrlicht &irr, std::string const& name,
			  std::string const& value)
{
  if (this->_attrs.find(name) != this->_attrs.cend()) {
    this->_attrs[name](bombs, players, irr, value);
  }
}

void bbman::BombAttr::setBombID(IBomb **bomb, std::vector<APlayer *> &player,
				Irrlicht &irr, std::string const& v)
{
  (void)player;
  std::vector<std::string> tokens;
  std::istringstream iss(v);
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  if (tokens.size() > 0) {
    if (tokens[0] == "1") {
      *bomb = new ExplodingBomb(NULL);
      (*bomb)->init(irr, (tokens.size() > 1) ? tokens[1] : "");
    }
  }
}

void bbman::BombAttr::setTimer(IBomb **bomb, std::vector<APlayer *> &player,
			       Irrlicht &irr, std::string const& v)
{
  (void)player;
  (void)irr;
  if (bomb && *bomb) {
    (*bomb)->setDelta(std::atof(v.data()));
  }
}

void bbman::BombAttr::setPosition(IBomb **bomb, std::vector<APlayer *> &player,
				  Irrlicht &irr, std::string const& v)
{
  (void)player;
  (void)irr;
  if (bomb && *bomb) {
    irr::core::vector3df pos;
    std::vector<std::string> tokens;
    std::istringstream iss(v);
    std::copy(std::istream_iterator<std::string>(iss),
	      std::istream_iterator<std::string>(),
	      std::back_inserter(tokens));
    if (tokens.size() == 3) {
      pos.X = std::atoi(tokens[0].data());
      pos.Y = std::atoi(tokens[1].data());
      pos.Z = std::atoi(tokens[2].data());
      (*bomb)->setPosition(pos);
    }
  }
}

void bbman::BombAttr::setOwner(IBomb **bomb, std::vector<APlayer *> &player,
			       Irrlicht &irr, std::string const& v)
{
  (void)irr;
  if (bomb && *bomb && (*bomb)->getBombID() == 1) {
    ExplodingBomb *explodingBomb = dynamic_cast<ExplodingBomb *>(*bomb);
    if (explodingBomb && std::atoi(v.data()) < (int)player.size()) {
      explodingBomb->setOwner(player[std::atoi(v.data())]);
    }
  }
}

void bbman::BombAttr::setExplosed(IBomb **bomb, std::vector<APlayer *> &player,
				  Irrlicht &irr, std::string const& v)
{
  (void)irr;
  (void)player;
  if (bomb && *bomb) {
    (*bomb)->setExplosed(v == "1");
  }
}

void bbman::BombAttr::setLol(IBomb **bomb, std::vector<APlayer *> &player,
			     Irrlicht &irr, std::string const& v)
{
  (void)irr;
  (void)player;
  if (bomb && *bomb) {
    (*bomb)->setExplosed(v == "1");
  }
}
