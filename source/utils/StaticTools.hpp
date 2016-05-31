//
// StaticTools.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:50:51 2016 stephane galibert
// Last update Tue May 31 10:57:54 2016 stephane galibert
//

#ifndef _STATICTOOLS_HPP_
# define _STATICTOOLS_HPP_

# include <irrlicht.h>
# include <cmath>

# include "ThreadPool.hpp"

namespace tools
{
  class StaticTools
  {
  public:
    static bbman::ThreadPool *ThreadPool;
  public:
    static irr::s32 getDistance2D(irr::core::vector3d<irr::s32> const& p1,
				  irr::core::vector3d<irr::s32> const& p2);
    static void initThreadPool(size_t nbThread);
    static void deleteThreadPool(void);
  };
}

#endif /* !_STATICTOOLS_HPP_ */
