/*
** AiFunctions.cpp for bomberman in /home/care_j/work/bomberman/source
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "AIFunctions.hpp"

bbman::Board    *boardBinding(bbman::Board *board)
{
  static bbman::Board *boardSave = NULL;

  if (board != NULL)
    boardSave = board;
  return (boardSave);
}

luabridge::LuaRef findPath(lua_State *L)
{
  bbman::Board *board = boardBinding(NULL);
  luabridge::LuaRef table = luabridge::newTable(L);
  table["test"] = "If i'm printed, that works !";
  return (table);
}
