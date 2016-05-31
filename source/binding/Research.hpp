/*
** Research.hpp for bomberman in /home/care_j/work/bomberman/source/binding
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#ifndef _RESEARCH_HPP_
# define _RESEARCH_HPP_

#include "Board.hpp"
#include "Binding.hpp"

namespace bbman
{
  class Research
  {
  public:
    Research(void);
    ~Research(void);
    void setL(lua_State * L);
    size_t distCalc(irr::core::vector3d<irr::s32>const& p1,
                    irr::core::vector3d<irr::s32>const& p2);
    luabridge::LuaRef vecToTable(irr::core::vector3d<irr::s32> const& vec);
    irr::core::vector3d<irr::s32> getAIPos(int numplayer);
    irr::core::vector3d<irr::s32> getNearPlayer(irr::core::vector3d<irr::s32> const& ia);
    irr::core::vector3d<irr::s32> getNearBox(irr::core::vector3d<irr::s32> const& ia);
    irr::core::vector3d<irr::s32> getNearDBox(irr::core::vector3d<irr::s32> const& ia);
    bbman::APlayer *getAI(int numplayer);
  private:
    lua_State* _L;
    bbman::Board * _board;
  };
}

#endif /* !_RESEARCH_HPP_ */
