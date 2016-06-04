//
// Loader.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 25 14:13:49 2016 stephane galibert
// Last update Sat Jun  4 15:39:06 2016 stephane galibert
//

#ifndef _LOADER_HPP_
# define _LOADER_HPP_

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <functional>
# include <vector>

# include "PlayerAttr.hpp"
# include "BombAttr.hpp"
# include "TimeOutAttr.hpp"
# include "Irrlicht.hpp"
# include "Map.hpp"
# include "Cell.hpp"
# include "APlayer.hpp"
# include "TimeOut.hpp"

namespace bbman
{
  class Loader
  {
  public:
    Loader(void);
    ~Loader(void);
    void load(Irrlicht &irr, std::string const& filename);
    Map<bbman::Cell> const& getMap(void) const;
    std::vector<APlayer *> const& getPlayers(void) const;
    std::list<IBomb *> const& getBombs(void) const;
    TimeOut *getTimeOut(void) const;
    irr::f32 getChrono(void) const;
  private:
    void loadGame(Irrlicht &irr, std::ifstream &ifs);
    void loadMap(Irrlicht &irr, std::ifstream &ifs);
    void loadPlayers(Irrlicht &irr, std::ifstream &ifs);
    void loadBombs(Irrlicht &irr, std::ifstream &ifs);
    void loadTimeOut(Irrlicht &irr, std::ifstream &ifs);
    std::map<std::string, std::function<void(Irrlicht &, std::ifstream &)> > _loads;
    Map<bbman::Cell> _map;
    std::vector<APlayer *> _players;
    std::list<IBomb *> _bombs;
    TimeOut *_timeout;
    irr::f32 _chrono;
  };
}

#endif /* !_LOADER_HPP_ */
