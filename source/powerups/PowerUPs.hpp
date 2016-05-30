//
// PowerUPs.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:47 2016 stephane galibert
// Last update Mon May 30 17:46:49 2016 stephane galibert
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
    void add(Irrlicht &irr, Board *board, irr::core::vector3df const& pos);
    void checkCollision(APlayer *player);
  private:
    void generate(Irrlicht &irr, Board *board, irr::core::vector3df const& pos);
    void generateSpeedUp(Irrlicht &irr, Board *board,
			 irr::core::vector3df const& pos);
    void generateAddExplosingBomb(Irrlicht &irr, Board *board,
				  irr::core::vector3df const& pos);
    std::list<IPowerUP *> _powerUPs;
    tools::Generator _generator;
    irr::f32 _delta;
  };
}

# endif /* !_POWERUPS_HPP_ */
