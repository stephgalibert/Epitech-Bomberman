//
// Bomb.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 15:15:50 2016 stephane galibert
// Last update Tue May 10 04:51:10 2016 stephane galibert
//

#ifndef _BOMB_HPP_
# define _BOMB_HPP_

# include "IEntity.hpp"

namespace bbman
{
  class IBomb : public IEntity
  {
  public:
    virtual ~IBomb(void) {}
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
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
  };
}

#endif /* !_BOMB_HPP_ */
