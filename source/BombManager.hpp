//
// BombManager.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 20:29:11 2016 stephane galibert
// Last update Wed May 25 01:26:34 2016 stephane galibert
//

#ifndef _BOMBMANAGER_HPP_
# define _BOMBMANAGER_HPP_

# include <iostream>
# include <vector>

# include "IBomb.hpp"

namespace bbman
{
  class BombManager
  {
  public:
    BombManager(void);
    ~BombManager(void);
    void addBomb(IBomb *type);
    IBomb *getSelectedBomb(void) const;
    void operator++(void);
    void operator--(void);
    std::vector<IBomb *> const& getBombs(void) const;
  private:
    std::vector<IBomb *> _bombs;
    std::vector<IBomb *>::const_iterator _selectedBomb;
  };

  std::ostream &operator<<(std::ostream &flux, BombManager const& bm);
}

#endif /* !_BOMBMANAGER_HPP_ */
