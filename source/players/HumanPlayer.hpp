//
// HumanPlayer.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 17:39:17 2016 stephane galibert
// Last update Fri May 20 14:55:57 2016 stephane galibert
//

#ifndef _HUMANPLAYER_HPP_
# define _HUMANPLAYER_HPP_

# include <irrlicht.h>
# include <functional>
# include <unordered_map>
# include <algorithm>

# include "BombManager.hpp"
# include "IPlayer.hpp"
# include "ExplodingBomb.hpp"
# include "InputListener.hpp"
# include "Direction.hpp"

namespace bbman
{
  class HumanPlayer : public IPlayer
  {
  public:
    static HumanPlayer *create(void);
    virtual ~HumanPlayer(void);
    virtual void init(Irrlicht &irr);
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual void checkDirection(Board *board);
    virtual void addBomb(IBomb *bomb);
    virtual void dropBomb(Irrlicht &irr, Board *board,
			  std::list<IBomb *> &bombs);
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual t_action getAction(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual irr::s32 getScore(void) const;
    virtual bool isRunning(void) const;
    virtual bool input(InputListener &inputListener);
    //virtual void goToPrevPosition(void);
    virtual size_t getSpeed(void) const;
    virtual void setSpeed(size_t speed);
    virtual void addEffect(IEffect *effect);
    virtual size_t getPlayerNumber(void) const;
  private:
    static size_t NumberOfPlayer;
  private:
    HumanPlayer(void);
    IBomb *createBomb(Irrlicht &irr);
    void updateEffets(irr::f32 delta);
    void move(irr::f32 delta);
    void moveEast(irr::f32 delta);
    void moveWest(irr::f32 delta);
    void moveNorth(irr::f32 delta);
    void moveSouth(irr::f32 delta);
    std::unordered_map<int, std::function<void(irr::f32 delta)> > _move;
    void inputPlayer1(InputListener &inputListener);
    void inputPlayer2(InputListener &inputListener);
    std::unordered_map<size_t, std::function<void(InputListener &)> > _inputs;
    void initPlayer1(Irrlicht &irr);
    void initPlayer2(Irrlicht &irr);
    std::unordered_map<size_t, std::function<void(Irrlicht &)> > _inits;
    irr::scene::IAnimatedMeshSceneNode *_mesh;
    std::list<IEffect *> _effects;
    BombManager _bombManager;
    t_direction _direction;
    t_direction _prevDirection;
    t_action _action;
    irr::s32 _score;
    size_t _speed;
    bool _isRunning;
    bool _alive;
    size_t _playerNum;
  };
}

#endif /* !_HUMANPLAYER_HPP_ */
