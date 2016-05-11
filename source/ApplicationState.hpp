//
// ApplicationState.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 15:34:00 2016 stephane galibert
// Last update Wed May  4 15:45:32 2016 stephane galibert
//

#ifndef _APPLICATION_STATE_HPP_
# define _APPLICATION_STATE_HPP_

namespace bbman
{
  enum class ApplicationState : int
    {
      AS_NONE = 0,
      AS_GAME = 1,
      AS_MENU = 2
    };
}

#endif /* !_APPLICATION_STATE_HPP_ */
