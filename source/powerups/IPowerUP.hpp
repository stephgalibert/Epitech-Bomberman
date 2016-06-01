//
// IPowerUP.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:02:45 2016 stephane galibert
// Last update Tue May 31 20:24:16 2016 stephane galibert
//

#ifndef _IPOWERUP_HPP_
# define _IPOWERUP_HPP_

# include <irrlicht.h>

# include "APlayer.hpp"
# include "IEntity.hpp"
# include "Irrlicht.hpp"

namespace bbman
{
  class IPowerUP : public IEntity
  {
  public:
    virtual ~IPowerUP(void) {}
    virtual void init(Irrlicht &irr, std::string const& color = "") = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual void explode(Board *board) = 0;
    virtual void playExplosion(void) = 0;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale) = 0;
    virtual void affectPlayer(APlayer *player) = 0;
    virtual bool hasExplosed(void) const = 0;
    virtual std::string const& getColor(void) const = 0;
    virtual void setColor(std::string const& color) = 0;
  };
}

#endif /* !_IPOWERUP_HPP_ */
