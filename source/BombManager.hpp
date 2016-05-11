//
// BombManager.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 20:29:11 2016 stephane galibert
// Last update Tue May 10 04:45:08 2016 stephane galibert
//

#ifndef _BOMBMANAGER_HPP_
# define _BOMBMANAGER_HPP_

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
  private:
    std::vector<IBomb *> _bombs;
    std::vector<IBomb *>::const_iterator _selectedBomb;
  };
}

#endif /* !_BOMBMANAGER_HPP_ */
