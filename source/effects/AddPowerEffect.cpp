//
// AddPowerEffect.cpp for indie in /home/galibe_s/rendu/bomberman/source/effects
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed Jun  1 16:41:20 2016 stephane galibert
// Last update Wed Jun  1 21:13:10 2016 stephane galibert
//

#include "AddPowerEffect.hpp"

bbman::AddPowerEffect::AddPowerEffect(bbman::APlayer *player)
{
  this->_delta = 0;
  this->_target = player;
  this->_isFinished = false;
  this->_enabled = false;
}

bbman::AddPowerEffect::~AddPowerEffect(void)
{

}

void bbman::AddPowerEffect::update(irr::f32 delta)
{
  (void)delta;
}

bool bbman::AddPowerEffect::isFinished(void) const
{
  return (this->_isFinished);
}

void bbman::AddPowerEffect::enable(void)
{
  if (!this->_enabled) {
    this->_enabled = true;
    this->_target->setPower(this->_target->getPower() + 1);
  }
}

void bbman::AddPowerEffect::restart(void)
{
  this->_delta = 0;
}

void bbman::AddPowerEffect::setDelta(irr::f32 delta)
{
  this->_delta = delta;
}

size_t bbman::AddPowerEffect::getEffectID(void) const
{
  return (3);
}

irr::f32 bbman::AddPowerEffect::getDelta(void) const
{
  return (this->_delta);
}
