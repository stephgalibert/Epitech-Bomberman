//
// Chronometer.cpp for chronometer in /home/galibe_s/cpp_utils/src
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon Apr 11 02:48:39 2016 stephane galibert
// Last update Thu May 12 16:06:54 2016 stephane galibert
//

#include "Chronometer.hpp"

tools::Chronometer::Chronometer(void)
{
  _timer = NULL;
  _running = false;
  _value = 0;
}

tools::Chronometer::~Chronometer(void)
{

}

void tools::Chronometer::setTimer(irr::ITimer *timer)
{
  _timer = timer;
}

irr::f32 tools::Chronometer::restart(void)
{
  irr::f32 elapsed = 0.;

  elapsed = getElapsedTime();
  _value = 0.;
  _running = false;
  start();
  return (elapsed);
}

void tools::Chronometer::toggle(void)
{
  if (!_running) {
    start();
  }
  else {
    pause();
  }
}

void tools::Chronometer::start(void)
{
  if (!_running && _timer) {
    _then = _timer->getTime();
    _running = true;
  }
}

void tools::Chronometer::pause(void)
{
  if (_running) {
    _value += getElapsedTime();
    _running = false;
  }
}

irr::f32 tools::Chronometer::getElapsedTime(void)
{
  if (_running && _timer) {
    _now = _timer->getTime();
    return (_now - _then + _value);
  }
  return (_value);
}
