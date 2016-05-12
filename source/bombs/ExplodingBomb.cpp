//
// ExplodingBomb.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 18:11:12 2016 stephane galibert
// Last update Thu May 12 16:01:31 2016 stephane galibert
//

#include "ExplodingBomb.hpp"

bbman::ExplodingBomb::ExplodingBomb(bbman::IPlayer *owner)
{
  this->_mesh = NULL;
  this->_owner = owner;
  this->_delta = 0;
  this->_explosing = false;
  this->_explosed = false;
}

bbman::ExplodingBomb::~ExplodingBomb(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::ExplodingBomb::init(bbman::Irrlicht &irr)
{
  try {
    this->initMesh(irr);
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }
}

void bbman::ExplodingBomb::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  if (this->_delta <= DELAY_TO_EXPLOSE) {
    this->_delta += delta;
    this->_explosing = (this->_delta > DELAY_TO_EXPLOSE);
  }
  if (this->_explosing) {
    this->_explosed = !(this->_delta < DELAY_TO_EXPLOSE + DELAY_EXPLOSING);
    if (!this->_explosed) {
      this->_delta += delta;
    }
  }
}

bbman::IBomb *bbman::ExplodingBomb::clone(void) const
{
  return (new ExplodingBomb(this->_owner));
}

void bbman::ExplodingBomb::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::ExplodingBomb::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::ExplodingBomb::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
}

bool bbman::ExplodingBomb::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

std::string bbman::ExplodingBomb::getName(void) const
{
  return ("Exploding bomb");
}

bool bbman::ExplodingBomb::isExplosing(void) const
{
  return (this->_explosing);
}

bool bbman::ExplodingBomb::hasExplosed(void) const
{
  return (this->_explosed);
}
void bbman::ExplodingBomb::initMesh(bbman::Irrlicht &irr)
{
  std::string txt = "../media/ninja.b3d";

  this->_mesh = irr.getSmgr()->addAnimatedMeshSceneNode(irr.getMesh(txt.data()));
  if (this->_mesh) {
    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_mesh->setAnimationSpeed(0);
    this->_mesh->setCurrentFrame(3);
    this->_mesh->setScale(irr::core::vector3df(1.5f, 1.5f, 1.5f));
    this->_mesh->setRotation(irr::core::vector3df(0, 0, 0));
  }
  else {
    throw (std::runtime_error("can not create exploding bomb"));
  }
}

irr::f32 bbman::ExplodingBomb::getDelay(void) const
{
  return (ExplodingBomb::DELAY_TO_EXPLOSE);
}

irr::f32 bbman::ExplodingBomb::getDelta(void) const
{
  return (this->_delta);
}
