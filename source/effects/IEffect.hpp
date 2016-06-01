//
// IEffect.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 21:08:19 2016 stephane galibert
// Last update Wed Jun  1 16:26:30 2016 stephane galibert
//

#ifndef _IEFFECT_HPP_
# define _IEFFECT_HPP_

# include <irrlicht.h>

namespace bbman
{
  class IEffect
  {
  public:
    virtual ~IEffect(void) {}
    virtual void update(irr::f32 delta) = 0;
    virtual bool isFinished(void) const = 0;
    virtual void enable(void) = 0;
    virtual void restart(void) = 0;
    virtual void setDelta(irr::f32 delta) = 0;
    virtual size_t getEffectID(void) const = 0;
    virtual irr::f32 getDelta(void) const = 0;
  };
}

#endif /* !_IEFFECT_HPP_ */
