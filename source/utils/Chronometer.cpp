//
// Chronometer.cpp for chronometer in /home/galibe_s/cpp_utils/src
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon Apr 11 02:48:39 2016 stephane galibert
// Last update Wed May 18 17:20:08 2016 stephane galibert
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
