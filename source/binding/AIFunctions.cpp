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
   II_BOMB = 5
 */
bbman::Board* boardBinding(bbman::Board *board)
{
  static bbman::Board *boardSave = NULL;

  if (board != NULL) {
    boardSave = board;
  }
  return boardSave;
}

int iAmSafe(int numplayer, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;

  irr::core::vector3d<irr::s32> ai = r->getAIPos(numplayer);
  if (board->isInExplosion(ai)) {
    return (1);
  }
  return (0);
}

int directionIsSafe(int numplayer, int direction, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;
  irr::core::vector3d<irr::s32> ai = r->getAIPos(numplayer);

  if (direction == 1) {
    ai.X += 1;
  }
  else if (direction == 2) {
    ai.X -= 1;
  }
  else if (direction == 4) {
    ai.Z += 1;
  }
  else if (direction == 8) {
    ai.Z -= 1;
  }
  if (board->isInExplosion(ai)) {
    return (1);
  }
  return (0);  
}

luabridge::LuaRef getPos(int numplayer, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;

  if (r == NULL) {
    r = new bbman::Research;
  }
  r->setL(L);
  r->setBoard(board);

  luabridge::LuaRef table = luabridge::newTable(L);

  irr::core::vector3d<irr::s32> ai = r->getAIPos(numplayer);
  table = r->vecToTable(ai);
  return table;
}

int getMood(int numplayer, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;

  if (r == NULL) {
    r = new bbman::Research;
  }
  r->setL(L);
  r->setBoard(board);
  luabridge::LuaRef table = luabridge::newTable(L);
  bbman::APlayer   *ai    = r->getAI(numplayer);

  if (!ai) {
    return -1;
  }
  return ai->getMood();
}

void setMood(int numplayer, int mood, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;

  if (r == NULL) {
    r = new bbman::Research;
  }
  r->setL(L);
  r->setBoard(board);
  luabridge::LuaRef table = luabridge::newTable(L);
  bbman::APlayer   *ai    = r->getAI(numplayer);

  if (ai) {
    ai->setMood(mood);
  }
}

luabridge::LuaRef findPath(int numplayer, int type, lua_State *L)
{
  bbman::Board *board       = boardBinding(NULL);
  static bbman::Research *r = NULL;
  luabridge::LuaRef table   = luabridge::newTable(L);

  irr::core::vector3d<irr::s32> near;
  irr::core::vector3d<irr::s32> ia;
  bbman::TrueAStar trueA;
  bbman::NeighborAStar neighA;

 
  int distmin;
  int ret;

  trueA.addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
  trueA.addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
  neighA.addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
  neighA.addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);

  if (r == NULL) {
  r = new bbman::Research;
  }
  r->setL(L);
  r->setBoard(board);
  bbman::APlayer *aiPlayer = r->getAI(numplayer);
  if (aiPlayer) {
    ia = r->getAIPos(numplayer);
    if (board->isInExplosion(ia)) {
      table["success"] = 2;
      table["safedir"] = static_cast<int>(r->findNearestSafeZone(ia));
    } else {
      table["success"] = 1;
      if (type == BOX) {
        near = r->getNearDBox(ia);
	neighA.compute(board->getMap(), ia, near);
        table["size"]   = neighA.getSize();
        table["dir"]    = static_cast<int>(tools::StaticTools::getDirByCoord(ia, neighA.getNextResult()));
        table["target"] = r->vecToTable(near);
      } else if (type == UNBREAKB) {
        near = r->getNearBox(ia);
        neighA.compute(board->getMap(), ia, near);
        table["size"]   = neighA.getSize();
        table["dir"]    = static_cast<int>(tools::StaticTools::getDirByCoord(ia, neighA.getNextResult()));
        table["target"] = r->vecToTable(near);
      } else if (type == PLAYER) {
        near = r->getNearPlayer(ia);
        trueA.compute(board->getMap(), ia, near);
        table["size"]   = trueA.getSize();
        table["dir"]    = static_cast<int>(tools::StaticTools::getDirByCoord(ia, trueA.getNextResult()));
        table["target"] = r->vecToTable(near);
      } else {
        table["success"] = 0;
      }
    }
  }
  return table;
}
