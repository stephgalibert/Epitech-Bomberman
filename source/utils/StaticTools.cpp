//
// StaticTools.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:54:23 2016 stephane galibert
// Last update Sun Jun  5 13:37:31 2016 stephane galibert
//

#include "StaticTools.hpp"

bbman::ThreadPool *tools::StaticTools::ThreadPool = NULL;

irr::u32 tools::StaticTools::getDistance2D(irr::core::vector3d<irr::s32> const& p1,
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

int tools::StaticTools::volume(std::string const& volume, int value)
{
  static int music = 0;
  static int effect = 0;
  if (value > -1) {
    if (volume == "music") {
      music = value;
    } else if (volume == "effect") {
      effect = value;
    }
  }
  return ((volume == "music") ? music : effect);
}
