//
// IndestructibleBlock.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:54:19 2016 avelin_j
// Last update Sat Jun  4 23:55:22 2016 avelin_j
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

void bbman::IndestructibleBlock::init(Irrlicht &irr, std::string const& color)
{
  std::string txt = "./asset/cube/indCube" + color + ".png";
  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    if (color == "0") {
      this->_node->setMaterialTexture(0, irr.getTexture("./asset/cube/indCubeGrey.png"));
    }
    else {
      this->_node->setMaterialTexture(0, irr.getTexture(txt.data()));
    }

    this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  }
  else {
    throw (std::runtime_error("cannot add IndestructibleBlock"));
  }
}

void bbman::IndestructibleBlock::setScale(irr::core::vector3df const& scale)
{
  if (this->_node) {
    this->_node->setScale(scale);
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

void bbman::IndestructibleBlock::playExplosion(void)
{

}

void bbman::IndestructibleBlock::setColor(std::string const& color)
{
  this->_color = color;
}

std::string const& bbman::IndestructibleBlock::getColor(void) const
{
  return (this->_color);
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

int bbman::IndestructibleBlock::getScoreValue(void) const
{
  return (0);
}

irr::scene::ISceneNode const *bbman::IndestructibleBlock::testGetNode(void) const
{
  return (this->_node);
}
