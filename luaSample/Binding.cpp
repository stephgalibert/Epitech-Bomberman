/*
** binding.cpp for luatest in /home/care_j/work/luatest
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "Binding.hpp"

Data *accessData(Data *newAIdata)
{
  static Data *AIdata = 0;

  if (newAIdata != NULL)
    AIdata = newAIdata;
  return AIdata;
}

int getpos()
{
  return accessData(NULL)->pos;
}

bbman::Binding::Binding(void)
{

}


bbman::Binding::~Binding(void)
{

}

int  bbman::Binding::runAI(void)
{
  luabridge::LuaRef aiFct = luabridge::getGlobal(this->luaState, "ai");
  luabridge::LuaRef move = aiFct();
  luabridge::LuaRef a = move["a"];
  std::cout << "move.a -> = " << a.cast<int>() << std::endl;
  return 0;
}

void bbman::Binding::init(const std::string &scriptName)
{
  try {
    this->luaState = luaL_newstate();
    luaL_openlibs(this->luaState);
    luaL_dofile(this->luaState, scriptName.data());
    lua_pcall(this->luaState, 0, 0, 0);
    /* Add function C++ to LUA */
    /* getGlobalNamespace(this->luaState).addFunction("nom de fonction", fonction);*/
    luabridge::getGlobalNamespace(this->luaState).addFunction("getpos", getpos);
    /* get function LUA to C++ */
    /* LuaRef function = getGlobal(this->luaState, "nom de fonction") */
  }
  catch (...){
    std::cerr << "Erreur : Binding problem." << std::endl;
  }
}
