//
// ExplosionTask.hpp for indie in /home/galibe_s/rendu/bomberman/source/thread
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 30 16:07:37 2016 stephane galibert
// Last update Tue May 31 12:43:53 2016 stephane galibert
//

#ifndef _EXPLOSIONTASK_HPP_
# define _EXPLOSIONTASK_HPP_

# include <irrlicht.h>

# include "Irrlicht.hpp"
# include "ITask.hpp"
# include "Chronometer.hpp"

namespace bbman
{
  class ExplosionTask : public ITask
  {
  public:
    ExplosionTask(Irrlicht &irr);
    virtual ~ExplosionTask(void);
    virtual void start(void);
    virtual void stop(void);
    virtual void setFinished(bool v);
    virtual bool isFinished(void) const;
    virtual bool isRunning(void) const;
    void setPosition(irr::core::vector3df const& pos);
  private:
    tools::Chronometer _timer;
    irr::scene::IParticleSystemSceneNode *_ps;
    irr::core::vector3df _pos;
    bool _isFinished;
    bool _isRunning;
  };
}

#endif /* !_EXPLOSIONTASK_HPP_ */
