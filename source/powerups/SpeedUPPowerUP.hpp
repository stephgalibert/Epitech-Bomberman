//
// SpeedUPPowerUP.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 18:34:04 2016 stephane galibert
// Last update Fri May 27 07:58:33 2016 stephane galibert
//

#ifndef _SPEEDUPPOWERUP_HPP_
# define _SPEEDUPPOWERUP_HPP_

# include <iostream>

# include "IPowerUP.hpp"
# include "SpeedUPEffect.hpp"

namespace bbman
{
  class SpeedUPPowerUP : public IPowerUP
  {
  public:
    SpeedUPPowerUP(void);
    virtual ~SpeedUPPowerUP(void);
    virtual void init(Irrlicht &irr);
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual void explode(void);
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale);
    virtual void affectPlayer(APlayer *player);
    virtual bool hasExplosed(void) const;
  private:
    irr::scene::ISceneNode *_node;
    irr::f32 _delta;
    irr::core::vector3d<irr::s32> _posInMap;
  };
}

#endif /* !_SPEEDUPPOWERUP_HPP_ */
