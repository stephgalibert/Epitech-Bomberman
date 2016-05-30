//
// InputListener.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:07:45 2016 stephane galibert
// Last update Mon May 30 20:16:42 2016 stephane galibert
//

#include "InputListener.hpp"

bbman::InputListener::InputListener(void)
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i) {
    this->_keyIsDown[i] = false;
  }
  this->_joystickStates.push_back(irr::SEvent::SJoystickEvent());
  this->_joystickStates.push_back(irr::SEvent::SJoystickEvent());
  this->_joystickStates.push_back(irr::SEvent::SJoystickEvent());
}

bbman::InputListener::~InputListener(void)
{

}

bool bbman::InputListener::OnEvent(irr::SEvent const& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
    this->_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  }
  else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
	   && event.JoystickEvent.Joystick < this->_joystickStates.size()) {
    this->_joystickStates[event.JoystickEvent.Joystick] = event.JoystickEvent;
  }
  else if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
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

  return (false);
}

bool bbman::InputListener::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return (this->_keyIsDown[keyCode]);
}

irr::core::position2d<irr::s32> const& bbman::InputListener::getPosition(void)
{
  return this->_position;
}

bool bbman::InputListener::getState(void)
{
  static int i = 0;

  if (this->_currentEvent != i) {
    i = this->_currentEvent;
    return this->_leftButtonDown;
  } else {
    return false;
  }
}

irr::SEvent::SJoystickEvent const& bbman::InputListener::getJoystickState(size_t idx) const
{
  if (idx < this->_joystickStates.size()) {
    return (this->_joystickStates[idx]);
  }
  throw (std::runtime_error("unknown joystick"));
}
