//
// BombManager.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 20:29:11 2016 stephane galibert
// Last update Sun May 29 09:28:46 2016 stephane galibert
//

#ifndef _BOMBMANAGER_HPP_
# define _BOMBMANAGER_HPP_

# include <iostream>
# include <map>

# include "IBomb.hpp"

namespace bbman
{
  class BombManager
  {
  public:
    BombManager(void);
    ~BombManager(void);
    void addBomb(IBomb *type);
    IBomb *getSelectedBomb(void);
    void operator++(void);
    void operator--(void);
    std::map<size_t, std::pair<size_t, IBomb *> > const& getBombs(void) const;
    std::map<size_t, std::pair<size_t, IBomb *> >::iterator const& getCurrent(void) const;
    // add
  private:
    // <nb, bomb>
    std::map<size_t, std::pair<size_t, IBomb *> > _bombs;
    std::map<size_t, std::pair<size_t, IBomb *> >::iterator _selectedBomb;
  };

  std::ostream &operator<<(std::ostream &flux, BombManager const& bm);
}

#endif /* !_BOMBMANAGER_HPP_ */
