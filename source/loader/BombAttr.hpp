//
// BombAttr.hpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 26 10:30:09 2016 stephane galibert
// Last update Fri Jun  3 11:50:17 2016 stephane galibert
//

#ifndef _BOMBATTR_HPP_
# define _BOMBATTR_HPP_

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <list>
# include <functional>
# include <iterator>
# include <sstream>

# include "APlayer.hpp"
# include "Irrlicht.hpp"
# include "IBomb.hpp"
# include "ExplodingBomb.hpp"

namespace bbman
{
  class BombAttr
  {
  public:
    BombAttr(void);
    ~BombAttr(void);
    void set(IBomb **bombs,
	     std::vector<APlayer *> &players,
	     Irrlicht &irr,
	     std::string const& name,
	     std::string const& value);
  private:
    void setBombID(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		   std::string const& v);
    void setTimer(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		  std::string const& v);
    void setPosition(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		     std::string const& v);
    void setOwner(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		  std::string const& v);
    void setExplosed(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		     std::string const& v);
    void setLol(IBomb **bombs, std::vector<APlayer *> &player, Irrlicht &irr,
		std::string const& v);
    std::map<std::string, std::function<void(IBomb **, std::vector<APlayer *> &,
					     Irrlicht &,
					     std::string const&)> > _attrs;
  };
}

#endif /* !_BOMBATTR_HPP_ */
