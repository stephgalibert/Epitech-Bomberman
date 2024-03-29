//
// DestructibleBlock.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:50:57 2016 avelin_j
// Last update Sat Jun  4 23:52:13 2016 avelin_j
//

#include "DestructibleBlock.hpp"
#include "Board.hpp"

bbman::DestructibleBlock::DestructibleBlock(void)
{
  this->_node = NULL;
  this->_explosed = true;
  this->_explosion = NULL;
  this->_anim = true;
}

bbman::DestructibleBlock::~DestructibleBlock(void)
{
  if (this->_node) {
    this->_node->remove();
  }
  if (this->_explosion) {
    delete (this->_explosion);
  }
}

void bbman::DestructibleBlock::init(Irrlicht &irr, std::string const& color)
{
  std::string txt = "./asset/cube/Texture_cube_" + color + ".png";

  this->_color = color;
  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    this->_explosion = new Explosion;
    this->_explosion->init(irr, color);
    this->_node->setMaterialTexture(0, irr.getTexture(txt.data()));
    if (color == "White") {
      this->_node->setMaterialTexture(1, irr.getTexture(txt.data()));
    //this->_node->setMaterialTexture(0, irr.getTexture("./asset/cube/Texture_cube_orange.png"));
      this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }
    //this->_node->getMaterial(0).FogEnable = false;
    //this->_node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
    this->_node->setScale(irr::core::vector3df(0.8f, 1.f, 0.8));
    this->_node->setMaterialType(irr::video::EMT_LIGHTMAP_ADD);
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
  if (this->_explosion) {
    this->_explosion->update(delta);
    if (this->_explosion->hasFinished()) {
      delete (this->_explosion);
      this->_explosion = NULL;
    }
  }
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

void bbman::DestructibleBlock::playExplosion(void)
{
  if (this->_anim && this->_explosion) {
    this->_explosion->play(getPosition());
  }
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

    PowerUPs &powerups = board->getPowerUPs();
    Irrlicht *irr = board->getIrrlicht();
    powerups.add(*irr, getPosition());
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

void bbman::DestructibleBlock::setColor(std::string const& color)
{
  this->_color = color;
}

std::string const& bbman::DestructibleBlock::getColor(void) const
{
  return (this->_color);
}

void bbman::DestructibleBlock::disableAnimation(void)
{
  this->_anim = false;
}

int bbman::DestructibleBlock::getScoreValue(void) const
{
  return (5);
}

irr::scene::ISceneNode const *bbman::DestructibleBlock::testGetNode(void) const
{
  return (this->_node);
}

bbman::Explosion const * bbman::DestructibleBlock::testGetExplosion(void) const
{
  return (this->_explosion);
}
