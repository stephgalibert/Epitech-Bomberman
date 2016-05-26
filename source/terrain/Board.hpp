//
// Board.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 02:14:22 2016 stephane galibert
// Last update Wed May 25 15:13:31 2016 stephane galibert
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
# include "Direction.hpp"
# include "Map.hpp"
# include "Cell.hpp"
# include "IBlock.hpp"
# include "IndestructibleBlock.hpp"
# include "DestructibleBlock.hpp"

namespace bbman
{
  class Board
  {
  public:
    Board(void);
    ~Board(void);
    void init(Irrlicht &irr);
    //void initFromStream(Irrlicht &irr, std::ifstream &ifs);
    void init(Irrlicht &irr, Map<Cell> const& map);
    void setPosition(irr::core::vector3df const& pos);
    irr::core::vector3df const& getPosition(void) const;
    bool isColliding(irr::core::aabbox3df const& box) const;
    void explodeBlocks(bbman::IBomb *bomb);
    bool isNotProtected(irr::core::vector3d<irr::s32> const& bomb,
			irr::core::vector3d<irr::s32> const& block);
    bool isOutside(irr::core::vector3df const& pos);
    irr::core::vector3df const& getSize(void) const;
    irr::core::vector3df const& getScale(void) const;
    irr::core::vector3df const& getSpawnPosition(size_t num) const;
    bool isValidMove(irr::core::vector3df const& pos, t_direction dir) const;
    bool isInNode(irr::core::vector3df const& pos) const;
    Map<Cell> const& getMap(void) const;
  private:
    void initTerrain(Irrlicht &irr);
    void initMap(void);
    //void initMapFromStream(std::ifstream &ifs);
    void initNode(void);
    void initMesh(Irrlicht &irr);
    void updateNode(irr::core::vector3d<irr::s32> const& pos);
    void buildInbrkable(Irrlicht &irr, size_t x, size_t y);
    void buildBrkable(Irrlicht &irr, size_t x, size_t y);
    std::unordered_map<int, std::function<void(Irrlicht &, size_t, size_t)> > _ctor;
    irr::scene::IMeshSceneNode *_backgroundMesh;
    irr::video::SMaterial _texture;
    std::vector<IBlock *> _blocks;
    std::list<IBlock *> _dblocks;
    Map<bbman::Cell> _map;
    irr::core::vector3df _size;
    irr::core::vector3df _scale;
    irr::core::vector3df _spawn[4];
  };

  inline std::ostream &operator<<(std::ostream &flux, bbman::Board const& board)
  {
    flux << board.getMap();
    return (flux);
  }
}

#endif /* !_BOARD_HPP_ */
