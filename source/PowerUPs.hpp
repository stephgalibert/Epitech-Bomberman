//
// PowerUPs.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:47 2016 stephane galibert
// Last update Tue May 10 04:59:53 2016 stephane galibert
//

#ifndef _POWERUPS_HPP_
# define _POWERUPS_HPP_

# include <irrlicht.h>
# include <list>
# include <algorithm>

# include "IPlayer.hpp"
# include "IPowerUP.hpp"
# include "SpeedUPPowerUP.hpp"
# include "Irrlicht.hpp"
# include "Generator.hpp"
# include "Board.hpp"

namespace bbman
{
  class PowerUPs
  {
  public:
    static const size_t constexpr DELAY = 5.f;
  public:
    PowerUPs(void);
    ~PowerUPs(void);
    void update(Irrlicht &irr, float delta, Board *board);
    void checkCollision(IPlayer *player);
    void setArea(irr::core::vector3df const& max);
  private:
    void generate(Irrlicht &irr, Board *board);
    void generateSpeedUp(Irrlicht &irr, Board *board);
    bool isFree(IPowerUP *powerUP, Board *board) const;
    std::list<IPowerUP *> _powerUPs;
    tools::Generator _generator;
    irr::f32 _delta;
    irr::core::vector3df _min;
    irr::core::vector3df _max;
  };
}

# endif /* !_POWERUPS_HPP_ */
