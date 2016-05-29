//
// Board.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:08:25 2016 stephane galibert
// Last update Sun May 29 10:42:55 2016 stephane galibert
//

#include "Board.hpp"

bbman::Board::Board(void)
{
  this->_backgroundMesh = NULL;
  // la taille de la map doit être impaire
  this->_size = irr::core::vector3df(19, 0, 13);
  this->_scale = irr::core::vector3df(10, 10, 10);
  this->_ctor[(int)ItemID::II_BLOCK_INBRKABLE] =
    std::bind(&bbman::Board::buildInbrkable, this, std::placeholders::_1,
              std::placeholders::_2, std::placeholders::_3);
  this->_ctor[(int)ItemID::II_BLOCK_BRKABLE] =
    std::bind(&bbman::Board::buildBrkable, this, std::placeholders::_1,
              std::placeholders::_2, std::placeholders::_3);
}

bbman::Board::~Board(void)
{
  for (auto& it : this->_blocks) {
    delete (it);
  }
  for (auto& it : this->_dblocks) {
    delete (it);
  }
  for (auto& it : this->_bombs) {
    delete (it);
  }
  for (auto& it : this->_players) {
    delete (it);
  }
  if (this->_backgroundMesh) {
    this->_backgroundMesh->remove();
  }
}

void bbman::Board::init(bbman::Irrlicht& irr)
{
  this->_map.load(this->_size.X, this->_size.Z);
  initMap();
  initNode();
  initTerrain(irr);
  initMesh(irr);
  this->_spawn[0] = irr::core::vector3df(10.f, 0.f, 10.f);
  this->_spawn[1] = irr::core::vector3df(170.f, 0.f, 10.f);
  this->_spawn[2] = irr::core::vector3df(170.f, 0.f, 110.f);
  this->_spawn[3] = irr::core::vector3df(10.f, 0.f, 110.f);
}

void bbman::Board::init(bbman::Irrlicht& irr, bbman::Loader const& loader)
{
  this->_map = loader.getMap();

  for (auto& it : loader.getPlayers()) {
    addPlayer(it);
  }
  this->_bombs = loader.getBombs();
  initNode();
  initTerrain(irr);
  initMesh(irr);
  this->_spawn[0] = irr::core::vector3df(10.f, 0.f, 10.f);
  this->_spawn[1] = irr::core::vector3df(170.f, 0.f, 10.f);
  this->_spawn[2] = irr::core::vector3df(170.f, 0.f, 110.f);
  this->_spawn[3] = irr::core::vector3df(10.f, 0.f, 110.f);
}

void bbman::Board::input(bbman::InputListener& listener)
{
  for (auto& it : this->_players) {
    it->input(listener);
  }
}

void bbman::Board::update(Irrlicht& irr, irr::f32 delta)
{
  updatePlayers(irr, delta);
  updateBombs(irr, delta);
  this->_powerUPs.update(irr, delta, this);
}

bool bbman::Board::hasWinners(void) const
{
  int nbAlive = 0;
  for (auto it : this->_players) {
    if (!it->hasExplosed()) {
      ++nbAlive;
    }
  }
  return (nbAlive < 2);
}

bbman::APlayer *bbman::Board::getPlayerByID(size_t id) const
{
  for (auto it : this->_players) {
    if (it->getID() == id) {
      return (it);
    }
  }
  return (NULL);
}

void bbman::Board::addPlayer(APlayer *player)
{
  this->_players.push_back(player);
  this->_explosable.push_back(player);
}

bool bbman::Board::addBomb(IBomb *newBomb)
{
  if (std::find_if(std::begin(this->_bombs), std::end(this->_bombs),
		   [&newBomb](IBomb *bomb) {
		     if (newBomb->getPosition() == bomb->getPosition())
		       return (true);
		     return (false);
		   }) == std::end(this->_bombs)
      && !isOutside(newBomb->getPosition())) {
    this->_bombs.push_back(newBomb);
    this->_explosable.push_back(newBomb);
    return (true);
  }
  return (false);
}

