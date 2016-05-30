/*
** listener.hpp for UI in /home/escoba_j/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 18:43:50 2016 Joffrey Escobar
*/

#ifndef LISTENER_HPP_
#define LISTENER_HPP_

#include <irrlicht.h>

class listener : public irr::IEventReceiver
{
public:

  listener(void)
  {
    this->_leftButtonDown = true;
    this->_currentEvent = 0;
  }

  bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
      switch (event.MouseInput.Event)
      {
      case irr::EMIE_LMOUSE_PRESSED_DOWN:
        this->_leftButtonDown = true;
        this->_currentEvent += 1;
        break;

      case irr::EMIE_LMOUSE_LEFT_UP:
        this->_leftButtonDown = false;
        this->_currentEvent += 1;
        break;

      case irr::EMIE_MOUSE_MOVED:
        this->_position.X = event.MouseInput.X;
        this->_position.Y = event.MouseInput.Y;
        break;

      default:
        break;
      }
    }
    return false;
  }

  const irr::core::position2d<irr::s32> &getPosition(void)
  {
    return this->_position;
  }

  bool getState(void)
  {
    static int i = 0;

    if (this->_currentEvent != i) {
      i = this->_currentEvent;
      return this->_leftButtonDown;
    } else{
      return false;
    }
  }

private:

  irr::core::position2d<irr::s32> _position;
  bool  _leftButtonDown;
  int   _currentEvent;
};

#endif
