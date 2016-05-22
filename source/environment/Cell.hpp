//
// Cell.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 19 20:10:50 2016 stephane galibert
// Last update Mon May 23 06:05:28 2016 stephane galibert
//

#ifndef _CELL_HPP_
# define _CELL_HPP_

# include <irrlicht.h>
# include "ItemID.hpp"

namespace bbman
{
  struct Cell
  {
    Cell(void)
    {
      this->id = ItemID::II_NONE;
      this->node = ~(0x0LU & 0);
    }
    ItemID id;
    irr::core::aabbox3df nodeBox;
    size_t node;
  };
}

#endif /* !_CELL_HPP_ */
