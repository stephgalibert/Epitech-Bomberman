//
// AddExplosingBombPowerUP.hpp for indie in /home/galibe_s/rendu/bomberman/source/powerups
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:10:18 2016 stephane galibert
// Last update Sun May 29 10:10:28 2016 stephane galibert
//

#ifndef _ADDEXPLOSINGBOMBPOWERUP_HPP_
# define _ADDEXPLOSINGBOMBPOWERUP_HPP_

# include <iostream>

# include "IPowerUP.hpp"
# include "AddExplosingBombEffect.hpp"

namespace bbman
{
  class AddExplosingBombPowerUP : public IPowerUP
  {
  public:
    AddExplosingBombPowerUP(void);
    virtual ~AddExplosingBombPowerUP(void);
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

#endif /* !_ADDEXPLOSINGBOMBPOWERUP_HPP_ */
