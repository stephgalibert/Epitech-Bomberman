//
// Board.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 02:14:22 2016 stephane galibert
// Last update Mon May 30 09:24:59 2016 stephane galibert
//

#ifndef _BOARD_HPP_
# define _BOARD_HPP_

# include <fstream>
# include <iostream>
# include <unordered_map>
# include <functional>
# include <irrlicht.h>
# include <stdexcept>
# include <vector>
# include <list>

# include "IBomb.hpp"
# include "APlayer.hpp"
# include "Direction.hpp"
# include "Map.hpp"
# include "Cell.hpp"
# include "IBlock.hpp"
# include "IndestructibleBlock.hpp"
# include "DestructibleBlock.hpp"
# include "PowerUPs.hpp"
# include "InputListener.hpp"
# include "PowerUPs.hpp"

namespace bbman
{
  class Loader;
  class Board
  {
  public:
    Board(void);
    ~Board(void);
    void init(Irrlicht &irr);
    void init(Irrlicht &irr, Loader const& loader);
    void input(InputListener &listener);
    void update(Irrlicht &irr, irr::f32 delta);
    void addPlayer(APlayer *player);
    bool addBomb(IBomb *bomb);
    void setPosition(irr::core::vector3df const& pos);
    irr::core::vector3df const& getPosition(void) const;
    bool isColliding(irr::core::aabbox3df const& box) const;
    /*void deleteBlock(IEntity *entity);
    void deleteEntity(IEntity *entity);
    void deleteBomb(IBomb *bomb);*/
    IEntity *getEntityByPosition(irr::core::vector3d<irr::s32> const& pos) const;
    void eraseEntityByPosition(irr::core::vector3d<irr::s32> const& pos);
    void explodeBlocks(IBomb *bomb);
    bool isOutside(irr::core::vector3df const& pos);
    irr::core::vector3df const& getSize(void) const;
    irr::core::vector3df const& getScale(void) const;
    irr::core::vector3df const& getSpawnPosition(size_t num) const;
    bool isValidMove(irr::core::vector3df const& pos, t_direction dir) const;
    bool isInNode(irr::core::vector3df const& pos) const;
    Map<Cell> const& getMap(void) const;
    Map<Cell> &getMap(void);
    std::vector<APlayer *> const& getPlayers(void) const;
    std::list<IBomb *> const& getBombs(void) const;
    bool hasWinners(void) const;
    IBlock *createInbrkable(Irrlicht &irr, size_t x, size_t y);
    void registerBlock(IBlock *block);
    void disableDirection(size_t x, size_t y);
    void updateNode(irr::core::vector3d<irr::s32> const& pos);
    APlayer *getPlayerByID(size_t id) const;
  private:
    void buildInbrkable(Irrlicht &irr, size_t x, size_t y);
    void buildBrkable(Irrlicht &irr, size_t x, size_t y);
    void initTerrain(Irrlicht &irr);
    void initMap(void);
    void initNode(void);
    void initMesh(Irrlicht &irr);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    void updatePlayers(bbman::Irrlicht &irr, irr::f32 delta);
    std::unordered_map<int, std::function<void(Irrlicht &, size_t, size_t)> > _ctor;
    irr::scene::IMeshSceneNode *_backgroundMesh;
    irr::video::SMaterial _texture;
    std::vector<IBlock *> _blocks;
    std::list<IBlock *> _dblocks;
    std::vector<APlayer *> _players;
    std::list<IBomb *> _bombs;
    std::list<IEntity *> _explosable;
    PowerUPs _powerUPs;
    Map<bbman::Cell> _map;
    irr::core::vector3df _size;
    irr::core::vector3df _scale;
    irr::core::vector3df _spawn[4];
  };

  inline std::ostream &operator<<(std::ostream &flux, bbman::Board const& board)
  {
    flux << "MAP_BEGIN" << std::endl;
    flux << board.getMap();
    flux << "MAP_END" << std::endl;
    flux << "PLAYERS_BEGIN" << std::endl;
    for (auto it : board.getPlayers()) {
      flux << *it;
    }
    flux << "PLAYERS_END" << std::endl;
    flux << "BOMBS_BEGIN" << std::endl;
    for (auto it : board.getBombs()) {
      flux << *it;
    }
    flux << "BOMBS_END" << std::endl;
    flux << "POWERUPS_BEGIN" << std::endl;
    // powerups
    flux << "POWERUPS_END" << std::endl;
    return (flux);
  }
}

#endif /* !_BOARD_HPP_ */
