//
// AStar.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 21 16:44:05 2016 stephane galibert
// Last update Sat May 21 16:49:53 2016 stephane galibert
//

#ifndef _IASTAR_HPP_
# define _IASTAR_HPP_

# include <irrlicht.h>
# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <list>
# include <stdexcept>
# include <algorithm>

# include "Map.hpp"
# include "ItemID.hpp"
# include "Cell.hpp"

namespace bbman
{
  class IAStar
  {
  public:
    ~IAStar(void) {};
    virtual void addBlockType(bbman::ItemID const& blocktype) = 0;
    virtual void compute(const Map<bbman::Cell> &map, irr::core::vector3d<irr::s32> const& p1,
            irr::core::vector3d<irr::s32> const& p2) = 0;
    virtual irr::core::vector3d<irr::s32> getNextResult(void) = 0;
    virtual void reset(void) = 0;
    virtual size_t getSize() = 0;
  };
}

#endif /* !_IASTAR_HPP_ */
