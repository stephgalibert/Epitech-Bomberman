//
// SpeedUPEffect.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 21:14:34 2016 stephane galibert
// Last update Tue May 10 04:09:11 2016 stephane galibert
//

#include "SpeedUPEffect.hpp"

bbman::SpeedUPEffect::SpeedUPEffect(bbman::IPlayer *player)
{
  this->_delta = 0;
  this->_target = player;
  this->_isFinished = false;
  this->_enabled = false;
}

bbman::SpeedUPEffect::~SpeedUPEffect(void)
{
  if (this->_enabled)
    this->_target->setSpeed(bbman::IPlayer::INITIAL_SPEED);
}

void bbman::SpeedUPEffect::update(irr::f32 delta)
{
  this->_delta += delta;
  if (this->_delta > DURATION)
    this->_isFinished = true;
}

bool bbman::SpeedUPEffect::isFinished(void) const
{
  return (this->_isFinished);
}

void bbman::SpeedUPEffect::enable(void)
{
  this->_enabled = true;
  this->_target->setSpeed(bbman::IPlayer::INITIAL_SPEED * 2.f);
}

void bbman::SpeedUPEffect::restart(void)
{
  this->_delta = 0;
}

size_t bbman::SpeedUPEffect::getEffectID(void) const
{
  return (1);
}
