//
// SpeedUPEffect.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 21:11:53 2016 stephane galibert
// Last update Tue May 10 04:09:16 2016 stephane galibert
//

#ifndef _SPEEDUPEFFECT_HPP_
# define _SPEEDUPEFFECT_HPP_

# include "IPlayer.hpp"
# include "IEffect.hpp"

namespace bbman
{
  class SpeedUPEffect : public IEffect
  {
  public:
    static const size_t constexpr DURATION = 5.f;
  public:
    SpeedUPEffect(IPlayer *target);
    virtual ~SpeedUPEffect(void);
    virtual void update(irr::f32 delta);
    virtual bool isFinished(void) const;
    virtual void enable(void);
    virtual void restart(void);
    virtual size_t getEffectID(void) const;
  private:
    irr::f32 _delta;
    IPlayer *_target;
    bool _isFinished;
    bool _enabled;
  };
}

#endif /* !_SPEEDUPEFFECT_HPP_ */
