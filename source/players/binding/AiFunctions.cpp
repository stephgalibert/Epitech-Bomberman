/*
** AiFunctions.cpp for bomberman in /home/care_j/work/bomberman/source
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "AiFunctions.hpp"

bbman::Board    *boardBinding(bbman::Board *board)
{
  static bbman::Board *boardSave = NULL;

  if (board != NULL)
    boardSave = board;
  return (boardSave);
}

luabridge::luaRef findPath(luabridge::lua_State *L)
{
  bbman::Board *board = boardBinding(NULL);
  luabridge::luaRef table = luabridge::newTable(L);
  table["test"] = "If i'm printed, that works !";
  return (table);
}
