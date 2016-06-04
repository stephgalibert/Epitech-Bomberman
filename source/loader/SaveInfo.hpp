//
// SaveInfo.hpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun Jun  5 00:58:04 2016 stephane galibert
// Last update Sun Jun  5 01:25:50 2016 stephane galibert
//

#ifndef _SAVEINFO_HPP_
# define _SAVEINFO_HPP_

# include <irrlicht.h>

# include <fstream>
# include <map>
# include <functional>

namespace bbman
{
  class SaveInfo
  {
  public:
    SaveInfo(void);
    ~SaveInfo(void);
    void parse(std::string const& filename);
    irr::f32 getTimer(void) const;
    size_t getNbPlayers(void) const;
  private:
    void infoNbPlayers(std::ifstream &ifs);
    void infoTimer(std::ifstream &ifs);
    std::map<std::string, std::function<void(std::ifstream &)> > _infos;

    irr::f32 _timer;
    size_t _nbPlayers;
  };
}

#endif /* !_SAVEINFO_HPP_ */
