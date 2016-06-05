/*
** binding.hpp for luatest in /home/care_j/work/luatest
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#ifndef _BINDING_HPP_
# define _BINDING_HPP_

#include <string>
#include <iostream>
#include <stdexcept>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

#include "LuaBridge.h"
#include "AIFunctions.hpp"

struct Data {
  int pos;
};

namespace bbman
{
  class Binding
  {
  public:
    Binding(void);
    ~Binding(void);
    void sendPosToLua(irr::core::vector3d<irr::s32> pos);
    void init(const std::string &scriptName);
    int runAI(size_t id);
  private:
    lua_State* luaState;
  };
}

#endif /* !_BINDING_HPP_ */
