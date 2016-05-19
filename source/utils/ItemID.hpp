//
// ItemID.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:25:34 2016 stephane galibert
// Last update Mon May 16 16:29:31 2016 stephane galibert
//

#ifndef _ITEMID_HPP_
# define _ITEMID_HPP_

namespace bbman
{
  enum class ItemID : int
  {
    II_NONE = 0,
    II_BLOCK_INBRKABLE = 1,
    II_BLOCK_BRKABLE = 2,
    II_PLAYER = 3,
    II_BOMBS = 4
  };
}

#endif /* !_ITEMID_HPP_ */