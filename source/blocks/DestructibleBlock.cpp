//
// DestructibleBlock.cpp for indie in /home/galibe_s/rendu/bomberman/source/blocks
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 19:14:02 2016 stephane galibert
// Last update Mon May 30 10:37:34 2016 stephane galibert
//

#include "DestructibleBlock.hpp"
#include "Board.hpp"

bbman::DestructibleBlock::DestructibleBlock(void)
{
  this->_node = NULL;
  this->_explosed = true;
}

bbman::DestructibleBlock::~DestructibleBlock(void)
{
  if (this->_node) {
    this->_node->remove();
  }
}

void bbman::DestructibleBlock::init(Irrlicht &irr)
{
  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    this->_node->setMaterialTexture(0, irr.getTexture("./asset/Texture/Texture_cube3.png"));
    this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
    this->_explosed = false;
  }
  else {
    throw (std::runtime_error("cannot add DestructibleBlock"));
  }
}

void bbman::DestructibleBlock::setMaterialFlag(irr::video::E_MATERIAL_FLAG flag,
						 bool value)
{
  this->_node->setMaterialFlag(flag, value);
}

void bbman::DestructibleBlock::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  (void)delta;
}

void bbman::DestructibleBlock::addAnimation(irr::scene::ISceneNodeAnimator *anim)
{
  this->_node->addAnimator(anim);
  anim->drop();
}

void bbman::DestructibleBlock::setPosition(irr::core::vector3df const& pos)
{
  this->_node->setPosition(pos);
  this->_node->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::DestructibleBlock::getPosition(void) const
{
  return (this->_node->getPosition());
}

irr::core::aabbox3df const bbman::DestructibleBlock::getBoundingBox(void) const
{
  return (this->_node->getTransformedBoundingBox());
}

bool bbman::DestructibleBlock::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::DestructibleBlock::explode(Board *board)
{
  if (!this->_explosed) {
    irr::core::vector3d<irr::s32>const& pos = getPosInMap(board->getScale());
    board->updateNode(pos);

    if (board->getMap().at(pos.X, pos.Z).id == getID()) {
      board->getMap().at(pos.X, pos.Z).id = ItemID::II_NONE;
    }

    this->_explosed = true;
    this->_node->setVisible(false);
    /*this->_node->remove();
      this->_node = NULL;*/
  }
}

irr::core::vector3d<irr::s32> const& bbman::DestructibleBlock::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

bool bbman::DestructibleBlock::hasExplosed(void) const
{
  return (this->_explosed);
}

bbman::ItemID bbman::DestructibleBlock::getID(void) const
{
  return (ItemID::II_BLOCK_BRKABLE);
}
