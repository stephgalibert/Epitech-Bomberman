//
// Board.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:08:25 2016 stephane galibert
// Last update Sat Jun  4 19:58:35 2016 stephane galibert
//

#include "Board.hpp"
#include "Loader.hpp"

bbman::Board::Board(void)
{
  this->_backgroundMesh = NULL;

  // la taille de la map doit être impaire
  this->_size                                  = irr::core::vector3df(19, 0, 13);
  this->_scale                                 = irr::core::vector3df(10, 10, 10);
  this->_ctor[(int)ItemID::II_BLOCK_INBRKABLE] =
    std::bind(&bbman::Board::buildInbrkable, this, std::placeholders::_1,
              std::placeholders::_2, std::placeholders::_3);
  this->_ctor[(int)ItemID::II_BLOCK_BRKABLE] =
    std::bind(&bbman::Board::buildBrkable, this, std::placeholders::_1,
    std::placeholders::_2, std::placeholders::_3);
  this->_irr = NULL;
}

bbman::Board::~Board(void)
{
  for (auto &it : this->_pss) {
    it->remove();
  }
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
  this->_irr = &irr;
  initMap();
  initNode();
  initTerrain(irr);
  initMesh(irr);
  this->_spawn[0] = irr::core::vector3df(170.f, 0.f, 110.f);
  this->_spawn[1] = irr::core::vector3df(170.f, 0.f, 10.f);
  this->_spawn[2] = irr::core::vector3df(10.f, 0.f, 10.f);
  this->_spawn[3] = irr::core::vector3df(10.f, 0.f, 110.f);
}

void bbman::Board::init(bbman::Irrlicht& irr, bbman::Loader const& loader)
{
  this->_map = loader.getMap();

  for (auto& it : loader.getPlayers()) {
    addPlayer(it);
  }

  for (auto& it : loader.getBombs()) {
    addBomb(it);
  }
  this->_irr = &irr;
  initNode();
  initTerrain(irr);
  initMesh(irr);
  this->_spawn[0] = irr::core::vector3df(170.f, 0.f, 110.f);
  this->_spawn[1] = irr::core::vector3df(170.f, 0.f, 10.f);
  this->_spawn[2] = irr::core::vector3df(10.f, 0.f, 10.f);
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

  for (auto& it : this->_dblocks) {
    it->update(irr, delta);
  }
}

bool bbman::Board::hasWinners(void) const
{
  int nbAlive = 0;

  for (auto it : this->_players) {
    if (!it->hasExplosed()) {
      ++nbAlive;
    }
  }
  return nbAlive > 0 && nbAlive < 2;
}

bbman::APlayer *bbman::Board::getWinner(void) const
{
  for (auto it : this->_players) {
    if (!it->hasExplosed()) {
      return (it);
    }
  }
  return (NULL);
}

bool bbman::Board::isNoPlayer(void) const
{
  int n = 0;
  for (auto it : this->_players) {
    if (!it->hasExplosed()) {
      ++n;
    }
  }
  return n == 0;
}

bbman::APlayer * bbman::Board::getPlayerByID(size_t id) const
{
  for (auto it : this->_players) {
    if (it->getID() == id) {
      return it;
    }
  }
  return NULL;
}

bool bbman::Board::isNotProtected(IBomb                              *bombs,
                                  irr::core::vector3d<irr::s32>const& bomb,
                                  irr::core::vector3d<irr::s32>const& block)
{
  if (block.X == bomb.X) {
    if (block.Z > bomb.Z) {
      if (this->_map.at(block.X, block.Z - 1).id == ItemID::II_BLOCK_INBRKABLE)
        return false;
    }
    else if (block.Z < bomb.Z) {
      if (this->_map.at(block.X, block.Z + 1).id == ItemID::II_BLOCK_INBRKABLE)
        return false;
    }

    if (tools::StaticTools::getDistance2D(bomb, block) > bombs->getRange())
      return false;
  }
  else if (block.Z == bomb.Z) {
    if (block.X > bomb.X) {
      if (this->_map.at(block.X - 1, block.Z).id == ItemID::II_BLOCK_INBRKABLE)
        return false;
    }
    else if (block.X < bomb.X) {
      if (this->_map.at(block.X + 1, block.Z).id == ItemID::II_BLOCK_INBRKABLE)
        return false;
    }

    if (tools::StaticTools::getDistance2D(bomb, block) > bombs->getRange())
      return false;
  }
  else
    return false;

  return true;
}

bool bbman::Board::isInExplosion(irr::core::vector3d<irr::s32>const& pos)
{
  for (auto it : this->_bombs) {
    irr::core::vector3d<irr::s32>const& bpos = it->getPosInMap(getScale());

    if (isNotProtected(it, bpos, pos)) {
      return true;
    }
  }
  return false;
}

