//
// TimeOut.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 28 08:20:16 2016 stephane galibert
// Last update Sat May 28 18:54:56 2016 stephane galibert
//

#include "TimeOut.hpp"

//# include "TimeOutAsyncTask.hpp"
//TimeOutAsyncTask *_asynctask;
//this->_asynctask = NULL;
/*if (this->_asynctask && this->_asynctask->isRunning()) {
  this->_asynctask->stop();
  while (!this->_asynctask->isFinished());
  delete (this->_asynctask);
  }*/
//this->_asynctask = new TimeOutAsyncTask(irr, board);
//this->_asynctask = new TimeOutAsyncTask(irr, board);
/*if ((int)this->_delta < 10.0000f) {
  this->_delta += delta;
  if (this->_delta >= 10.0000f) {
  pool->addTask(this->_asynctask);
  }
  }*/

bbman::CacheManager<std::string, bbman::MemoryFile> bbman::TimeOut::SoundCache;

bbman::TimeOut::TimeOut(void)
{
  this->_delta = 0;
  this->_deltaAnim = 0;
  this->_step = 0;
  this->_board = NULL;
}

bbman::TimeOut::~TimeOut(void)
{

}

void bbman::TimeOut::init(Irrlicht &irr, Board *board)
{
  (void)irr;
  try {
    if (!SoundCache.find("explosion")) {
      SoundCache.insert("explosion", MemoryFile("./asset/sound/explosion.wav"));
      SoundCache["explosion"].load();
    }
    this->_sounds.addSample("explosion", SoundCache["explosion"]);
    this->_sounds.setVolumeBySample("explosion", 70.f);
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }
  this->_board = board;
}

void bbman::TimeOut::init(Irrlicht &irr, Board *board, Loader const& loader)
{
  (void)loader;
  (void)irr;
  try {
    if (!SoundCache.find("explosion")) {
      SoundCache.insert("explosion", MemoryFile("./asset/sound/explosion.wav"));
      SoundCache["explosion"].load();
    }
    this->_sounds.addSample("explosion", SoundCache["explosion"]);
    this->_sounds.setVolumeBySample("explosion", 50.f);
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }

  this->_board = board;
  //TimeOut const& out = loader.getTimeOut();
  //setDelta(out.getDelta());
}

void bbman::TimeOut::update(ThreadPool *pool, Irrlicht &irr, irr::f32 delta)
{
  this->_delta += delta;
  if (this->_delta >= 60.0000f) {
    narrowBoard(irr);
    this->_delta = 0.f;
  }
}

irr::f32 bbman::TimeOut::getDelta(void) const
{
  return (this->_delta);
}

void bbman::TimeOut::setDelta(irr::f32 delta)
{
  this->_delta = delta;
}

void bbman::TimeOut::north(Irrlicht &irr)
{
  while (this->_current.Z < this->_board->getMap().h - 2 - this->_step) {
    putBlock(irr);
    ++this->_current.Z;
  }
}

void bbman::TimeOut::south(Irrlicht &irr)
{
  while (this->_current.Z > this->_begin.Z) {
    putBlock(irr);
    --this->_current.Z;
  }
}

void bbman::TimeOut::east(Irrlicht &irr)
{
  while (this->_current.X < this->_board->getMap().w - 2 - this->_step) {
    putBlock(irr);
    ++this->_current.X;
  }
}

void bbman::TimeOut::west(Irrlicht &irr)
{
  while (this->_current.X >= this->_begin.X) {
    putBlock(irr);
    --this->_current.X;
  }
}

void bbman::TimeOut::narrowBoard(Irrlicht &irr)
{
  this->_begin.X = this->_step + 1;
  this->_begin.Z = this->_step + 1;
  this->_current = this->_begin;

  if (this->_step < 3)
    {
      try {
	this->_sounds.play("explosion");
      } catch (std::runtime_error const& e) {
	std::cerr << e.what() << std::endl;
      }
      north(irr);
      east(irr);
      south(irr);
      west(irr);
      ++this->_step;
    }
}
#include <unistd.h>
void bbman::TimeOut::putBlock(Irrlicht &irr)
{
  IEntity *entity = this->_board->getEntityByPosition(this->_current);
  if (entity) {
    entity->explode();
  }
  this->_board->buildInbrkable(irr, this->_current.X, this->_current.Z);
}
