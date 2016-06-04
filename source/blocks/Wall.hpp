//
// Wall.hpp for indie in /home/galibe_s/rendu/bomberman/source/blocks
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu Jun  2 17:11:02 2016 stephane galibert
// Last update Sat Jun  4 14:54:42 2016 stephane galibert
//

#ifndef _WALL_HPP_
# define _WALL_HPP_

# include "IBlock.hpp"

namespace bbman
{
  class Wall : public IBlock
  {
  public:
    Wall(void);
    virtual ~Wall(void);
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
    virtual void disableAnimation(void) {}
    virtual int getScoreValue(void) const  {return 0;}
  private:
    //irr::scene::ISceneNode *_node;
    irr::scene::IMeshSceneNode *_mesh;
    irr::core::vector3d<irr::s32> _posInMap;
    std::string _color;
  };
}

#endif /* !_WALL_HPP_ */
