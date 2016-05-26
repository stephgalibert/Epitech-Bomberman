//
// Bomb.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 15:15:50 2016 stephane galibert
// Last update Thu May 26 12:26:08 2016 stephane galibert
//

#ifndef _IBOMB_HPP_
# define _IBOMB_HPP_

# include <list>
# include <vector>
# include <iostream>

# include "IEntity.hpp"

namespace bbman
{
  class IBomb : public IEntity
  {
  public:
    virtual ~IBomb(void) {}
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual bool isInExplosion(IEntity *entity, irr::core::vector3df const& scale) = 0;
    virtual bool isInDeflagration(IEntity *entity, irr::core::vector3df const& scale) = 0;
    virtual IBomb *clone(void) const = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual std::string getName(void) const = 0;
    virtual bool isExplosing(void) const = 0;
    virtual bool hasExplosed(void) const = 0;
    virtual irr::f32 getDelay(void) const = 0;
    virtual irr::f32 getDelta(void) const = 0;
    virtual void setDelta(irr::f32 value) = 0;
    virtual void explode(void) = 0;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale) = 0;
    virtual size_t getOwnerID(void) const = 0;
    virtual size_t getBombID(void) const = 0;
  };

  inline std::ostream &operator<<(std::ostream &flux, bbman::IBomb const& bomb)
  {
    std::string timer = std::to_string((int)bomb.getDelta());
    irr::core::vector3df const& pos = bomb.getPosition();
    std::string position = std::to_string((int)pos.X)
      + " " + std::to_string((int)pos.Y)
      + " " + std::to_string((int)pos.Z);
    std::string owner = std::to_string(bomb.getOwnerID());
    std::string id = std::to_string(bomb.getBombID());

    flux << "BID:" << id << ";timer:" << timer << ";pos:" << position
	 << ";owner:" << owner << ";" << std::endl;
    return (flux);
  }

}

#endif /* !_IBOMB_HPP_ */
