/*
** Research.hpp for bomberman in /home/care_j/work/bomberman/source/binding
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#ifndef _RESEARCH_HPP_
#define _RESEARCH_HPP_

#include "Board.hpp"
#include "Binding.hpp"
#include "NeighborAStar.hpp"
#include "TrueAStar.hpp"

namespace bbman {
  class Research
  {
  public:

    Research(void);
    ~Research(void);
    void setL(lua_State *L);
    void setBoard(bbman::Board * board);
    size_t distCalc(irr::core::vector3d<irr::s32>const& p1,
                  irr::core::vector3d<irr::s32>const& p2);
    luabridge::LuaRef vecToTable(irr::core::vector3d<irr::s32>const& vec);
    irr::core::vector3d<irr::s32>const& getAIPos(int numplayer);
    irr::core::vector3d<irr::s32>const& getNearPlayer(irr::core::vector3d<irr::s32>const& ia);
    irr::core::vector3d<irr::s32>const& getNearBox(irr::core::vector3d<irr::s32>const& ia);
    irr::core::vector3d<irr::s32>const& getNearDBox(irr::core::vector3d<irr::s32>const& ia);
    bbman::Direction findNearestSafeZone(irr::core::vector3d<irr::s32>const& pos);
    bbman::APlayer* getAI(int numplayer);
    bbman::TrueAStar getTrueA() const;
    bbman::NeighborAStar getNeighA() const;
  private:

    lua_State *_L;
    bbman::Board *_board;
    irr::core::vector3d<irr::s32> _near;
    bbman::TrueAStar _trueA;
    bbman::NeighborAStar _neighA;
  };
}

#endif /* !_RESEARCH_HPP_ */
