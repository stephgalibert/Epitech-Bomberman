//
// PowerUPs.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 17:37:21 2016 stephane galibert
// Last update Wed Jun  1 21:27:01 2016 stephane galibert
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

void bbman::PowerUPs::checkCollision(APlayer *player)
{
  for (std::list<IPowerUP *>::iterator it = std::begin(this->_powerUPs);
       it != std::end(this->_powerUPs); ) {
    if ((*it)->isColliding(player->getBoundingBox())) {
      (*it)->affectPlayer(player);
      delete (*it);
      it = this->_powerUPs.erase(it);
    }
    else {
      ++it;
    }
  }
}

void bbman::PowerUPs::generate(bbman::Irrlicht &irr, irr::core::vector3df const& pos)
{
  size_t random;

  random = this->_generator(0, 100);
  if (random > 90) {
    generateAddPower(irr, pos);
  }
  else if (random > 80) {
    generateSpeedUp(irr, pos);
  }
  else if (random > 70) {
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
