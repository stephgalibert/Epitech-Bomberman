//
// StaticTools.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:54:23 2016 stephane galibert
// Last update Thu Jun  2 14:02:25 2016 stephane galibert
//

#include "StaticTools.hpp"

bbman::ThreadPool *tools::StaticTools::ThreadPool = NULL;

irr::s32 tools::StaticTools::getDistance2D(irr::core::vector3d<irr::s32> const& p1,
					   irr::core::vector3d<irr::s32> const& p2)
{
  return (sqrt(pow(p2.X - p1.X, 2) + pow(p2.Z - p1.Z, 2)));
}

void tools::StaticTools::initThreadPool(size_t nbThread)
{
  if (!tools::StaticTools::ThreadPool) {
    tools::StaticTools::ThreadPool = new bbman::ThreadPool(nbThread);
    tools::StaticTools::ThreadPool->init();
  }
}

void tools::StaticTools::deleteThreadPool(void)
{
  if (tools::StaticTools::ThreadPool) {
    delete (tools::StaticTools::ThreadPool);
    tools::StaticTools::ThreadPool = NULL;
  }
}

bbman::Direction tools::StaticTools::getDirByCoord(irr::core::vector3d<irr::s32> const& p1, irr::core::vector3d<irr::s32> const& p2)
{
  bbman::Direction dir = bbman::Direction::DIR_NONE;
  if (p1.X != p2.X)
    {
      if (p1.X < p2.X) {
	dir = bbman::Direction::DIR_EAST;
      }
      else if (p1.X > p2.X) {
	dir = bbman::Direction::DIR_WEST;
      }
    }
  else if (p1.Z != p2.Z)
    {
      if (p1.Z > p2.Z) {
	dir = bbman::Direction::DIR_SOUTH;
      }
      else if (p1.Z < p2.Z) {
	dir = bbman::Direction::DIR_NORTH;
      }
    }
  return (dir);
}
