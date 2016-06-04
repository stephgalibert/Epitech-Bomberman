//
// DestructibleBlock.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:50:50 2016 avelin_j
// Last update Sat Jun  4 23:51:27 2016 avelin_j
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
    virtual int getScoreValue(void) const;
    irr::scene::ISceneNode const *testGetNode(void) const;
    Explosion const *testGetExplosion(void) const;
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