void bbman::Board::setPosition(irr::core::vector3df const& pos)
{
  this->_backgroundMesh->setPosition(pos);
  this->_backgroundMesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::Board::getPosition(void) const
{
  return this->_backgroundMesh->getPosition();
}

irr::core::vector3df const& bbman::Board::getSpawnPosition(size_t num) const
{
  if (num < 4) {
    return this->_spawn[num];
  }
  return this->_spawn[0];
}

bool bbman::Board::isValidMove(irr::core::vector3df const& pos,
                               bbman::t_direction          dir) const
{
  return this->_map.at(pos.X / this->_scale.X, pos.Z / this->_scale.Z).node & dir;
}

bool bbman::Board::isInNode(irr::core::vector3df const& pos) const
{
  irr::f32 x = (int)(pos.X / this->_scale.X) * this->_scale.X;
  irr::f32 y = (int)(pos.Z / this->_scale.Z) * this->_scale.Z;
  return pos.X > x + 2.f && pos.Z > y + 2.f
         && pos.X < x + 6.f && pos.Z < y + 6.f;
}

bbman::Map<bbman::Cell>const& bbman::Board::getMap(void) const
{
  return this->_map;
}

std::vector<bbman::APlayer *>const& bbman::Board::getPlayers(void) const
{
  return this->_players;
}

std::list<bbman::IBomb *>const& bbman::Board::getBombs(void) const
{
  return this->_bombs;
}

bool bbman::Board::isColliding(irr::core::aabbox3df const& box) const
{
  for (auto& it : this->_blocks) {
    if (box.intersectsWithBox(it->getBoundingBox())) {
      return true;
    }
  }
  return false;
}

void bbman::Board::deleteBlock(IEntity *entity)
{
  irr::core::vector3d<irr::s32>const& pos = entity->getPosInMap(getScale());
  updateNode(entity->getPosInMap(getScale()));
  this->_map.at(pos.X, pos.Z).id = ItemID::II_NONE;
  entity->explode();
}

void bbman::Board::deleteEntity(IEntity *entity)
{
  entity->explode();
}

void bbman::Board::deleteBomb(IBomb *bomb)
{
  APlayer *owner = getPlayerByID(bomb->getOwnerID());
  bomb->explode();
  if (owner) {
    owner->addBomb(bomb->clone());
  }
}

bbman::IEntity *bbman::Board::getEntityByPosition(irr::core::vector3d<irr::s32>const& pos) const
{
  for (auto it : this->_explosable) {
    if (!it->hasExplosed()) {
      irr::core::vector3d<irr::s32> const& epos = it->getPosInMap(getScale());
      if (epos == pos) {
        return it;
      }
    }
  }
  return NULL;
}

void bbman::Board::explodeBlocks(bbman::IBomb *bomb)
{
  size_t   bombRange = bomb->getRange();
  IEntity *entity    = NULL;

  if (!bomb->isExploding()) {
    return;
  }

  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(getScale()).X + i;
    size_t y = bomb->getPosInMap(getScale()).Z;
    if ((entity = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y)))
	&& entity != bomb) {
      IBlock *block = dynamic_cast<IBlock *>(entity);
      if (block) {
        deleteBlock(entity);
      } else {
	deleteEntity(entity);
      }
      break;
    }
    else if (entity == bomb) {
      deleteBomb(bomb);
    }
    else if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
  }

  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X;
    size_t y = bomb->getPosInMap(this->_scale).Z + i;
    if ((entity = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y)))
	&& entity != bomb) {
      IBlock *block = dynamic_cast<IBlock *>(entity);
      if (block) {
        deleteBlock(entity);
      } else {
	deleteEntity(entity);
      }
      break;
    }
    else if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
  }

  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X - i;
    size_t y = bomb->getPosInMap(this->_scale).Z;
    if ((entity = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y)))
	&& entity != bomb) {
      IBlock *block = dynamic_cast<IBlock *>(entity);
      if (block) {
        deleteBlock(entity);
      } else {
	deleteEntity(entity);
      }
      break;
    }
    else if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
  }

  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X;
    size_t y = bomb->getPosInMap(this->_scale).Z - i;
    if ((entity = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y)))
	&& entity != bomb) {
      IBlock *block = dynamic_cast<IBlock *>(entity);
      if (block) {
        deleteBlock(entity);
      } else {
	deleteEntity(entity);
      }
      break;
    }
    else if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
  }
}

