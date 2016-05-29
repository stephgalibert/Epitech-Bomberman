//
// PowerUPs.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:47 2016 stephane galibert
// Last update Sun May 29 10:19:43 2016 stephane galibert
//

#ifndef _POWERUPS_HPP_
# define _POWERUPS_HPP_

# include <irrlicht.h>
# include <list>
# include <algorithm>

# include "APlayer.hpp"
# include "IPowerUP.hpp"
# include "SpeedUPPowerUP.hpp"
# include "AddExplosingBombPowerUP.hpp"
# include "Irrlicht.hpp"
# include "Generator.hpp"

namespace bbman
{
  class Board;

  class PowerUPs
  {
  public:
    static const size_t constexpr DELAY = 5.f;
  public:
    PowerUPs(void);
    ~PowerUPs(void);
    void update(Irrlicht &irr, float delta, Board *board);
    void checkCollision(APlayer *player);
  private:
    void generate(Irrlicht &irr, Board *board);
    void generateSpeedUp(Irrlicht &irr, Board *board);
    void generateAddExplosingBomb(Irrlicht &irr, Board *board);
    bool isFree(IPowerUP *powerUP, Board *board) const;
    std::list<IPowerUP *> _powerUPs;
    tools::Generator _generator;
    irr::f32 _delta;
  };
}

# endif /* !_POWERUPS_HPP_ */
