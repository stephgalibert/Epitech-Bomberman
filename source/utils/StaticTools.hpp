//
// StaticTools.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:50:51 2016 stephane galibert
// Last update Mon May 23 17:59:49 2016 stephane galibert
//

#ifndef _STATICTOOLS_HPP_
# define _STATICTOOLS_HPP_

# include <irrlicht.h>
# include <cmath>

namespace tools
{
  class StaticTools
  {
  public:
    static irr::s32 getDistance2D(irr::core::vector3d<irr::s32> const& p1,
				  irr::core::vector3d<irr::s32> const& p2);

  };
}

#endif /* !_STATICTOOLS_HPP_ */
