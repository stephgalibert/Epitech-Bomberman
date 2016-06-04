//
// Chronometer.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 17:45:43 2016 stephane galibert
// Last update Sat Jun  4 22:29:20 2016 avelin_j
//

#ifndef _CHRONOMETER_HPP_
# define _CHRONOMETER_HPP_

# include <irrlicht.h>

namespace tools
{
  class Chronometer
  {
  public:
    Chronometer(void);
    ~Chronometer(void);
    void setTimer(irr::ITimer *timer);
    irr::f32 restart(void);
    void toggle(void);
    void start(void);
    void pause(void);
    irr::f32 getElapsedTime(void);
    irr::f32 testGetValue(void) const;
    irr::ITimer const *testGetTimer(void) const;
    bool testGetRunning(void) const;
  private:
    irr::ITimer *_timer;
    irr::u32 _now;
    irr::f32 _then;
    bool _running;
    irr::f32 _value;
  };
}

#endif /* !_CHRONOMETER_HPP_ */