irr::core::vector3df const& bbman::Board::getSize(void) const
{
  return this->_size;
}

irr::core::vector3df const& bbman::Board::getScale(void) const
{
  return this->_scale;
}

bool bbman::Board::isOutside(irr::core::vector3df const& pos)
{
  return (pos.X < 0.f)
         || (pos.X / 10.f) >= this->_map.w
         || (pos.Z < 0.f)
         || (pos.Z / 10.f) >= this->_map.h;
}

void bbman::Board::initTerrain(Irrlicht& irr)
{
  irr::scene::IMesh *mesh;

  this->_texture.setTexture(0, irr.getTexture("./asset//media/wall.jpg"));
  this->_texture.setFlag(irr::video::EMF_LIGHTING, false);
  mesh = irr.getSmgr()->getGeometryCreator()->
         createHillPlaneMesh(irr::core::dimension2d<irr::f32>(10, 10),
                             irr::core::dimension2d<irr::u32>(this->_map.w,
                                                              this->_map.h),
                             &this->_texture, 0,
                             irr::core::dimension2d<irr::f32>(0, 0),
                             irr::core::dimension2d<irr::f32>(this->_map.w,
                                                              this->_map.h));
  this->_backgroundMesh = irr.getSmgr()->addMeshSceneNode(mesh);
  this->_backgroundMesh->setPosition(irr::core::vector3df(this->_map.w * this->_scale.X / 2, 0,
                                                          this->_map.h * this->_scale.Z / 2));
}

void bbman::Board::initMap(void)
{
  for (size_t i = 0; i < this->_map.h; ++i) {
    for (size_t j = 0; j < this->_map.w; ++j) {
      if ((!(i % 2) && !(j % 2))
          || (i == 0 || j == 0 || i == this->_map.h - 1 || j == this->_map.w - 1)) {
        this->_map.at(j, i).id = ItemID::II_BLOCK_INBRKABLE;
      } else {
        this->_map.at(j, i).id = ItemID::II_BLOCK_BRKABLE;
      }
    }
  }
  this->_map.at(1, 1).id = ItemID::II_NONE;
  this->_map.at(1, 2).id = ItemID::II_NONE;
  this->_map.at(2, 1).id = ItemID::II_NONE;
  this->_map.at(3, 1).id = ItemID::II_NONE;

  this->_map.at(17, 11).id = ItemID::II_NONE;
  this->_map.at(17, 10).id = ItemID::II_NONE;
  this->_map.at(16, 11).id = ItemID::II_NONE;
  this->_map.at(15, 11).id = ItemID::II_NONE;

  this->_map.at(17, 1).id = ItemID::II_NONE;
  this->_map.at(17, 2).id = ItemID::II_NONE;
  this->_map.at(16, 1).id = ItemID::II_NONE;
  this->_map.at(15, 1).id = ItemID::II_NONE;

  this->_map.at(1, 11).id = ItemID::II_NONE;
  this->_map.at(1, 10).id = ItemID::II_NONE;
  this->_map.at(2, 11).id = ItemID::II_NONE;
  this->_map.at(3, 11).id = ItemID::II_NONE;
}

void bbman::Board::initNode(void)
{
  for (size_t i = 0; i < this->_map.h; ++i) {
    for (size_t j = 0; j < this->_map.w; ++j) {
      if (this->_map.at(j, i).id != ItemID::II_NONE) {
        if (i > 0) {
	  Cell& north = this->_map.at(j, i - 1);
          north.node &= ~(north.node & ((size_t)DIR_NORTH));
        }
        if (i < this->_map.h - 1) {
	  Cell& south = this->_map.at(j, i + 1);
          south.node &= ~(south.node & ((size_t)DIR_SOUTH));
        }
        if (j > 0) {
	  Cell& east  = this->_map.at(j - 1, i);
          east.node &= ~(east.node & ((size_t)DIR_EAST));
        }
        if (j < this->_map.w - 1) {
	  Cell& west  = this->_map.at(j + 1, i);
          west.node &= ~(west.node & ((size_t)DIR_WEST));
        }
      }
    }
  }
}

