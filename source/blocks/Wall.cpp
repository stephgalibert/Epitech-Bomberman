//
// Wall.cpp for indi in /home/galibe_s/rendu/bomberman/source/blocks
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu Jun  2 17:14:10 2016 stephane galibert
// Last update Fri Jun  3 00:13:01 2016 stephane galibert
//

#include "Wall.hpp"

bbman::Wall::Wall(void)
{
  this->_mesh = NULL;
}

bbman::Wall::~Wall(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::Wall::init(Irrlicht &irr, std::string const& num)
{
  std::string obj = "./asset/wall/Mur" + num + ".obj";
  std::string alpha = "./asset/wall/Walls_alpha.png";
  std::string light = "./asset/wall/Walls_illum.png";

  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(obj.data()));
  if (this->_mesh) {
    this->_mesh->setMaterialTexture(0, irr.getTexture(alpha.data()));
    this->_mesh->setMaterialTexture(0, irr.getTexture(light.data()));

    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_mesh->setMaterialType(irr::video::EMT_LIGHTMAP_ADD);
    if (num == "1") {
      this->_mesh->setScale(irr::core::vector3df(1.f, 6.f, 9.4f));
      this->_mesh->setRotation(irr::core::vector3df(0, 180, 0));
    }
    if (num == "2") {
      this->_mesh->setScale(irr::core::vector3df(9.4f, 6.f, 1));
    }
    if (num == "3") {
      this->_mesh->setScale(irr::core::vector3df(1.f, 6.f, 9.4f));
      this->_mesh->setRotation(irr::core::vector3df(0, 180, 0));
    }
  }
  else {
    throw (std::runtime_error("cannot add Wall"));
  }
}

void bbman::Wall::setMaterialFlag(irr::video::E_MATERIAL_FLAG flag,
						 bool value)
{
  this->_mesh->setMaterialFlag(flag, value);
}

void bbman::Wall::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  static_cast<void>(delta);
}

void bbman::Wall::addAnimation(irr::scene::ISceneNodeAnimator *anim)
{
  this->_mesh->addAnimator(anim);
  anim->drop();
}

void bbman::Wall::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::Wall::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::Wall::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
}

bool bbman::Wall::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::Wall::explode(Board *board)
{
  (void)board;
}

void bbman::Wall::playExplosion(void)
{

}

void bbman::Wall::setColor(std::string const& color)
{
  this->_color = color;
}

std::string const& bbman::Wall::getColor(void) const
{
  return (this->_color);
}

irr::core::vector3d<irr::s32> const& bbman::Wall::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

bool bbman::Wall::hasExplosed(void) const
{
  return (true);
}

bbman::ItemID bbman::Wall::getID(void) const
{
  return (ItemID::II_BLOCK_INBRKABLE);
}
