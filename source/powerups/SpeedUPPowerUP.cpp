//
// SpeedUPPowerUP.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May  8 18:34:45 2016 stephane galibert
// Last update Tue May 31 20:26:46 2016 stephane galibert
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

void bbman::SpeedUPPowerUP::init(Irrlicht &irr, std::string const& color)
{
  irr::scene::ISceneNodeAnimator *anms = NULL;

  (void)color;
  this->_node = irr.getSmgr()->addCubeSceneNode();
  if (this->_node) {
    this->_node->setMaterialTexture(0, irr.getTexture("./asset/media/t351sml.jpg"));
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

void bbman::SpeedUPPowerUP::explode(Board *board)
{
  (void)board;
}

void bbman::SpeedUPPowerUP::playExplosion(void)
{

}

irr::core::vector3d<irr::s32> const& bbman::SpeedUPPowerUP::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

void bbman::SpeedUPPowerUP::affectPlayer(APlayer *player)
{
  player->addEffect(new SpeedUPEffect(player));
}

bool bbman::SpeedUPPowerUP::hasExplosed(void) const
{
  return (true);
}

std::string const& bbman::SpeedUPPowerUP::getColor(void) const
{
  return (this->_color);
}

void bbman::SpeedUPPowerUP::setColor(std::string const& color)
{
  this->_color = color;
}
