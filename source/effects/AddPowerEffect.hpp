//
// AddPowerEffect.hpp for indie in /home/galibe_s/rendu/bomberman/source/effects
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed Jun  1 16:24:30 2016 stephane galibert
// Last update Sat Jun  4 16:55:58 2016 avelin_j
//

#ifndef _ADDPOWEREFFECT_HPP_
# define _ADDPOWEREFFECT_HPP_

# include "IEffect.hpp"
# include "APlayer.hpp"

namespace bbman
{
  class AddPowerEffect : public IEffect
  {
  public:
    AddPowerEffect(APlayer *target);
    virtual ~AddPowerEffect(void);
    virtual void update(irr::f32 delta);
    virtual bool isFinished(void) const;
    virtual void enable(void);
    virtual void restart(void);
    virtual void setDelta(irr::f32 delta);
    virtual size_t getEffectID(void) const;
    virtual irr::f32 getDelta(void) const;
    bool testGetEnable(void) const;
    APlayer const *testGetTarget(void) const;
  private:
    irr::f32 _delta;
    APlayer *_target;
    bool _isFinished;
    bool _enabled;
  };
}

#endif /* !_ADDPOWEREFFECT_HPP_ */
