//
// PowerUPs.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 17:37:21 2016 stephane galibert
// Last update Sat May 21 04:49:03 2016 stephane galibert
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

void bbman::PowerUPs::update(bbman::Irrlicht &irr, float delta, Board *board)
{
  this->_delta += delta;

  for (auto &it : this->_powerUPs) {
    it->update(irr, delta);
  }

  if (this->_delta > DELAY && this->_powerUPs.size() < 5) {
    this->generate(irr, board);
    this->_delta = 0;
  }
}

void bbman::PowerUPs::checkCollision(IPlayer *player)
{
  for (std::list<IPowerUP *>::iterator it = std::begin(this->_powerUPs);
       it != std::end(this->_powerUPs);
       ++it) {
    if ((*it)->isColliding(player->getBoundingBox())) {
      (*it)->affectPlayer(player);
      delete (*it);
      it = this->_powerUPs.erase(it);
    }
  }
}

void bbman::PowerUPs::setArea(irr::core::vector3df const& max)
{
  this->_max = max;
}

void bbman::PowerUPs::generate(bbman::Irrlicht &irr, bbman::Board *board)
{
  size_t random;

  random = this->_generator(0, 100);
  if (random > 70) {
    this->generateSpeedUp(irr, board);
  }
}

void bbman::PowerUPs::generateSpeedUp(bbman::Irrlicht &irr, bbman::Board *board)
{
  irr::core::vector3df pos;
  SpeedUPPowerUP *speedUP = new SpeedUPPowerUP;

  speedUP->init(irr);
  do {
    pos.X = (this->_generator(0, this->_max.X) * board->getScale().X)
      - board->getScale().X / 2;
    pos.Y = 4.f;
    pos.Z = (this->_generator(0, this->_max.Z) * board->getScale().Z)
      - board->getScale().Z / 2;
    speedUP->setPosition(pos);
  } while (!isFree(speedUP, board));
  this->_powerUPs.push_back(speedUP);
}

bool bbman::PowerUPs::isFree(bbman::IPowerUP *powerUP, bbman::Board *board) const
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
}