void bbman::Board::initMesh(Irrlicht& irr)
{
  ItemID id;

  for (size_t i = 0; i < this->_map.h; ++i) {
    for (size_t j = 0; j < this->_map.w; ++j) {
      id = this->_map.at(j, i).id;

      if (this->_ctor.find((int)id) != this->_ctor.cend()) {
        this->_ctor[(int)id](irr, j, i);
      }
    }
  }
}

void bbman::Board::updateNode(irr::core::vector3d<irr::s32>const& pos)
{
  Cell& north = this->_map.at(pos.X, pos.Z - 1);
  Cell& south = this->_map.at(pos.X, pos.Z + 1);
  Cell& east  = this->_map.at(pos.X - 1, pos.Z);
  Cell& west  = this->_map.at(pos.X + 1, pos.Z);

  north.node |= (north.node | ((size_t)DIR_NORTH));
  south.node |= (south.node | ((size_t)DIR_SOUTH));
  east.node  |= (east.node | ((size_t)DIR_EAST));
  west.node  |= (west.node | ((size_t)DIR_WEST));
}

void bbman::Board::buildInbrkable(Irrlicht& irr, size_t x, size_t y)
{
  IBlock *block = new IndestructibleBlock;
  irr::core::vector3df pos;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    block->init(irr);
    block->setPosition(pos);
    this->_blocks.push_back(block);
    this->_map.at(x, y).id = ItemID::II_BLOCK_INBRKABLE;

    if (y > 0) {
      Cell& north = this->_map.at(x, y - 1);
      north.node &= ~(north.node & ((size_t)DIR_NORTH));
    }
    if (y < this->_map.h - 1) {
      Cell& south = this->_map.at(x, y + 1);
      south.node &= ~(south.node & ((size_t)DIR_SOUTH));
    }
    if (x > 0) {
      Cell& east  = this->_map.at(x - 1, y);
      east.node &= ~(east.node & ((size_t)DIR_EAST));
    }
    if (x < this->_map.w - 1) {
      Cell& west  = this->_map.at(x + 1, y);
      west.node &= ~(west.node & ((size_t)DIR_WEST));
    }

  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
    }
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Board::buildBrkable(Irrlicht& irr, size_t x, size_t y)
{
  IBlock *block = new DestructibleBlock;
  irr::core::vector3df pos;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    block->init(irr);
    block->setPosition(pos);
    this->_dblocks.push_back(block);
    this->_explosable.push_back(block);
  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
    }
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Board::updateBombs(bbman::Irrlicht& irr, irr::f32 delta)
{
  for (std::list<IBomb *>::iterator it = std::begin(this->_bombs);
       it != std::end(this->_bombs);) {
    if ((*it)->hasExplosed()) {
      for (std::list<IEntity *>::iterator it2 = std::begin(this->_explosable);
	   it2 != std::end(this->_explosable);) {
	if ((*it) == (*it2)) {
	  it2 = this->_explosable.erase(it2);
	  break;
	}
	else {
	  ++it2;
	}
      }
      /*APlayer *owner = getPlayerByID((*it)->getOwnerID());
      if (owner) {
	owner->addBomb((*it)->clone());
	}*/
      delete (*it);
      it = this->_bombs.erase(it);
    } else {
      (*it)->update(irr, delta);
      if ((*it)->isExplosing()) {
        explodeBlocks(*it);
      }
      ++it;
    }
  }
}

void bbman::Board::updatePlayers(bbman::Irrlicht& irr, irr::f32 delta)
{
  for (auto& it : this->_players) {
    it->play(irr, this);
    it->update(irr, delta);

    if (it->isRunning()) {
      this->_powerUPs.checkCollision(it);
    }
  }
}
