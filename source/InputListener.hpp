//
// InputListener.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/examples/04.Movement
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May  3 18:39:36 2016 stephane galibert
// Last update Wed May  4 19:11:21 2016 stephane galibert
//

#ifndef _INPUTLISTENER_HPP_
# define _INPUTLISTENER_HPP_

# include "irrlicht.h"

namespace bbman
{
  class InputListener : public irr::IEventReceiver
  {
  public:
    InputListener(void);
    ~InputListener(void);
    virtual bool OnEvent(irr::SEvent const& event);
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

  private:
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  };
}

#endif /* !_INPUTLISTENER_HPP_ */
