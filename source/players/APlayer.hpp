//
// APlayer.hpp for indie in /home/galibe_s/rendu/bomberman/source/players
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May 24 22:28:29 2016 stephane galibert
// Last update Fri May 27 08:14:38 2016 stephane galibert
//

#ifndef _APLAYER_HPP_
# define _APLAYER_HPP_

# include <iostream>
# include <list>

//# include "Board.hpp"
# include "IEntity.hpp"
# include "IBomb.hpp"
# include "IEffect.hpp"
# include "Action.hpp"
# include "BombManager.hpp"

namespace bbman
{
  class Board;

  class APlayer : public IEntity
  {
  public:
    static const constexpr float INITIAL_SPEED = 40.0f;
  public:
    APlayer(void);
    virtual ~APlayer(void);
    virtual size_t getAPlayerID(void) const = 0;
    virtual void init(Irrlicht &irr) = 0;
    virtual void update(Irrlicht &irr, irr::f32 delta) = 0;
    virtual void play(Irrlicht &irr, Board *board, std::list<IBomb *> &bombs) = 0;
    virtual void addBomb(IBomb *bomb) = 0;
    virtual void setPosition(irr::core::vector3df const& pos) = 0;
    virtual irr::core::vector3df const& getPosition(void) const = 0;
    virtual irr::core::aabbox3df const getBoundingBox(void) const = 0;
    virtual bool isColliding(irr::core::aabbox3df const& box) const = 0;
    virtual void explode(void) = 0;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale) = 0;
    virtual bool input(InputListener &inputListener) = 0;
    virtual size_t getSpeed(void) const = 0;
    virtual void setSpeed(size_t speed) = 0;
    virtual void addEffect(IEffect *effect) = 0;
    virtual size_t getPlayerNumber(void) const = 0;
    virtual bool isRunning(void) const = 0;
    virtual BombManager const& getBombManager(void) const = 0;
    virtual std::list<IEffect *> const& getEffects(void) const = 0;
    virtual void setRotation(irr::s32 rotation) = 0;
    virtual irr::s32 getRotation(void) const = 0;
    bool hasExplosed(void) const;
    void setAlive(bool value);
    size_t getID(void) const;
    irr::s32 getScore(void) const;
    void setScore(irr::s32 score);
  private:
    static size_t NumberOfPlayer;
    size_t _id;
  protected:
    irr::s32 _score;
    bool _alive;
  };

  inline std::ostream &operator<<(std::ostream &flux, APlayer const& player)
  {
    std::list<bbman::IEffect *> const& effects = player.getEffects();
    std::string id = std::to_string(player.getID());
    std::string position;
    std::string rotation;
    std::string score = std::to_string(player.getScore());
    std::string alive = (player.hasExplosed()) ? "false" : "true";

    if (!player.hasExplosed()) {
      irr::core::vector3df const& pos = player.getPosition();
      position = std::to_string((int)pos.X) + " "
	+ std::to_string((int)pos.Y) + " "
	+ std::to_string((int)pos.Z);
      rotation = std::to_string(player.getRotation());
    }
    flux << "PID:" << player.getAPlayerID() << ";id:" << id << ";pos:"
	 << position << ";score:" << score << ";alive:" << alive << ";"
	 << "rot:" << rotation << ";";
    for (auto it : effects) {
      flux << "effect:" << it->getEffectID()
	   << " " << (int)it->getDelta() << ";";
    }
    flux << player.getBombManager() << std::endl;
    return (flux);
  }
}

#endif /* !_APLAYER_HPP_ */