void bbman::Board::addPlayer(APlayer *player)
{
  this->_players.push_back(player);
  this->_explosable.push_back(player);
}

bool bbman::Board::addBomb(IBomb *newBomb)
{
  if ((std::find_if(std::begin(this->_bombs), std::end(this->_bombs),
                    [&newBomb](IBomb * bomb) {
                      if (newBomb->getPosition() == bomb->getPosition())
                        return true;

                      return false;
                    }) == std::end(this->_bombs))
      && !isOutside(newBomb->getPosition())) {
    this->_bombs.push_back(newBomb);
    this->_explosable.push_back(newBomb);
    return true;
  }
  return false;
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

  return pos.X > x + 4.f && pos.Z > y + 4.f
         && pos.X < x + 6.f && pos.Z < y + 6.f;
}

bbman::Map<bbman::Cell>const& bbman::Board::getMap(void) const
{
  return this->_map;
}

bbman::Map<bbman::Cell>& bbman::Board::getMap(void)
{
  return this->_map;
}

std::vector<bbman::APlayer *>const& bbman::Board::getPlayers(void) const
{
  return this->_players;
}

std::vector<bbman::IBlock *>const& bbman::Board::getBlocks(void) const
{
  return this->_blocks;
}

std::list<bbman::IBlock *>const& bbman::Board::getDBlocks(void) const
{
  return this->_dblocks;
}

std::list<bbman::IBomb *>const& bbman::Board::getBombs(void) const
{
  return this->_bombs;
}

bbman::PowerUPs const& bbman::Board::getPowerUPs(void) const
{
  return this->_powerUPs;
}

bbman::PowerUPs& bbman::Board::getPowerUPs(void)
{
  return this->_powerUPs;
}

bbman::Irrlicht * bbman::Board::getIrrlicht(void)
{
  return this->_irr;
}

bbman::IBlock * bbman::Board::createInbrkable(Irrlicht& irr, size_t x, size_t y)
{
  IndestructibleBlock *block = new IndestructibleBlock;
  irr::core::vector3df pos;
  irr::core::vector3df ext;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    block->init(irr, "Grey");
    ext = block->getBoundingBox().getExtent();
    pos.Y = ext.Y / 2;
    block->setPosition(pos);
    block->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
      block = NULL;
    }
    std::cerr << e.what() << std::endl;
  }
  return block;
}

void bbman::Board::disableDirection(size_t x, size_t y)
{
  if (y > 0) {
    Cell& north = this->_map.at(x, y - 1);
    north.node &= ~(north.node & ((size_t)DIR_NORTH));
  }

  if (y < this->_map.h - 1) {
    Cell& south = this->_map.at(x, y + 1);
    south.node &= ~(south.node & ((size_t)DIR_SOUTH));
  }

  if (x > 0) {
    Cell& east = this->_map.at(x - 1, y);
    east.node &= ~(east.node & ((size_t)DIR_EAST));
  }

  if (x < this->_map.w - 1) {
    Cell& west = this->_map.at(x + 1, y);
    west.node &= ~(west.node & ((size_t)DIR_WEST));
  }
}

