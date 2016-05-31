/*
** AiFunctions.cpp for bomberman in /home/care_j/work/bomberman/source
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "AIFunctions.hpp"

#include "Board.hpp"
#include "TrueAStar.hpp"
#include "NeighborAStar.hpp"
#include "IBlock.hpp"
#include "AIPlayer.hpp"
#include "Binding.hpp"
/*
   II_NONE = 0,
   II_BLOCK_INBRKABLE = 1,
   II_BLOCK_BRKABLE = 2,
   II_WALL = 3,
   II_CORNER = 4
 */

bbman::Board* boardBinding(bbman::Board *board)
{
  static bbman::Board *boardSave = NULL;

  if (board != NULL) {
    boardSave = board;
  }
  return boardSave;
}

luabridge::LuaRef getPos(int numplayer, lua_State *L)
{
  bbman::Board *board     = boardBinding(NULL);
  bbman::Research r;
  r.setL(L);

  luabridge::LuaRef table = luabridge::newTable(L);
  irr::core::vector3d<irr::s32> ai = r.getAIPos(numplayer);
  table = r.vecToTable(ai);
  return table;
}

int getMood(int numplayer, lua_State *L)
{
  bbman::Board *board     = boardBinding(NULL);
  bbman::Research r;
  r.setL(L);
  luabridge::LuaRef table = luabridge::newTable(L);
  bbman::APlayer *ai = r.getAI(numplayer);
  return ai->getMood();
}

void setMood(int numplayer, int mood, lua_State *L)
{
  bbman::Board *board     = boardBinding(NULL);
  bbman::Research r;
  r.setL(L);
  luabridge::LuaRef table = luabridge::newTable(L);
  bbman::APlayer *ai = r.getAI(numplayer);
  ai->setMood(mood);
}

luabridge::LuaRef findPath(int numplayer, int type, lua_State *L)
{
  bbman::Board *board     = boardBinding(NULL);
  bbman::Research r;
  luabridge::LuaRef table = luabridge::newTable(L);

  static bbman::TrueAStar *TrueA      = NULL;
  static bbman::NeighborAStar *NeighA = NULL;

  irr::core::vector3d<irr::s32> near;
  irr::core::vector3d<irr::s32> ia;

  int distmin;
  int ret;

  r.setL(L);
  if (!TrueA) {
    TrueA = new bbman::TrueAStar;
    TrueA->addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
    TrueA->addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
    NeighA = new bbman::NeighborAStar;
    NeighA->addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
    NeighA->addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
  }

  table["success"] = 1;
  ia = r.getAIPos(numplayer);
  if (type == BOX) {
    near = r.getNearDBox(ia);
    NeighA->compute(board->getMap(), ia, near);
    table["size"]   = NeighA->getSize();
    table["dir"]    = r.vecToTable(NeighA->getNextResult());
    table["target"] = r.vecToTable(near);
  } else if (type == UNBREAKB) {
    near = r.getNearBox(ia);
    NeighA->compute(board->getMap(), ia, near);
    table["size"]   = NeighA->getSize();
    table["dir"]    = r.vecToTable(NeighA->getNextResult());
    table["target"] = r.vecToTable(near);
  } else if (type == PLAYER) {
    near = r.getNearPlayer(ia);
    TrueA->compute(board->getMap(), ia, near);
    table["size"]   = TrueA->getSize();
    table["dir"]    = r.vecToTable(TrueA->getNextResult());
    table["target"] = r.vecToTable(near);
  } else {
    table["success"] = 0;
  }
  return table;
}
