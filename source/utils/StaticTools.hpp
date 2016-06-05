//
// StaticTools.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:50:51 2016 stephane galibert
// Last update Sun Jun  5 13:37:23 2016 stephane galibert
//

#ifndef _STATICTOOLS_HPP_
# define _STATICTOOLS_HPP_

# include <irrlicht.h>
# include <cmath>

# include "ThreadPool.hpp"
# include "Direction.hpp"

namespace tools
{
  class StaticTools
  {
  public:
    static bbman::ThreadPool *ThreadPool;
  public:
    static irr::u32 getDistance2D(irr::core::vector3d<irr::s32> const& p1,
				  irr::core::vector3d<irr::s32> const& p2);
    static void initThreadPool(size_t nbThread);
    static void deleteThreadPool(void);
    static bbman::Direction getDirByCoord(irr::core::vector3d<irr::s32> const& p1, irr::core::vector3d<irr::s32> const& p2);
    static int volume(std::string const& volume, int value = -1);
  };
}

#endif /* !_STATICTOOLS_HPP_ */
