/*
** AIPlayer.hpp for bomberman in /home/care_j/work/bomberman/source/players
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#ifndef _AIPLAYER_HPP_
# define _AIPLAYER_HPP_

# include <irrlicht.h>
# include <iostream>
# include <functional>
# include <unordered_map>
# include <algorithm>

# include "APlayer.hpp"
# include "ExplodingBomb.hpp"
# include "InputListener.hpp"
# include "Direction.hpp"
# include "Binding.hpp"

namespace bbman
{
  class AIPlayer : public APlayer
  {
  public:
    AIPlayer(void);
    virtual ~AIPlayer(void);
    virtual size_t getAPlayerID(void) const;
    virtual void init(Irrlicht &irr, std::string const& color = "");
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void play(Irrlicht &irr, Board *board);
    virtual void addBomb(IBomb *bomb);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual void explode(Board *board);
    virtual void playExplosion(void);
    virtual bool input(InputListener &inputListener);
    virtual size_t getSpeed(void) const;
    virtual void setSpeed(size_t speed);
    virtual void addEffect(IEffect *effect);
    virtual size_t getPlayerNumber(void) const;
    virtual bool isRunning(void) const;
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale);
    virtual BombManager const& getBombManager(void) const;
    virtual std::list<IEffect *> const& getEffects(void) const;
    virtual void setRotation(irr::s32 rotation);
    virtual irr::s32 getRotation(void) const;
    virtual void setAlive(bool value);
    virtual bool isAlive(void) const;
    virtual bool hasExplosed(void) const;
    virtual std::string const& getColor(void) const;
    virtual void setColor(std::string const& color);
  private:
    static size_t NumberOfPlayer;
  private:
    void dropBomb(Irrlicht &irr, Board *board);
    IBomb *createBomb(Irrlicht &irr);
    void updateEffets(irr::f32 delta);
    void move(irr::f32 delta);
    void moveEast(irr::f32 delta);
    void moveWest(irr::f32 delta);
    void moveNorth(irr::f32 delta);
    void moveSouth(irr::f32 delta);
    std::unordered_map<int, std::function<void(irr::f32 delta)> > _move;
    std::unordered_map<size_t, std::function<void(InputListener &)> > _inputs;
    std::unordered_map<size_t, std::function<void(Irrlicht &)> > _inits;
    irr::scene::IAnimatedMeshSceneNode *_mesh;
    std::list<IEffect *> _effects;
    irr::core::vector3d<irr::s32> _posInMap;
    BombManager _bombManager;
    t_direction _direction;
    t_direction _prevDirection;
    t_action _action;
    size_t _speed;
    bool _isRunning;
    size_t _playerNum;
    bool _alive;
    bbman::Binding _binding;
    std::string _color;
  };
}

#endif /* !_AIPLAYER_HPP_ */
