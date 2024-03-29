//
// PowerUPs.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:09:11 2016 avelin_j
// Last update Sun Jun  5 00:09:13 2016 avelin_j
//

#include "PowerUPs.hpp"

bbman::PowerUPs::PowerUPs(void)
{
  this->_delta = 0;
}

bbman::PowerUPs::~PowerUPs(void)
{
  for (auto &it : this->_powerUPs) {
    delete (it);
  }
}

/*void bbman::PowerUPs::update(bbman::Irrlicht &irr, float delta, Board *board)
{
  this->_delta += delta;

  for (auto &it : this->_powerUPs) {
    it->update(irr, delta);
  }

  if (this->_delta > DELAY / 2 && this->_powerUPs.size() < 5) {
    this->generate(irr, board);
    this->_delta = 0;
  }
}*/

void bbman::PowerUPs::add(bbman::Irrlicht &irr, irr::core::vector3df const& pos)
{
  generate(irr, pos);
}

std::list<bbman::IPowerUP *>const& bbman::PowerUPs::getPowerUPs(void) const
{
   return this->_powerUPs;
}

void bbman::PowerUPs::checkCollision(APlayer *player,
				     irr::core::vector3df const& scale)
{
  for (std::list<IPowerUP *>::iterator it = std::begin(this->_powerUPs);
       it != std::end(this->_powerUPs); ) {
    irr::core::vector3d<irr::s32> const& pos = player->getPosInMap(scale);
    if (pos == (*it)->getPosInMap(scale)) {
      (*it)->affectPlayer(player);
      delete (*it);
      it = this->_powerUPs.erase(it);
    } else {
      ++it;
    }

    /*if ((*it)->isColliding(player->getBoundingBox())) {
      (*it)->affectPlayer(player);
      delete (*it);
      it = this->_powerUPs.erase(it);
    }
    else {
      ++it;
      }*/
  }
}

void bbman::PowerUPs::generate(bbman::Irrlicht &irr, irr::core::vector3df const& pos)
{
  size_t random;

  random = this->_generator(0, 100);
  if (random > 95) {
    generateSpeedUp(irr, pos);
  }
  else if (random > 90) {
    generateAddPower(irr, pos);
  }
  else if (random > 80) {
    generateAddExplosingBomb(irr, pos);
  }
}

void bbman::PowerUPs::generateSpeedUp(bbman::Irrlicht &irr,
				      irr::core::vector3df const& pos)
{
  SpeedUPPowerUP *speedUP = new SpeedUPPowerUP;

  speedUP->init(irr);
  speedUP->setPosition(pos);
  this->_powerUPs.push_back(speedUP);
}

void bbman::PowerUPs::generateAddExplosingBomb(bbman::Irrlicht &irr,
					       irr::core::vector3df const& pos)
{
  AddExplosingBombPowerUP *add = new AddExplosingBombPowerUP;

  add->init(irr);
  add->setPosition(pos);
  this->_powerUPs.push_back(add);
}

void bbman::PowerUPs::generateAddPower(bbman::Irrlicht &irr,
				       irr::core::vector3df const& pos)
{
  AddPowerPowerUP *add = new AddPowerPowerUP;

  add->init(irr);
  add->setPosition(pos);
  this->_powerUPs.push_back(add);
}

irr::f32 bbman::PowerUPs::testGetDelta(void) const
{
  return (this->_delta);
}

/*bool bbman::PowerUPs::isFree(bbman::IPowerUP *powerUP, bbman::Board *board) const
{
  if (board->isColliding(powerUP->getBoundingBox())) {
    return (false);
  }
  if (board->isOutside(powerUP->getPosition())) {
    return (false);
  }
  return (std::find_if(std::begin(this->_powerUPs), std::end(this->_powerUPs),
		       [&powerUP](IPowerUP *up) {
			 return (up->getPosition() == powerUP->getPosition());
		       }) == std::end(this->_powerUPs));
}*/
