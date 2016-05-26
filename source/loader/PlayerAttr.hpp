//
// PlayerAttr.hpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 25 20:03:57 2016 stephane galibert
// Last update Thu May 26 11:31:57 2016 stephane galibert
//

#ifndef _PLAYERATTR_HPP_
# define _PLAYERATTR_HPP_

# include <string>
# include <map>
# include <functional>
# include <cstdlib>
# include <algorithm>
# include <iterator>
# include <sstream>

# include "Irrlicht.hpp"
# include "APlayer.hpp"
# include "HumanPlayer.hpp"
# include "SpeedUPEffect.hpp"

namespace bbman
{
  class PlayerAttr
  {
  public:
    PlayerAttr(void);
    ~PlayerAttr(void);
    void set(APlayer **player, Irrlicht &irr, std::string const& name,
	     std::string const& value);
  private:
    void setPlayerID(APlayer **player, Irrlicht &irr, std::string const& value);
    void setPosition(APlayer **player, Irrlicht &irr, std::string const& value);
    void setScore(APlayer **player, Irrlicht &irr, std::string const& value);
    void setAlive(APlayer **player, Irrlicht &irr, std::string const& value);
    void setRotation(APlayer **player, Irrlicht &irr, std::string const& value);
    void addEffect(APlayer **player, Irrlicht &irr, std::string const& value);
    void addBombInBm(APlayer **player, Irrlicht &irr, std::string const& value);
    std::map<std::string, std::function<void(APlayer **, Irrlicht &, std::string const&)> > _attrs;
  };
}

# endif /* !_PLAYERATTR_HPP_ */
