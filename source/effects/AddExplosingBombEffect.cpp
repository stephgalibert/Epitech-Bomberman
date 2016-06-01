//
// AddExplosingBombEffect.cpp for indie in /home/galibe_s/rendu/bomberman/source/effects
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:13:38 2016 stephane galibert
// Last update Wed Jun  1 16:44:34 2016 stephane galibert
//

#include "AddExplosingBombEffect.hpp"

bbman::AddExplosingBombEffect::AddExplosingBombEffect(bbman::APlayer *player)
{
  this->_delta = 0;
  this->_target = player;
  this->_isFinished = false;
  this->_enabled = false;
}

bbman::AddExplosingBombEffect::~AddExplosingBombEffect(void)
{
  /*if (this->_enabled) {
    this->_target->setSpeed(bbman::APlayer::INITIAL_SPEED);
    }*/
}

void bbman::AddExplosingBombEffect::update(irr::f32 delta)
{
  /*this->_delta += delta;
  if (this->_delta > DURATION) {
    this->_isFinished = true;
    }*/
  (void)delta;
}

bool bbman::AddExplosingBombEffect::isFinished(void) const
{
  return (this->_isFinished);
}

void bbman::AddExplosingBombEffect::enable(void)
{
  if (!this->_enabled) {
    this->_enabled = true;
    //this->_target->setSpeed(bbman::APlayer::INITIAL_SPEED * 1.5f);
    this->_target->addBomb(new ExplodingBomb(this->_target));
  }
}

void bbman::AddExplosingBombEffect::restart(void)
{
  this->_delta = 0;
}

void bbman::AddExplosingBombEffect::setDelta(irr::f32 delta)
{
  this->_delta = delta;
}

size_t bbman::AddExplosingBombEffect::getEffectID(void) const
{
  return (2);
}

irr::f32 bbman::AddExplosingBombEffect::getDelta(void) const
{
  return (this->_delta);
}
