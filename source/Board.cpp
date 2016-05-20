//
// Board.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:08:25 2016 stephane galibert
// Last update Fri May 20 17:33:08 2016 stephane galibert
//

#include "Board.hpp"

bbman::Board::Board(void)
{
  this->_backgroundMesh = NULL;
  // la taille de la map doit être impaire
  this->_size = irr::core::vector3df(19, 0, 13);
  this->_scale = irr::core::vector3df(10, 10, 10);
}

bbman::Board::~Board(void)
{
  if (this->_backgroundMesh) {
    this->_backgroundMesh->remove();
  }
  for (auto &it : this->_blocks) {
    delete (it);
  }
}

void bbman::Board::init(bbman::Irrlicht &irr)
{
  this->_map.load(this->_size.X, this->_size.Z);
  initMap();
  initTerrain(irr);
  initMesh(irr);
}

void bbman::Board::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  (void)delta;
}

void bbman::Board::setPosition(irr::core::vector3df const& pos)
{
  this->_backgroundMesh->setPosition(pos);
  this->_backgroundMesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::Board::getPosition(void) const
{
  return (this->_backgroundMesh->getPosition());
}

irr::core::aabbox3df const bbman::Board::getBoundingBox(void) const
{
  return (this->_backgroundMesh->getTransformedBoundingBox());
}

bbman::Map<bbman::Cell> const& bbman::Board::getMap(void) const
{
  return (this->_map);
}

irr::core::vector3df const& bbman::Board::getSpawnPosition(size_t num) const
{
  if (num < 4)
    return (this->_spawn[num]);
  return (this->_spawn[0]);
}

bool bbman::Board::isValidMove(irr::core::vector3df const& pos,
			       bbman::t_direction dir) const
{
  Cell const& cell = this->_map.at(pos.X / this->_scale.X, pos.Z / this->_scale.Z);
  return (cell.node & dir);
}

bool bbman::Board::isInNode(irr::core::vector3df const& pos,
			    irr::core::aabbox3df const& box) const
{
  int x = (int)(pos.X / 10.f) * 10.f;
  int y = (int)(pos.Z / 10.f) * 10.f;

  x += (10.f / 2.f);
  y += (10.f / 2.f);
  return (box.isPointInside(irr::core::vector3df(x, 0.f, y)));
}

bool bbman::Board::isColliding(irr::core::aabbox3df const& box) const
{
  for (auto &it : this->_blocks) {
    if (box.intersectsWithBox(it->getBoundingBox())) {
      return (true);
    }
  }
  return (false);
}

irr::core::vector3df const& bbman::Board::getSize(void) const
{
  return (this->_size);
}

irr::core::vector3df const& bbman::Board::getScale(void) const
{
  return (this->_scale);
}

bool bbman::Board::isOutside(irr::core::vector3df const& pos)
{
  return ((pos.X < 0.f)
	  || (pos.X / 10.f) >= this->_map.w
	  || (pos.Z < 0.f)
	  || (pos.Z / 10.f) >= this->_map.h);
}

void bbman::Board::initTerrain(Irrlicht &irr)
{
  irr::scene::IMesh *mesh;

  this->_texture.setTexture(0, irr.getTexture("./media/wall.jpg"));
  this->_texture.setFlag(irr::video::EMF_LIGHTING, false);
  mesh = irr.getSmgr()->getGeometryCreator()->
    createHillPlaneMesh(irr::core::dimension2d<irr::f32>(10, 10),
			irr::core::dimension2d<irr::u32>(this->_map.w * 2,
							 this->_map.h * 2),
			&this->_texture, 0,
			irr::core::dimension2d<irr::f32>(0, 0),
			irr::core::dimension2d<irr::f32>(this->_map.w * 2,
							 this->_map.h * 2));
  this->_backgroundMesh = irr.getSmgr()->addMeshSceneNode(mesh);
  this->_backgroundMesh->setPosition(irr::core::vector3df(this->_map.w * this->_scale.X / 2, 0, this->_map.h * this->_scale.Z / 2));
}

void bbman::Board::initMap(void)
{
  for (size_t i = 0 ; i < this->_map.h; ++i) {
    for (size_t j = 0 ; j < this->_map.w; ++j) {
      if (i == 0 || j == 0 || i == this->_map.h - 1 || j == this->_map.w - 1) {
	this->_map.at(j, i).id = ItemID::II_BLOCK_INBRKABLE;
      }
      else if (!(i % 2) && !(j % 2)) {
	this->_map.at(j, i).id = ItemID::II_BLOCK_INBRKABLE;
      }
    }
  }

  for (size_t i = 0 ; i < this->_map.h; ++i) {
    for (size_t j = 0 ; j < this->_map.w; ++j) {
      if (this->_map.at(j, i).id == ItemID::II_BLOCK_INBRKABLE) {
	if (i == 0 || j == 0 || i == this->_map.h - 1 || j == this->_map.w - 1) {
	  if (i == 0)
	    this->_map.at(j, i + 1).node &= ~(this->_map.at(j, i + 1).node & ((size_t)Direction::DIR_SOUTH));
	  if (j == 0)
	    this->_map.at(j + 1, i).node &= ~(this->_map.at(j + 1, i).node & ((size_t)Direction::DIR_WEST));
	  if (i == this->_map.h - 1)
	    this->_map.at(j, i - 1).node &= ~(this->_map.at(j, i - 1).node & ((size_t)Direction::DIR_NORTH));
	  if (j == this->_map.w - 1)
	    this->_map.at(j - 1, i).node &= ~(this->_map.at(j - 1, i).node & ((size_t)Direction::DIR_EAST));
	}
	else {
	  if (i > 0)
	    this->_map.at(j, i - 1).node &= ~(this->_map.at(j, i - 1).node & ((size_t)Direction::DIR_NORTH));
	  if (i < this->_map.h - 1)
	    this->_map.at(j, i + 1).node &= ~(this->_map.at(j, i + 1).node & ((size_t)Direction::DIR_SOUTH));
	  if (j > 0)
	    this->_map.at(j - 1, i).node &= ~(this->_map.at(j - 1, i).node & ((size_t)Direction::DIR_EAST));
	  if (j < this->_map.w - 1)
	    this->_map.at(j + 1, i).node &= ~(this->_map.at(j + 1, i).node & ((size_t)Direction::DIR_WEST));
	}
      }
    }
  }
  _spawn[0] = irr::core::vector3df(10.f, 0.f, 10.f);
  _spawn[1] = irr::core::vector3df(170.f, 0.f, 10.f);
  _spawn[2] = irr::core::vector3df(170.f, 0.f, 110.f);
  _spawn[3] = irr::core::vector3df(10.f, 0.f, 110.f);
}

void bbman::Board::initMesh(Irrlicht &irr)
{
  IndestructibleBlock *block = NULL;
  irr::core::vector3df ext;

  for (size_t i = 0 ; i < this->_map.h ; ++i) {
    for (size_t j = 0 ; j < this->_map.w ; ++j) {
      if (this->_map.at(j, i).id == ItemID::II_BLOCK_INBRKABLE) {
	block = new IndestructibleBlock;
	try {
	  block->init(irr);
	  ext = block->getBoundingBox().getExtent();
	  block->setPosition(irr::core::vector3df(j * this->_scale.X + (this->_scale.X / 2), (ext.Y / 2), i * this->_scale.Z + (this->_scale.Z / 2)));
	  this->_blocks.push_back(block);
	} catch (std::runtime_error const& e) {
	  if (block)
	    delete (block);
	  std::cerr << e.what() << std::endl;
	}
      }
    }
  }
}
