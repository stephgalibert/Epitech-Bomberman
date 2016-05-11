//
// IPowerUP.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:45 2016 stephane galibert
// Last update Sun May  8 20:15:37 2016 stephane galibert
//

#ifndef _IPOWERUP_HPP_
# define _IPOWERUP_HPP_

# include <irrlicht.h>

# include "IPlayer.hpp"
# include "IEntity.hpp"
# include "Irrlicht.hpp"

namespace bbman
{
  class IPowerUP : public IEntity
  {
  public:
    virtual ~IPowerUP(void) {}
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual void affectPlayer(IPlayer *player) = 0;
  };
}

#endif /* !_IPOWERUP_HPP_ */
