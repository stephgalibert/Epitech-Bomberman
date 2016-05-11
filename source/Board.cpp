//
// Board.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:08:25 2016 stephane galibert
// Last update Wed May 11 16:02:42 2016 stephane galibert
//

#include "Board.hpp"

bbman::Board::Board(void)
{
  this->_backgroundMesh = NULL;
  this->_size = irr::core::vector3df(17, 0, 11);
  this->_scale = irr::core::vector3df(10, 10, 10);
}

bbman::Board::~Board(void)
{
  if (_backgroundMesh)
    _backgroundMesh->remove();
  for (auto &it : _blocks)
    delete (it);
}

void bbman::Board::init(bbman::Irrlicht &irr)
{
  this->_map.load(this->_size.X, this->_size.Z, ItemID::II_NONE);
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

bbman::Map<bbman::ItemID> const& bbman::Board::getMap(void) const
{
  return (this->_map);
}

bool bbman::Board::isColliding(irr::core::aabbox3df const& box) const
{
  for (auto &it : _blocks)
    if (box.intersectsWithBox(it->getBoundingBox()))
      return (true);
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
	  || (pos.X / 10.f) >= _map.w
	  || (pos.Z < 0.f)
	  || (pos.Z / 10.f) >= _map.h);
}

void bbman::Board::initTerrain(Irrlicht &irr)
{
  irr::scene::IMesh *mesh;

  this->_texture.setTexture(0, irr.getTexture("../media/wall.jpg"));
  this->_texture.setFlag(irr::video::EMF_LIGHTING, false);
  mesh = irr.getSmgr()->getGeometryCreator()->
    createHillPlaneMesh(irr::core::dimension2d<irr::f32>(10, 10),
			irr::core::dimension2d<irr::u32>(_map.w * 2, _map.h * 2),
			&_texture, 0,
			irr::core::dimension2d<irr::f32>(0, 0),
			irr::core::dimension2d<irr::f32>(_map.w * 2, _map.h * 2));
  this->_backgroundMesh = irr.getSmgr()->addMeshSceneNode(mesh);
  this->_backgroundMesh->setPosition(irr::core::vector3df(_map.w * 10 / 2, 0,
							  _map.h * 10 / 2));
}

void bbman::Board::initMap(void)
{
  // algo generation de map ici
}

void bbman::Board::initMesh(Irrlicht &irr)
{
  IndestructibleBlock *block = NULL;
  irr::core::vector3df ext;

  for (int i = -1 ; i <= this->_map.h ; ++i)
    for (int j = -1 ; j <= this->_map.w ; ++j)
      if ((i == -1 || j == -1 || i == this->_map.h || j == this->_map.w)
	  || this->_map.at(j, i) == ItemID::II_BLOCK_INBRKABLE)
	{
	  block = new IndestructibleBlock;
	  try {
	    block->init(irr);
	    ext = block->getBoundingBox().getExtent();
	    block->setPosition(irr::core::vector3df(j * 10 + (10 / 2), (ext.Y / 2),
						    i * 10 + (10 / 2)));
	    this->_blocks.push_back(block);
	  } catch (std::runtime_error const& e) {
	    if (block)
	      delete (block);
	    std::cerr << e.what() << std::endl;
	  }
	}
}
