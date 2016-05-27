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

luabridge::luaRef findPath(luabridge::lua_State *L);

#endif /* !_AIFUNCTIONS_HPP_ */
