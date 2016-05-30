//
// IndestructibleBlock.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May  7 18:23:18 2016 stephane galibert
// Last update Mon May 30 08:57:51 2016 stephane galibert
//

#include "IndestructibleBlock.hpp"
#include "Board.hpp"

bbman::IndestructibleBlock::IndestructibleBlock(void)
{
  this->_node = NULL;
}

bbman::IndestructibleBlock::~IndestructibleBlock(void)
{
  if (this->_node) {
    this->_node->remove();
  }
}

void bbman::IndestructibleBlock::init(Irrlicht &irr)
{
  this->_node = irr.getSmgr()->addCubeSceneNode();
  //std::string txt = "./asset/Ind_Cube.obj";
  //this->_node = irr.getSmgr()->addMeshSceneNode(irr.getMesh(txt.data()));
  if (this->_node) {
    this->_node->setMaterialTexture(0, irr.getTexture("./asset/Texture/Texture_cube1.png"));
    //this->_node->setMaterialTexture(0, irr.getTexture("./asset/Texture/Texture_Ind_Cube.png"));
    this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  }
  else {
    throw (std::runtime_error("cannot add IndestructibleBlock"));
  }
}

void bbman::IndestructibleBlock::setMaterialFlag(irr::video::E_MATERIAL_FLAG flag,
						 bool value)
{
  this->_node->setMaterialFlag(flag, value);
}

void bbman::IndestructibleBlock::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  static_cast<void>(delta);
}

void bbman::IndestructibleBlock::addAnimation(irr::scene::ISceneNodeAnimator *anim)
{
  this->_node->addAnimator(anim);
  anim->drop();
}

void bbman::IndestructibleBlock::setPosition(irr::core::vector3df const& pos)
{
  //this->_node->setPosition(irr::core::vector3df(pos.X, ext.Y / 2, pos.Z));
  this->_node->setPosition(pos);
  this->_node->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::IndestructibleBlock::getPosition(void) const
{
  return (this->_node->getPosition());
}

irr::core::aabbox3df const bbman::IndestructibleBlock::getBoundingBox(void) const
{
  return (this->_node->getTransformedBoundingBox());
}

bool bbman::IndestructibleBlock::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::IndestructibleBlock::explode(Board *board)
{
  (void)board;
}

irr::core::vector3d<irr::s32> const& bbman::IndestructibleBlock::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

bool bbman::IndestructibleBlock::hasExplosed(void) const
{
  return (true);
}

bbman::ItemID bbman::IndestructibleBlock::getID(void) const
{
  return (ItemID::II_BLOCK_INBRKABLE);
}
