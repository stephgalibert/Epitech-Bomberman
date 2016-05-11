//
// IndestructibleBlock.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 18:22:34 2016 stephane galibert
// Last update Sun May  8 18:13:42 2016 stephane galibert
//

#ifndef _INDESTRUCTIBLEBLOCK_HPP_
# define _INDESTRUCTIBLEBLOCK_HPP_

# include "IBlock.hpp"

namespace bbman
{
  class IndestructibleBlock : public IBlock
  {
  public:
    IndestructibleBlock(void);
    virtual ~IndestructibleBlock(void);
    virtual void init(Irrlicht &irr);
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void setMaterialFlag(irr::video::E_MATERIAL_FLAG flag, bool value);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
  private:
    irr::scene::ISceneNode *_node;
  };
}

#endif /* !_BLOCK_HPP_ */
