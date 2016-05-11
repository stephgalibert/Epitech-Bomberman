//
// InputListener.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:07:45 2016 stephane galibert
// Last update Wed May  4 19:09:42 2016 stephane galibert
//

#include "InputListener.hpp"

bbman::InputListener::InputListener(void)
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}

bbman::InputListener::~InputListener(void)
{

}

bool bbman::InputListener::OnEvent(irr::SEvent const& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}

bool bbman::InputListener::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return (KeyIsDown[keyCode]);
}
