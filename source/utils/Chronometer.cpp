//
// Chronometer.cpp for chronometer in /home/galibe_s/cpp_utils/src
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon Apr 11 02:48:39 2016 stephane galibert
// Last update Sat Jun  4 22:32:25 2016 avelin_j
//

#include "Chronometer.hpp"

tools::Chronometer::Chronometer(void)
{
  this->_timer = NULL;
  this->_running = false;
  this->_value = 0;
}

tools::Chronometer::~Chronometer(void)
{

}

void tools::Chronometer::setTimer(irr::ITimer *timer)
{
  this->_timer = timer;
}

irr::f32 tools::Chronometer::restart(void)
{
  irr::f32 elapsed = 0.;

  elapsed = getElapsedTime();
  this->_value = 0.;
  this->_running = false;
  start();
  return (elapsed);
}

void tools::Chronometer::toggle(void)
{
  if (!this->_running) {
    start();
  }
  else {
    pause();
  }
}

void tools::Chronometer::start(void)
{
  if (!this->_running && this->_timer) {
    this->_then = this->_timer->getTime();
    this->_running = true;
  }
}

void tools::Chronometer::pause(void)
{
  if (this->_running) {
    this->_value += getElapsedTime();
    this->_running = false;
  }
}

irr::f32 tools::Chronometer::getElapsedTime(void)
{
  if (this->_running && this->_timer) {
    this->_now = this->_timer->getTime();
    return (this->_now - this->_then + this->_value);
  }
  return (this->_value);
}

irr::f32 tools::Chronometer::testGetValue(void) const
{
  return (this->_value);
}

irr::ITimer const *tools::Chronometer::testGetTimer(void) const
{
  return (this->_timer);
}

bool tools::Chronometer::testGetRunning(void) const
{
  return (this->_running);
}
