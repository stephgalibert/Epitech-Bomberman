//
// IPlayer.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 17:32:16 2016 stephane galibert
// Last update Tue May 10 09:36:15 2016 stephane galibert
//

#ifndef _IPLAYER_HPP_
# define _IPLAYER_HPP_

# include "IEntity.hpp"
# include "IBomb.hpp"
# include "IEffect.hpp"
# include "Action.hpp"

namespace bbman
{
  class IPlayer : public IEntity
  {
  public:
    static const constexpr float INITIAL_SPEED = 20.0f;
  public:
    virtual ~IPlayer(void) {}
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void addBomb(IBomb *bomb) = 0;
    virtual IBomb *createBomb(Irrlicht &irr) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual t_action getAction(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual irr::s32 getScore(void) const = 0;
    virtual bool isRunning(void) const = 0;
    virtual bool input(InputListener &inputListener) = 0;
    virtual void goToPrevPosition(void) = 0;
    virtual size_t getSpeed(void) const = 0;
    virtual void setSpeed(size_t speed) = 0;
    virtual void addEffect(IEffect *effect) = 0;
    virtual size_t getPlayerNumber(void) const = 0;
  };
}

#endif /* !_IPLAYER_HPP_ */
