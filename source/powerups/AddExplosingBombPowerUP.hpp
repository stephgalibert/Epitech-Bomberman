//
// AddExplosingBombPowerUP.hpp for indie in /home/galibe_s/rendu/bomberman/source/powerups
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:10:18 2016 stephane galibert
// Last update Sat Jun  4 22:12:38 2016 avelin_j
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
    virtual void init(Irrlicht &irr, std::string const& color = "");
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual void explode(Board *board);
    virtual void playExplosion(void);
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale);
    virtual void affectPlayer(APlayer *player);
    virtual bool hasExplosed(void) const;
    virtual std::string const& getColor(void) const;
    virtual void setColor(std::string const& color);
    irr::scene::IMeshSceneNode const *testGetMesh(void) const;
    irr::f32 testGetDelta(void) const;
  private:
    //irr::scene::ISceneNode *_mesh;
    irr::scene::IMeshSceneNode *_mesh;
    irr::f32 _delta;
    irr::core::vector3d<irr::s32> _posInMap;
    std::string _color;
  };
}

#endif /* !_ADDEXPLOSINGBOMBPOWERUP_HPP_ */
