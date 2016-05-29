//
// TimeOutAsyncTask.hpp for indie in /home/galibe_s/rendu/bomberman/source/threadPool
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 28 08:43:39 2016 stephane galibert
// Last update Sat May 28 14:24:11 2016 stephane galibert
//

#ifndef _TIMEOUTASYNCTASK_HPP_
# define _TIMEOUTASYNCTASK_HPP_

# include <iostream>
# include <string>

# include "Irrlicht.hpp"
# include "Board.hpp"
# include "ITask.hpp"
# include "Chronometer.hpp"

namespace bbman
{
  class TimeOutAsyncTask : public ITask
  {
  public:
    TimeOutAsyncTask(Irrlicht &irr, Board *board);
    virtual ~TimeOutAsyncTask(void);
    virtual void start(void);
    virtual void stop(void);
    virtual void setFinished(bool v);
    virtual bool isFinished(void) const;
    virtual bool isRunning(void) const;
    void narrowBoard(void);
    void putBlock(irr::core::vector3d<irr::s32> const& pos);
  private:
    Irrlicht &_irr;
    bool _isRunning;
    bool _finished;
    Board *_board;
    irr::f32 _delta;
  };
}

#endif /* !_TIMEOUTASYNCTASK_HPP_ */
