//
// PowerUPs.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:09:51 2016 avelin_j
// Last update Sun Jun  5 00:10:38 2016 avelin_j
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
    void checkCollision(APlayer *player, irr::core::vector3df const& scale);
    std::list<IPowerUP *>const& getPowerUPs() const;
    irr::f32 testGetDelta(void) const;
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
