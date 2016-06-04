//
// Board.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:05:48 2016 avelin_j
// Last update Sun Jun  5 00:05:50 2016 avelin_j
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
# include "Pillar.hpp"
# include "PowerUPs.hpp"
# include "Wall.hpp"
# include "InputListener.hpp"
# include "PowerUPs.hpp"
# include "Generator.hpp"

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
    std::list<IEntity *> const& getEntityByPosition(irr::core::vector3d<irr::s32> const& pos);
    void eraseEntityByPosition(irr::core::vector3d<irr::s32> const& pos);
    void explodeBlocks(IBomb *bomb);
    bool isNoPlayer(void) const;
    bool isOutside(irr::core::vector3df const& pos);
    irr::core::vector3df const& getSize(void) const;
    irr::core::vector3df const& getScale(void) const;
    irr::core::vector3df const& getSpawnPosition(size_t num) const;
    bool isValidMove(irr::core::vector3df const& pos, t_direction dir) const;
    bool isInNode(irr::core::vector3df const& pos) const;
    Map<Cell> const& getMap(void) const;
    Map<Cell> &getMap(void);
    std::vector<APlayer *> const& getPlayers(void) const;
    std::vector<IBlock *> const& getBlocks(void) const;
    std::list<IBlock *> const& getDBlocks(void) const;
    std::list<IBomb *> const& getBombs(void) const;
    PowerUPs const& getPowerUPs(void) const;
    PowerUPs &getPowerUPs(void);
    Irrlicht *getIrrlicht(void);
    bool hasWinners(void) const;
    APlayer *getWinner(void) const;
    IBlock *createInbrkable(Irrlicht &irr, size_t x, size_t y);
    void registerBlock(IBlock *block);
    void disableDirection(size_t x, size_t y);
    void updateNode(irr::core::vector3d<irr::s32> const& pos);
    APlayer *getPlayerByID(size_t id) const;
    bool isInExplosion(irr::core::vector3d<irr::s32> const& pos);
    irr::core::vector3df const& testGetScale(void) const;
    irr::core::vector3df const& testGetSize(void) const;
  private:
    bool isNotProtected(IBomb *bombs, irr::core::vector3d<irr::s32> const& bomb,
			irr::core::vector3d<irr::s32> const& block);
    void buildInbrkable(Irrlicht &irr, size_t x, size_t y);
    void buildBrkable(Irrlicht &irr, size_t x, size_t y);
    void buildPillar(Irrlicht &irr, size_t x, size_t y, std::string const& color);
    void buildWall(Irrlicht &irr, size_t x, size_t y, std::string const& color);
    void buildParticle(Irrlicht &irr, size_t x, size_t y, std::string const& color);
    void initTerrain(Irrlicht &irr);
    void initMap(void);
    void initNode(void);
    void initMesh(Irrlicht &irr);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    void updatePlayers(bbman::Irrlicht &irr, irr::f32 delta);
    std::unordered_map<int, std::function<void(Irrlicht &, size_t, size_t)> > _ctor;
    irr::scene::IMeshSceneNode *_backgroundMesh;
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
    Irrlicht *_irr;
    irr::scene::ILightSceneNode* _light;
    tools::Generator _generator;
    std::list<IEntity *> _entities;
    std::vector<irr::scene::IParticleSystemSceneNode *> _pss;
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
    //flux << board.getPowerUPs();
    flux << "POWERUPS_END" << std::endl;
    return (flux);
  }
}

#endif /* !_BOARD_HPP_ */
