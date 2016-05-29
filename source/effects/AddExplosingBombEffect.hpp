//
// AddExplosingBombEffect.hpp for indie in /home/galibe_s/rendu/bomberman/source/effects
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:12:49 2016 stephane galibert
// Last update Sun May 29 10:15:32 2016 stephane galibert
//

#ifndef _ADDEXPLOSINGBOMBEFFECT_HPP_
# define _ADDEXPLOSINGBOMBEFFECT_HPP_

# include "APlayer.hpp"
# include "IEffect.hpp"
# include "ExplodingBomb.hpp"

namespace bbman
{
  class AddExplosingBombEffect : public IEffect
  {
  public:
    static const size_t constexpr DURATION = 5.f;
  public:
    AddExplosingBombEffect(APlayer *target);
    virtual ~AddExplosingBombEffect(void);
    virtual void update(irr::f32 delta);
    virtual bool isFinished(void) const;
    virtual void enable(void);
    virtual void restart(void);
    virtual void setDelta(irr::f32 delta);
    virtual size_t getEffectID(void) const;
    virtual irr::f32 getDelta(void) const;
  private:
    irr::f32 _delta;
    APlayer *_target;
    bool _isFinished;
    bool _enabled;
  };
}

#endif /* !_SPEEDUPEFFECT_HPP_ */
