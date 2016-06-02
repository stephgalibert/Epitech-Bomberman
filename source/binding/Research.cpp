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
  this->_trueA.addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
  this->_trueA.addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
  this->_neighA.addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
  this->_neighA.addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
}

bbman::Research::~Research(void)
{

}

void bbman::Research::setL(lua_State *L)
{
  this->_L = L;
}

void bbman::Research::setBoard(bbman::Board * board)
{
  this->_board = board;
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

irr::core::vector3d<irr::s32> const& bbman::Research::getAIPos(int numplayer)
{
  IEntity *player = this->_board->getPlayerByID(numplayer);
  if (player) {
    return (player->getPosInMap(this->_board->getScale()));
  }
  throw (std::runtime_error("player " + std::to_string(numplayer) + " not found"));
}

irr::core::vector3d<irr::s32> const&
bbman::Research::getNearPlayer(irr::core::vector3d<irr::s32> const& ia)
{
  std::vector<bbman::APlayer *> const& Players = this->_board->getPlayers();
  size_t distmin = 1000; // TROUVER UNE SOLUTION

  size_t ret;

  for (auto& it : Players) {
    irr::core::vector3d<irr::s32> pos = it->getPosInMap(this->_board->getScale());
    if (distmin > (ret = distCalc(pos, ia)) && ((pos.X != ia.X) != (pos.Z != ia.Z))) {
      distmin = ret;
      this->_near    = it->getPosInMap(this->_board->getScale());
    }
  }
  return this->_near;
}

irr::core::vector3d<irr::s32> const&
bbman::Research::getNearBox(irr::core::vector3d<irr::s32> const& ia)
{
  std::vector<bbman::IBlock *>  Blocks = this->_board->getBlocks();
  size_t distmin = distCalc((*Blocks.begin())->getPosInMap(this->_board->getScale()), ia);

  size_t ret;

  for (auto& it : Blocks) {
    if (distmin > (ret = distCalc(it->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      this->_near    = it->getPosInMap(this->_board->getScale());
    }
  }
  return this->_near;
}

irr::core::vector3d<irr::s32> const&
bbman::Research::getNearDBox(irr::core::vector3d<irr::s32> const& ia)
{
  std::list<bbman::IBlock *>  Blocks = this->_board->getDBlocks();
  size_t distmin = distCalc((*Blocks.begin())->getPosInMap(this->_board->getScale()), ia);

  size_t ret;

  for (auto& it : Blocks) {
    if (distmin > (ret = distCalc(it->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      this->_near    = it->getPosInMap(this->_board->getScale());
    }
  }
  return this->_near;
}

/*irr::core::vector3d<irr::s32> const&
bbman::Research::getNearPowerUp(irr::core::vector3d<irr::s32> const& ia)
{
   std::list<bbman::IBlock *>  Blocks = this->_board->getDBlocks();
  size_t distmin = distCalc((*Blocks.begin())->getPosInMap(this->_board->getScale()), ia);

  size_t ret;

  for (auto& it : Blocks) {
    if (distmin > (ret = distCalc(it->getPosInMap(this->_board->getScale()), ia))) {
      distmin = ret;
      this->_near    = it->getPosInMap(this->_board->getScale());
    }
  }
  return this->_near;
  }*/

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

bbman::Direction bbman::Research::findNearestSafeZone(irr::core::vector3d<irr::s32>const& pos)
{
  Map<bbman::Cell> const& map = this->_board->getMap();
  bbman::TrueAStar trueA;

  trueA.addBlockType(bbman::ItemID::II_BLOCK_INBRKABLE);
  trueA.addBlockType(bbman::ItemID::II_BLOCK_BRKABLE);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (pos.X + j < map.w && pos.Z + i < map.h &&
          map.at(pos.X + j, pos.Z + i).id == ItemID::II_NONE) {
            if (this->_board->isInExplosion(
                irr::core::vector3d<irr::s32>(pos.X + j, 0 , pos.Z + i)) == false) {
                trueA.compute(map, pos, irr::core::vector3d<irr::s32>(pos.X + j, 0 , pos.Z + i));
                if (trueA.getSize() != 0) {
                    return tools::StaticTools::getDirByCoord(pos, trueA.getNextResult());
                }
            }
      }

      if (pos.X - j > 0 && pos.Z - i > 0 && map.at(pos.X - j, pos.Z - i).id == ItemID::II_NONE) {

        if (this->_board->isInExplosion(
            irr::core::vector3d<irr::s32>(pos.X - j, 0 , pos.Z - i)) == false) {
            trueA.compute(map, pos, irr::core::vector3d<irr::s32>(pos.X - j, 0 , pos.Z - i));
            if (trueA.getSize() != 0) {
                return tools::StaticTools::getDirByCoord(pos, trueA.getNextResult());
            }
        }
      }
    }
   }

   return bbman::Direction::DIR_NONE;
}

bbman::TrueAStar bbman::Research::getTrueA() const
{
  return this->_trueA;
}

bbman::NeighborAStar bbman::Research::getNeighA() const
{
  return this->_neighA;
}