void bbman::Board::registerBlock(IBlock *block)
{
  irr::core::vector3d<irr::s32>const& pos = block->getPosInMap(this->_scale);
  this->_map.at(pos.X, pos.Z).id = block->getID();
  this->_blocks.push_back(block);
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

std::list<bbman::IEntity *> const& bbman::Board::getEntityByPosition(irr::core::vector3d<irr::s32>const& pos)
{
  this->_entities.erase(this->_entities.begin(), this->_entities.end());
  for (auto it : this->_explosable) {
    if (!it->hasExplosed()) {
      irr::core::vector3d<irr::s32>const& epos = it->getPosInMap(getScale());

      if (epos == pos) {
	this->_entities.push_back(it);
      }
    }
  }
  return this->_entities;
}

void bbman::Board::explodeBlocks(bbman::IBomb *bomb)
{
  size_t   bombRange = bomb->getRange();
  IEntity *entity    = NULL;
  bool end = false;

  if (!bomb || !bomb->isExploding()) {
    return;
  }
  APlayer *owner = getPlayerByID(bomb->getOwnerID());
  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(getScale()).X + i;
    size_t y = bomb->getPosInMap(getScale()).Z;
    std::list<IEntity *> const& entities = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y));
    for (auto &it : entities) {
      entity = it;
      if (it != bomb) {
	owner->setScore(owner->getScore() + entity->getScoreValue());
	entity->explode(this);
	entity->playExplosion();
	end = true;
      } else if (it == bomb) {
	bomb->explode(this);
	bomb->playExplosion();
	if (owner) {
	  owner->addBomb(bomb->clone());
	}
      }
    }
    if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE)
      break;
    if (end)
      break;
  }
  end = false;
  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X;
    size_t y = bomb->getPosInMap(this->_scale).Z + i;

    std::list<IEntity *> const& entities = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y));
    for (auto &it : entities) {
      entity = it;
      if (it != bomb) {
	owner->setScore(owner->getScore() + entity->getScoreValue());
	entity->explode(this);
	entity->playExplosion();
	end = true;
      }
    }
    if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
    if (end)
      break;
  }
  end = false;
  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X - i;
    size_t y = bomb->getPosInMap(this->_scale).Z;
    std::list<IEntity *> const& entities = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y));
    for (auto &it : entities) {
      entity = it;
      if (it != bomb) {
	owner->setScore(owner->getScore() + entity->getScoreValue());
	entity->explode(this);
	entity->playExplosion();
	end = true;
      }
    }
    if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE) {
      break;
    }
    if (end)
      break;
  }
  end = false;
  for (size_t i = 0; i <= bombRange; ++i) {
    size_t x = bomb->getPosInMap(this->_scale).X;
    size_t y = bomb->getPosInMap(this->_scale).Z - i;
    std::list<IEntity *> const& entities = getEntityByPosition(irr::core::vector3d<irr::s32>(x, 0, y));
    for (auto &it : entities) {
      entity = it;
      if (it != bomb) {
	owner->setScore(owner->getScore() + entity->getScoreValue());
	entity->explode(this);
	entity->playExplosion();
	end = true;
      }
    }
    if (this->_map.at(x, y).id == ItemID::II_BLOCK_INBRKABLE)
      end = true;
    if (end)
      break;
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
  std::string txt = "./asset/Ground.obj";
  this->_backgroundMesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(txt.data()));
  this->_backgroundMesh->setMaterialTexture(0, irr.getTexture("./asset/Texture_ground.png"));
  this->_backgroundMesh->setMaterialTexture(1, irr.getTexture("./asset/Texture_ground_illum.png"));
  this->_backgroundMesh->setMaterialType(irr::video::EMT_LIGHTMAP_ADD);
  this->_backgroundMesh->setScale(irr::core::vector3df(10, 1, 8));

  irr::core::vector3df pos;
  pos.X = this->_map.w * this->_scale.X / 2;
  pos.Z = this->_map.h * this->_scale.Z / 2;
  this->_backgroundMesh->setPosition(pos);
  pos.Y += 120;
  this->_light = irr.getSmgr()->addLightSceneNode(0, pos);
  this->_light->setLightType(irr::video::ELT_DIRECTIONAL);

  irr::scene::ISceneNode* pNode = irr.getSmgr()->addEmptySceneNode();
  this->_light->setPosition(irr::core::vector3df(0,0,1));
  this->_light->setParent(pNode);
  pNode->setRotation(irr::core::vector3df(90, 0, 0));
}

void bbman::Board::initMap(void)
{
  for (size_t i = 0; i < this->_map.h; ++i) {
    for (size_t j = 0; j < this->_map.w; ++j) {
      if ((!(i % 2) && !(j % 2))
          || ((i == 0) || (j == 0) || (i == this->_map.h - 1) || (j == this->_map.w - 1))) {
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
  this->_map.at(17, 1).id  = ItemID::II_NONE;
  this->_map.at(17, 2).id  = ItemID::II_NONE;
  this->_map.at(16, 1).id  = ItemID::II_NONE;
  this->_map.at(15, 1).id  = ItemID::II_NONE;
  this->_map.at(1, 11).id  = ItemID::II_NONE;
  this->_map.at(1, 10).id  = ItemID::II_NONE;
  this->_map.at(2, 11).id  = ItemID::II_NONE;
  this->_map.at(3, 11).id  = ItemID::II_NONE;
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
          Cell& east = this->_map.at(j - 1, i);
          east.node &= ~(east.node & ((size_t)DIR_EAST));
        }

        if (j < this->_map.w - 1) {
          Cell& west = this->_map.at(j + 1, i);
          west.node &= ~(west.node & ((size_t)DIR_WEST));
        }
      }
    }
  }
}

