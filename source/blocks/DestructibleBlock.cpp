//
// DestructibleBlock.cpp for indie in /home/galibe_s/rendu/bomberman/source/blocks
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 19:14:02 2016 stephane galibert
// Last update Mon May 30 17:27:17 2016 stephane galibert
//

#include "DestructibleBlock.hpp"
#include "Board.hpp"

bbman::DestructibleBlock::DestructibleBlock(void)
{
  this->_node = NULL;
  this->_explosed = true;
  //this->_task = NULL;
}

bbman::DestructibleBlock::~DestructibleBlock(void)
{
  if (this->_node) {
    this->_node->remove();
  }
  /*if (this->_task) {
    if (this->_task->isRunning()) {
      this->_task->stop();
      while (!this->_task->isFinished());
    }
    delete (this->_task);
    }*/
}

void bbman::DestructibleBlock::init(Irrlicht &irr)
{
  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    //this->_task = new ExplosionTask(irr);
    /*this->_ps = irr.getSmgr()->addParticleSystemSceneNode(false);
      this->_ps->setVisible(false);
      this->_ps->setMaterialTexture(0, irr.getTexture("./asset/media/fire.bmp"));
      this->_ps->setScale(irr::core::vector3df(1,1,1));
      this->_ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->_ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
      this->_ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);*/
    // !
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

    PowerUPs &powerups = board->getPowerUPs();
    Irrlicht *irr = board->getIrrlicht();
    powerups.add(*irr, board, getPosition());

    /*this->_ps->setPosition(getPosition());
    irr::scene::IParticleEmitter* em =
    this->_ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(1,1,1,1,1,1),
    irr::core::vector3df(0.0f, 0.03f, 0.0f),
    100,100,
    irr::video::SColor(0,255,255,255),
    irr::video::SColor(0,255,255,255),
    300,500,180,
    irr::core::dimension2df(10.f,10.f),
    irr::core::dimension2df(10.f,10.f));
    this->_ps->setEmitter(em);
    em->drop();
    irr::scene::IParticleAffector* paf = this->_ps->createFadeOutParticleAffector();
    this->_ps->addAffector(paf);
    paf->drop();*/
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
