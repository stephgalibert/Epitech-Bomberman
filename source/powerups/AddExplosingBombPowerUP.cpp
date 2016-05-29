//
// AddExplosingBombPowerUp.cpp for inde in /home/galibe_s/rendu/bomberman/source/powerups
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:09:35 2016 stephane galibert
// Last update Sun May 29 10:12:14 2016 stephane galibert
//

#include "AddExplosingBombPowerUP.hpp"

bbman::AddExplosingBombPowerUP::AddExplosingBombPowerUP(void)
{
  this->_node = NULL;
  this->_delta = 0;
}

bbman::AddExplosingBombPowerUP::~AddExplosingBombPowerUP(void)
{
  if (this->_node) {
    this->_node->remove();
  }
}

void bbman::AddExplosingBombPowerUP::init(Irrlicht &irr)
{
  irr::scene::ISceneNodeAnimator *anms = NULL;

  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    //this->_node->setMaterialTexture(0, irr.getTexture("./asset/media/t351sml.jpg"));
    this->_node->setMaterialTexture(0, irr.getTexture("./asset/media/water.jpg"));
    this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_node->setScale(irr::core::vector3df(0.3f, 0.3f, 0.3f));
    anms = irr.getSmgr()->createRotationAnimator(irr::core::vector3df(0, 1, 0));
    if (anms) {
      this->_node->addAnimator(anms);
      anms->drop();
    }
  }
  else {
    throw (std::runtime_error("cannot add IndestructibleBlock"));
  }
}

void bbman::AddExplosingBombPowerUP::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  this->_delta += delta;
}

void bbman::AddExplosingBombPowerUP::setPosition(irr::core::vector3df const& pos)
{
  this->_node->setPosition(pos);
  this->_node->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::AddExplosingBombPowerUP::getPosition(void) const
{
  return (this->_node->getPosition());
}

irr::core::aabbox3df const bbman::AddExplosingBombPowerUP::getBoundingBox(void) const
{
  return (this->_node->getTransformedBoundingBox());
}

bool bbman::AddExplosingBombPowerUP::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::AddExplosingBombPowerUP::explode(void)
{
  std::cerr << "trying to explode a explos" << std::endl;
}

irr::core::vector3d<irr::s32> const& bbman::AddExplosingBombPowerUP::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

void bbman::AddExplosingBombPowerUP::affectPlayer(APlayer *player)
{
  player->addEffect(new AddExplosingBombEffect(player));
}

bool bbman::AddExplosingBombPowerUP::hasExplosed(void) const
{
  return (true);
}