void bbman::Board::initMesh(Irrlicht& irr)
{
  ItemID id;
  std::string txt    = "./asset/pillar/Pilliar_blue.obj";
  std::string txtobj = "./asset/pillar/Texture_pillier_green.png";

  for (size_t i = 0; i < this->_map.h; ++i) {
    for (size_t j = 0; j < this->_map.w; ++j) {
      id = this->_map.at(j, i).id;

      if (this->_ctor.find((int)id) != this->_ctor.cend()) {
        this->_ctor[(int)id](irr, j, i);
      }
    }
  }

  buildPillar(irr, 0, 0, "Green");
  buildPillar(irr, 18, 0, "Orange");
  buildPillar(irr, 0, 12, "Purple");
  buildPillar(irr, 18, 12, "Blue");
  buildWall(irr, 18, 6, "1");
  buildWall(irr, 9, 12, "2");
  buildWall(irr, 0, 6, "3");
  buildParticle(irr, 0, 0, "Green");
  buildParticle(irr, 0, 12, "Purple");
  buildParticle(irr, 18, 12, "Blue");
  buildParticle(irr, 18, 0, "Orange");
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
  irr::core::vector3df ext;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    if ((x == 0 || y == 0) || (x == 18 || y == 12))
      block->init(irr, "0");
    else {
      if (x < 8 && y < 6) {
	block->init(irr, "Green");
      } else if (x > 10 && y < 6) {
	block->init(irr, "Orange");
      } else if (x > 10 && y > 6) {
	block->init(irr, "Blue");
      } else if (x < 8 && y > 6) {
	block->init(irr, "Purple");
      } else {
	block->init(irr, "White");
      }
    }
    ext = block->getBoundingBox().getExtent();
    block->setPosition(irr::core::vector3df(pos.X, ext.Y / 2, pos.Z));
    this->_blocks.push_back(block);
    this->_map.at(x, y).id = ItemID::II_BLOCK_INBRKABLE;
  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
    }
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Board::buildPillar(Irrlicht& irr, size_t x, size_t y,
			       std::string const& color)
{
  IBlock *block = new Pillar;
  irr::core::vector3df pos;
  irr::core::vector3df ext;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    block->init(irr, color);
    ext = block->getBoundingBox().getExtent();
    block->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
    this->_blocks.push_back(block);
    this->_map.at(x, y).id = ItemID::II_BLOCK_INBRKABLE;
  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
    }
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Board::buildWall(Irrlicht& irr, size_t x, size_t y,
			       std::string const& color)
{
  IBlock *block = new Wall;
  irr::core::vector3df pos;
  irr::core::vector3df ext;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {
    block->init(irr, color);
    ext = block->getBoundingBox().getExtent();
    block->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
    this->_blocks.push_back(block);
    this->_map.at(x, y).id = ItemID::II_BLOCK_INBRKABLE;
  } catch (std::runtime_error const& e) {
    if (block) {
      delete (block);
    }
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Board::buildParticle(Irrlicht& irr, size_t x, size_t y,
				 std::string const& color)
{
  std::string txt = "./asset/Particles/particle" + color + ".png";
  irr::core::vector3df pos;

  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  irr::scene::IParticleSystemSceneNode *ps =
    irr.getSmgr()->addParticleSystemSceneNode(false);
  ps->setMaterialTexture(0, irr.getTexture(txt.c_str()));
  ps->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
  ps->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
  irr::scene::IParticleEmitter* emitter =
    ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(-5,5,-5,5,-5,5),
			 irr::core::vector3df(0.0f,0.005f,0.0f),
			 2,5,
			 irr::video::SColor(0,255,255,255),
			 irr::video::SColor(0,255,255,255),
			 4000,6000,0,
			 irr::core::dimension2df(1.f,1.f),
			 irr::core::dimension2df(3.f,3.f));
  ps->setEmitter(emitter);
  emitter->drop();
  irr::scene::IParticleAffector* fadeOutAffector =
    ps->createFadeOutParticleAffector(irr::video::SColor(0, 0, 0, 0), 100);
  ps->addAffector(fadeOutAffector);
  fadeOutAffector->drop();
  this->_pss.push_back(ps);
}

void bbman::Board::buildBrkable(Irrlicht& irr, size_t x, size_t y)
{
  IBlock *block = new DestructibleBlock;
  irr::core::vector3df pos;
  irr::core::vector3df ext;
  int random = 0;

  random = this->_generator(0, 100);
  pos.X = x * this->_scale.X + (this->_scale.X / 2);
  pos.Z = y * this->_scale.Z + (this->_scale.Z / 2);
  try {

    if (x < 9 && y < 6) {
      block->init(irr, "Green");
    } else if (x > 9 && y < 6) {
      block->init(irr, "Orange");
    } else if (x > 9 && y > 6) {
      block->init(irr, "Blue");
    } else if (x < 9 && y > 6) {
      block->init(irr, "Purple");
    } else {
      block->init(irr, "White");
    }
    ext = block->getBoundingBox().getExtent();
    block->setPosition(irr::core::vector3df(pos.X, ext.Y / 2, pos.Z));
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
    irr::core::vector3df const& pos = it->getPosition();
    if (pos.X < 10 || pos.Z < 10 || pos.X > 180 || pos.Z > 120)
      it->explode(this);
    it->update(irr, delta);

    if (it->isRunning()) {
      this->_powerUPs.checkCollision(it, this->_scale);
    }
  }
}
