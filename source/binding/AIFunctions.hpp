/*
** AiFunctuion.hpp for bomberman in /home/care_j/work/bomberman/source
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#ifndef _AIFUNCTIONS_HPP_
# define _AIFUNCTIONS_HPP_

#include "Board.hpp"
#include "Binding.hpp"
#include "Research.hpp"

# define BOX 1
# define UNBREAKB 2
# define PLAYER 3

/*
**
** Callable in C++
**
*/

bbman::Board      *boardBinding(bbman::Board *board);

/*
**
** Callable in Lua
**
*/

luabridge::LuaRef findPath(int player ,int flag, lua_State *L);
luabridge::LuaRef getPos(int numplayer, lua_State *L);
int getMood(int numplayer, lua_State *L);
void setMood(int numplayer, int mood, lua_State *L);

#endif /* !_AIFUNCTIONS_HPP_ */
