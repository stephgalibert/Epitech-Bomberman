//
// Direction.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 14:30:31 2016 stephane galibert
// Last update Sat May  7 18:40:23 2016 stephane galibert
//

#ifndef _DIRECTION_HPP_
# define _DIRECTION_HPP_

namespace bbman
{
  enum Direction
  {
    DIR_NONE = 0,
    DIR_EAST = 1,
    DIR_WEST = 2,
    DIR_NORTH = 4,
    DIR_SOUTH = 8
  };

  typedef size_t t_direction;
}

#endif /* !_DIRECTION_HPP_ */
