//
// InputListener.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/examples/04.Movement
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May  3 18:39:36 2016 stephane galibert
// Last update Fri May 27 15:45:24 2016 stephane galibert
//

#ifndef _INPUTLISTENER_HPP_
# define _INPUTLISTENER_HPP_

# include <vector>
# include <stdexcept>

# include "irrlicht.h"

namespace bbman
{
  class InputListener : public irr::IEventReceiver
  {
  public:
    InputListener(void);
    ~InputListener(void);
    virtual bool OnEvent(irr::SEvent const& event);
    bool IsKeyDown(irr::EKEY_CODE keyCode) const;
    irr::SEvent::SJoystickEvent const& getJoystickState(size_t idx) const;
  private:
    bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
    std::vector<irr::SEvent::SJoystickEvent> _joystickStates;
  };
}

#endif /* !_INPUTLISTENER_HPP_ */
