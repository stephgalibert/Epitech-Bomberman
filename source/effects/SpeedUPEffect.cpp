//
// SpeedUPEffect.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 21:14:34 2016 stephane galibert
// Last update Thu May 26 10:07:35 2016 stephane galibert
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
  /*if (this->_enabled) {
    this->_target->setSpeed(bbman::APlayer::INITIAL_SPEED);
    }*/
}

void bbman::SpeedUPEffect::update(irr::f32 delta)
{
  /*this->_delta += delta;
  if (this->_delta > DURATION) {
    this->_isFinished = true;
    }*/
  (void)delta;
}

bool bbman::SpeedUPEffect::isFinished(void) const
{
  return (this->_isFinished);
}

void bbman::SpeedUPEffect::enable(void)
{
  this->_enabled = true;
  this->_target->setSpeed(bbman::APlayer::INITIAL_SPEED * 1.5f);
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
