//
// SpeedUPEffect.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:02:44 2016 avelin_j
// Last update Sun Jun  5 11:54:23 2016 stephane galibert
//

#include "SpeedUPEffect.hpp"

bbman::SpeedUPEffect::SpeedUPEffect(bbman::APlayer *player)
{
  this->_delta = 0;
  this->_target = player;
  this->_isFinished = false;
  this->_enabled = false;
}

bbman::SpeedUPEffect::~SpeedUPEffect(void)
{

}

void bbman::SpeedUPEffect::update(irr::f32 delta)
{
  (void)delta;
}

bool bbman::SpeedUPEffect::isFinished(void) const
{
  return (this->_isFinished);
}

void bbman::SpeedUPEffect::enable(void)
{
  if (!this->_enabled) {
    this->_enabled = true;
    size_t speed = this->_target->getSpeed();
    if (speed == bbman::APlayer::INITIAL_SPEED) {
      this->_target->setSpeed(bbman::APlayer::INITIAL_SPEED * 1.25f);
    }
  }
}

void bbman::SpeedUPEffect::restart(void)
{
  this->_delta = 0;
}

void bbman::SpeedUPEffect::setDelta(irr::f32 delta)
{
  this->_delta = delta;
}

size_t bbman::SpeedUPEffect::getEffectID(void) const
{
  return (1);
}

irr::f32 bbman::SpeedUPEffect::getDelta(void) const
{
  return (this->_delta);
}

bool bbman::SpeedUPEffect::testGetEnable(void) const
{
  return (this->_enabled);
}

bbman::APlayer const *bbman::SpeedUPEffect::testGetTarget(void) const
{
  return (this->_target);
}
