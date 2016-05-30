//
// IEntity.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 03:11:29 2016 stephane galibert
// Last update Mon May 30 08:54:25 2016 stephane galibert
//

#ifndef _IENTITY_HPP_
# define _IENTITY_HPP_

# include <irrlicht.h>
# include "Irrlicht.hpp"

namespace bbman
{
  class Board;

  class IEntity
  {
  public:
    virtual ~IEntity(void) {}
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual void explode(Board *board) = 0;
    virtual bool hasExplosed(void) const = 0;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale) = 0;
  };
}

#endif /* !_IENTITY_HPP_ */
