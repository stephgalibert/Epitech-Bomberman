/*
** Research.cpp for bomberman in /home/care_j/work/bomberman/source/binding
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "Research.hpp"

bbman::Research::Research(void)
{
  this->_board = boardBinding(NULL);
}

bbman::Research::~Research(void)
{

}

void bbman::Research::setL(lua_State *L)
{
  this->_L = L;
}


size_t bbman::Research::distCalc(irr::core::vector3d<irr::s32>const& p1,
                                 irr::core::vector3d<irr::s32>const& p2)
{
  int res1 = p1.X - p2.X;
  int res2 = p1.Z - p2.Z;

  if (res1 < 0) {
    res1 *= -1;
  }

  if (res2 < 0) {
    res2 *= -1;
  }
  return res1 + res2;
}

luabridge::LuaRef bbman::Research::vecToTable(irr::core::vector3d<irr::s32> const& vec)
{
  luabridge::LuaRef pos = luabridge::newTable(this->_L);

  pos["x"] = vec.X;
  pos["y"] = vec.Z;
  return pos;
}

irr::core::vector3d<irr::s32> bbman::Research::getAIPos(int numplayer)
{
  std::vector<bbman::APlayer *>const& Players = this->_board->getPlayers();
  irr::core::vector3d<irr::s32> ia;

  for (auto& it : Players) {
    if (it->getID() == numplayer) {
      ia = it->getPosInMap(this->_board->getScale());
    }
  }
  return ia;
}

irr::core::vector3d<irr::s32> bbman::Research::getNearPlayer(irr::core::vector3d<irr::s32> const& ia)
{
  std::vector<bbman::APlayer *> const& Players = this->_board->getPlayers();
  size_t distmin = distCalc((*Players.begin())->getPosInMap(this->_board->getScale()), ia);

  irr::core::vector3d<irr::s32> near;
  size_t ret;

  for (auto& it : Players) {
    if (distmin > (ret = distCalc(it->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      near    = it->getPosInMap(this->_board->getScale());
    }
  }
  return near;
}

irr::core::vector3d<irr::s32>bbman::Research::getNearBox(irr::core::vector3d<irr::s32> const& ia)
{
  std::vector<bbman::IBlock *>  Blocks = this->_board->getBlocks();
  size_t distmin = distCalc((*Blocks.begin())->getPosInMap(this->_board->getScale()), ia);

  irr::core::vector3d<irr::s32> near;
  size_t ret;

  for (std::vector<bbman::IBlock *>::iterator it = Blocks.begin(); it != Blocks.end(); ++it) {
    if (distmin > (ret = distCalc((*it)->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      near    = (*it)->getPosInMap(this->_board->getScale());
    }
  }
  return near;
}

irr::core::vector3d<irr::s32>bbman::Research::getNearDBox(irr::core::vector3d<irr::s32> const& ia)
{
  std::list<bbman::IBlock *>  Blocks = this->_board->getDBlocks();
  size_t distmin = distCalc((*Blocks.begin())->getPosInMap(this->_board->getScale()), ia);

  irr::core::vector3d<irr::s32> near;
  size_t ret;

  for (std::list<bbman::IBlock *>::iterator it = Blocks.begin(); it != Blocks.end(); ++it) {
    if (distmin > (ret = distCalc((*it)->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      near    = (*it)->getPosInMap(this->_board->getScale());
    }
  }
  return near;
}

bbman::APlayer * bbman::Research::getAI(int numplayer)
{
  std::vector<bbman::APlayer *> const& Players = this->_board->getPlayers();
  bbman::APlayer *ia;

  for (auto& it : Players) {
    if (it->getID() == numplayer) {
      ia = it;
    }
  }
  if (ia && !ia->isAlive()) {
    ia = NULL;
    std::cerr << "ai not alive" << std::endl;
  }
  return ia;
}
