//
// TimeOut.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:44:07 2016 avelin_j
// Last update Sun Jun  5 13:23:27 2016 stephane galibert
//

#include "TimeOut.hpp"
#include "ExplodingBomb.hpp"

bbman::TimeOut::TimeOut(void)
{
  this->_delta = 0;
  this->_deltaAnim = 0;
  this->_step = 0;
  this->_board = NULL;
  this->_direction = Direction::DIR_NONE;
}

bbman::TimeOut::~TimeOut(void)
{
  for (auto it : this->_anims) {
    delete (it.first);
  }
}

void bbman::TimeOut::init(Irrlicht &irr, Board *board)
{
  (void)irr;
  this->_board = board;
}

void bbman::TimeOut::update(Irrlicht &irr, irr::f32 delta)
{
  if (this->_delta >= TimeOut::Release) {
    this->_deltaAnim += delta;
    if (this->_deltaAnim >= TimeOut::ReleaseStep) {
      narrowBoard(irr);
    }
  }
  else {
    this->_delta += delta;
  }
  updateAnim();
}

irr::f32 bbman::TimeOut::getDelta(void) const
{
  return (this->_delta);
}

void bbman::TimeOut::setDelta(irr::f32 delta)
{
  this->_delta = delta;
}

void bbman::TimeOut::setDeltaAnim(irr::f32 delta)
{
  this->_deltaAnim = delta;
}

irr::f32 bbman::TimeOut::getDeltaAnim(void) const
{
  return (this->_deltaAnim);
}

void bbman::TimeOut::setStep(int step)
{
  this->_step = step;
}

int bbman::TimeOut::getStep(void) const
{
  return (this->_step);
}

void bbman::TimeOut::setDirection(Direction dir)
{
  this->_direction = dir;
}

bbman::Direction bbman::TimeOut::getDirection(void) const
{
  return (this->_direction);
}

void bbman::TimeOut::setBegin(irr::core::vector3d<irr::u32> const& v)
{
  this->_begin = v;
}

irr::core::vector3d<irr::u32> const& bbman::TimeOut::getBegin(void) const
{
  return (this->_begin);
}

void bbman::TimeOut::setCurrent(irr::core::vector3d<irr::u32> const& v)
{
  this->_current = v;
}

irr::core::vector3d<irr::u32> const& bbman::TimeOut::getCurrent(void) const
{
  return (this->_current);
}

bbman::Board const *bbman::TimeOut::testGetBoard(void) const
{
  return (this->_board);
}

void bbman::TimeOut::updateAnim(void)
{
  for (std::list<std::pair<IBlock *, irr::scene::ISceneNodeAnimator *> >::iterator
	 it = this->_anims.begin() ; it != this->_anims.end();) {
    if ((*it).second->hasFinished()) {
      irr::core::vector3d<irr::s32> const& pos = (*it).first->getPosInMap(_board->getScale());
      this->_board->disableDirection(pos.X, pos.Z);
      std::list<IEntity *> const& entities = this->_board->getEntityByPosition(pos);
      for (auto &it : entities) {
	it->disableAnimation();
	it->explode(this->_board);
      }
      this->_board->registerBlock(it->first);

      /*Map<Cell> &map = this->_board->getMap();
      for (int i = 0 ; i < map.h ; ++i) {
	for (int j = 0 ; j < map.w ; ++j) {
	  std::cout << (int)map.at(j, i).id << " ";
	}
	std::cout << std::endl;
      }
      std::cout << std::endl;*/

      it = this->_anims.erase(it);
    }
    else {
      ++it;
    }
  }
}

void bbman::TimeOut::narrowBoard(Irrlicht &irr)
{
  if (this->_step < 4)
    {
      if (this->_direction == Direction::DIR_NORTH) {
	north(irr);
      }
      else if (this->_direction == Direction::DIR_EAST) {
	east(irr);
      }
      else if (this->_direction == Direction::DIR_SOUTH) {
	south(irr);
      }
      else if (this->_direction == Direction::DIR_WEST) {
	west(irr);
      }
      if (this->_direction == Direction::DIR_NONE) {
	this->_direction = Direction::DIR_NORTH;
	this->_begin.X = this->_step + 1;
	this->_begin.Z = this->_step + 1;
	this->_current = this->_begin;
	++this->_step;
      }
    }
}

void bbman::TimeOut::north(Irrlicht &irr)
{
  if (this->_current.Z < this->_board->getMap().h - 1 - this->_step) {
    putBlock(irr);
    ++this->_current.Z;
  }
  if (this->_current.Z >= this->_board->getMap().h - 1 - this->_step) {
    this->_direction = Direction::DIR_EAST;
  }
}

void bbman::TimeOut::south(Irrlicht &irr)
{
  if (this->_current.Z > this->_begin.Z) {
    putBlock(irr);
    --this->_current.Z;
  }
  if (this->_current.Z <= this->_begin.Z) {
    this->_direction = Direction::DIR_WEST;
  }
}

void bbman::TimeOut::east(Irrlicht &irr)
{
  if (this->_current.X < this->_board->getMap().w - 1 - this->_step) {
    putBlock(irr);
    ++this->_current.X;
  }
  if (this->_current.X >= this->_board->getMap().w - 1 - this->_step) {
    this->_direction = Direction::DIR_SOUTH;
  }
}

void bbman::TimeOut::west(Irrlicht &irr)
{
  if (this->_current.X > this->_begin.X) {
    putBlock(irr);
    --this->_current.X;
  }
  if (this->_current.X <= this->_begin.X) {
    this->_direction = Direction::DIR_NONE;
    this->_deltaAnim = 0.f;
  }
}

void bbman::TimeOut::putBlock(Irrlicht &irr)
{
  IBlock *block = this->_board->createInbrkable(irr, this->_current.X, _current.Z);
  if (block) {
    irr::core::vector3df const& pos = block->getPosition();
    irr::scene::ISceneNodeAnimator *anim =
      irr.getSmgr()->createFlyStraightAnimator(irr::core::vector3df(pos.X, pos.Y + 60, pos.Z), pos, 300, false);
    block->addAnimation(anim);
    this->_anims.push_back(std::make_pair(block, anim));
  }
}
