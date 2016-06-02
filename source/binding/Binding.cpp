/*
** binding.cpp for luatest in /home/care_j/work/luatest
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "Binding.hpp"

/* Add function C++ to LUA */
/* getGlobalNamespace(this->luaState).addFunction("nom de fonction", fonction);*/
/* get function LUA to C++ */
/* LuaRef function = getGlobal(this->luaState, "nom de fonction") */


bbman::Binding::Binding(void)
{

}


bbman::Binding::~Binding(void)
{

}

int  bbman::Binding::runAI(size_t id)
{
  this->init("../source/binding/script.lua"); // A REMOVE AVANT FINAL PUSH
  luabridge::LuaRef aiFct = luabridge::getGlobal(this->luaState, "ai");
  luabridge::LuaRef ret = aiFct(id);
  int move = ret["move"].cast<int>();
  if (ret["bomb"] == 1)
    move += 10;
  return (move);
}

void bbman::Binding::init(const std::string &scriptName)
{
  try {
    this->luaState = luaL_newstate();
    luaL_openlibs(this->luaState);
    luaL_dofile(this->luaState, scriptName.data());
    lua_pcall(this->luaState, 0, 0, 0);
    luabridge::getGlobalNamespace(this->luaState).addFunction("findPath", findPath);
    luabridge::getGlobalNamespace(this->luaState).addFunction("getPos", getPos);
    luabridge::getGlobalNamespace(this->luaState).addFunction("setMood", setMood);
    luabridge::getGlobalNamespace(this->luaState).addFunction("getMood", getMood);
  }
  catch (...){
    std::cerr << "Erreur : Binding problem." << std::endl;
  }
}
