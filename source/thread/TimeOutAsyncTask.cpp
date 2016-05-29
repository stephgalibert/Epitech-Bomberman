//
// TimeOutAsyncTask.cpp for indie in /home/galibe_s/rendu/bomberman/source/threadPool
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 28 08:43:29 2016 stephane galibert
// Last update Sat May 28 15:16:48 2016 stephane galibert
//

#include "TimeOutAsyncTask.hpp"

bbman::TimeOutAsyncTask::TimeOutAsyncTask(Irrlicht &irr, Board *board)
  : _irr(irr)
{
  this->_isRunning = false;
  this->_finished = false;
  this->_board = board;
  this->_delta = 0;
}

bbman::TimeOutAsyncTask::~TimeOutAsyncTask(void)
{

}

void bbman::TimeOutAsyncTask::start(void)
{
  tools::Chronometer timer;
  irr::f32 delta = 0;

  this->_isRunning = true;
  timer.setTimer(this->_irr.getTimer());
  while (this->_isRunning /*&& !this->_board->hasWinners()*/)
    {
      delta = timer.restart() / 1000.f;
      this->_delta += delta;
      if (this->_delta > 0.5f) {
	narrowBoard();
	this->_delta = 0;
      }
    }
}

void bbman::TimeOutAsyncTask::stop(void)
{
  this->_isRunning = false;
}

void bbman::TimeOutAsyncTask::setFinished(bool v)
{
  this->_finished = v;
}

bool bbman::TimeOutAsyncTask::isFinished(void) const
{
  return (this->_finished);
}

bool bbman::TimeOutAsyncTask::isRunning(void) const
{
  return (this->_isRunning);
}

#include <unistd.h>
void bbman::TimeOutAsyncTask::narrowBoard(void)
{
  static int nbCall = 0;
  irr::core::vector3d<irr::s32> begin;// = this->_board->narrow();
  irr::core::vector3d<irr::s32> current = begin;

  while (!this->_finished && current.Z < this->_board->getMap().h - 2 - nbCall) {
    putBlock(current);
    ++current.Z;
  }
  while (!this->_finished && current.X < this->_board->getMap().w - 2 - nbCall) {
    putBlock(current);
    ++current.X;
  }
  while (!this->_finished && current.Z > begin.Z) {
    putBlock(current);
    --current.Z;
  }
  while (!this->_finished && current.X > begin.X) {
    putBlock(current);
    --current.X;
  }
  ++nbCall;
}

void bbman::TimeOutAsyncTask::putBlock(irr::core::vector3d<irr::s32> const& pos)
{
  if (pos != irr::core::vector3d<irr::s32>(0, 0, 0)) {
    IEntity *entity = this->_board->getEntityByPosition(pos);
    if (entity) {
      entity->explode();
    }
    this->_board->buildInbrkable(this->_irr, pos.X, pos.Z);
    usleep(10000);
  }
}
