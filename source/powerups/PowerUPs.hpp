//
// PowerUPs.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:47 2016 stephane galibert
// Last update Fri Jun  3 01:26:08 2016 stephane galibert
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
# include "AddPowerPowerUP.hpp"
# include "Irrlicht.hpp"
# include "Generator.hpp"

namespace bbman
{
  class PowerUPs
  {
  public:
    static const size_t constexpr DELAY = 5.f;
  public:
    PowerUPs(void);
    ~PowerUPs(void);
    void add(Irrlicht &irr, irr::core::vector3df const& pos);
    void checkCollision(APlayer *player,
			irr::core::vector3df const& scale);
  private:
    void generate(Irrlicht &irr, irr::core::vector3df const& pos);
    void generateSpeedUp(Irrlicht &irr, irr::core::vector3df const& pos);
    void generateAddExplosingBomb(Irrlicht &irr,
				  irr::core::vector3df const& pos);
    void generateAddPower(Irrlicht &irr, irr::core::vector3df const& pos);
    std::list<IPowerUP *> _powerUPs;
    tools::Generator _generator;
    irr::f32 _delta;
  };
}

# endif /* !_POWERUPS_HPP_ */
