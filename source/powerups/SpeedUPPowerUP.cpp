//
// SpeedUPPowerUP.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 18:34:45 2016 stephane galibert
// Last update Thu May 12 16:05:51 2016 stephane galibert
//

#include "SpeedUPPowerUP.hpp"

bbman::SpeedUPPowerUP::SpeedUPPowerUP(void)
{
  this->_node = NULL;
  this->_delta = 0;
}

bbman::SpeedUPPowerUP::~SpeedUPPowerUP(void)
{
  if (this->_node) {
    this->_node->remove();
  }
}

void bbman::SpeedUPPowerUP::init(Irrlicht &irr)
{
  irr::scene::ISceneNodeAnimator *anms = NULL;

  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    this->_node->setMaterialTexture(0, irr.getTexture("../media/t351sml.jpg"));
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

void bbman::SpeedUPPowerUP::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  this->_delta += delta;
}

void bbman::SpeedUPPowerUP::setPosition(irr::core::vector3df const& pos)
{
  this->_node->setPosition(pos);
  this->_node->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::SpeedUPPowerUP::getPosition(void) const
{
  return (this->_node->getPosition());
}

irr::core::aabbox3df const bbman::SpeedUPPowerUP::getBoundingBox(void) const
{
  return (this->_node->getTransformedBoundingBox());
}

bool bbman::SpeedUPPowerUP::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::SpeedUPPowerUP::affectPlayer(IPlayer *player)
{
  player->addEffect(new SpeedUPEffect(player));
}
