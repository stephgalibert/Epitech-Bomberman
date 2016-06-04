//
// IBlock.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 16:55:19 2016 stephane galibert
// Last update Sat Jun  4 14:55:05 2016 stephane galibert
//

#ifndef _IBLOCK_HPP_
# define _IBLOCK_HPP_

# include "IEntity.hpp"
# include "ItemID.hpp"

namespace bbman
{
  class IBlock : public IEntity
  {
  public:
    virtual ~IBlock(void) {}
    virtual void init(Irrlicht &irr, std::string const& color = "") = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void setMaterialFlag(irr::video::E_MATERIAL_FLAG flag, bool value) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual void addAnimation(irr::scene::ISceneNodeAnimator *anim) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual void explode(Board *board) = 0;
    virtual void playExplosion(void) = 0;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale) = 0;
    virtual bool hasExplosed(void) const = 0;
    virtual ItemID getID(void) const = 0;
    virtual std::string const& getColor(void) const = 0;
    virtual void setColor(std::string const& color) = 0;
    virtual void disableAnimation(void) = 0;
    virtual int getScoreValue(void) const = 0;
  };
}

#endif /* !_IBLOCK_HPP_ */
