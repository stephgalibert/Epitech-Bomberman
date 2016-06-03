//
// DestructibleBlock.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 19:11:32 2016 stephane galibert
// Last update Fri Jun  3 21:23:18 2016 stephane galibert
//

#ifndef _DESTRUCTIBLEBLOCK_HPP_
# define _DESTRUCTIBLEBLOCK_HPP_

# include <iostream>

# include "Explosion.hpp"
# include "IBlock.hpp"

namespace bbman
{
  class DestructibleBlock : public IBlock
  {
  public:
    DestructibleBlock(void);
    virtual ~DestructibleBlock(void);
    virtual void init(Irrlicht &irr, std::string const& color = "");
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void setMaterialFlag(irr::video::E_MATERIAL_FLAG flag, bool value);
    virtual void addAnimation(irr::scene::ISceneNodeAnimator *anim);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual void explode(Board *board);
    virtual void playExplosion(void);
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale);
    virtual bool hasExplosed(void) const;
    virtual ItemID getID(void) const;
    virtual std::string const& getColor(void) const;
    virtual void setColor(std::string const& color);
    virtual void disableAnimation(void);
  private:
    bool _anim;
    irr::scene::ISceneNode *_node;
    Explosion *_explosion;
    irr::core::vector3d<irr::s32> _posInMap;
    bool _explosed;
    std::string _color;
  };
}

#endif /* !_DESTRUCTIBLEBLOCK_HPP_ */
