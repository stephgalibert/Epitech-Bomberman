//
// Pillar.cpp for indie in /home/galibe_s/rendu/bomberman/source/blocks
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu Jun  2 14:53:07 2016 stephane galibert
// Last update Thu Jun  2 21:26:59 2016 stephane galibert
//

#include "Pillar.hpp"
#include "Board.hpp"

bbman::Pillar::Pillar(void)
{
  this->_mesh = NULL;
}

bbman::Pillar::~Pillar(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::Pillar::init(Irrlicht &irr, std::string const& color)
{
  std::string obj = "./asset/pillier/pillar.obj";
  std::string txt = "./asset/pillier/Texture_pillier_" + color + ".png";
  std::string light = "./asset/pillier/Texture_pillier_Selfillum_" + color + ".png";

  //this->_mesh = irr.getSmgr()->addCubeSceneNode();
  //std::string txt = "./asset/Ind_Cube.obj";
  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(obj.data()));
  if (this->_mesh) {
    //this->_mesh->setMaterialTexture(0, irr.getTexture("./asset/indCube.png"));
    this->_mesh->setMaterialTexture(0, irr.getTexture(txt.data()));
    this->_mesh->setMaterialTexture(1, irr.getTexture(light.data()));

    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_mesh->setScale(irr::core::vector3df(8.f, 6.f, 8.f));
    this->_mesh->setMaterialType(irr::video::EMT_LIGHTMAP_ADD);
  }
  else {
    throw (std::runtime_error("cannot add Pillar"));
  }
}

void bbman::Pillar::setMaterialFlag(irr::video::E_MATERIAL_FLAG flag,
						 bool value)
{
  this->_mesh->setMaterialFlag(flag, value);
}

void bbman::Pillar::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  static_cast<void>(delta);
}

void bbman::Pillar::addAnimation(irr::scene::ISceneNodeAnimator *anim)
{
  this->_mesh->addAnimator(anim);
  anim->drop();
}

void bbman::Pillar::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::Pillar::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::Pillar::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
}

bool bbman::Pillar::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::Pillar::explode(Board *board)
{
  (void)board;
}

void bbman::Pillar::playExplosion(void)
{

}

void bbman::Pillar::setColor(std::string const& color)
{
  this->_color = color;
}

std::string const& bbman::Pillar::getColor(void) const
{
  return (this->_color);
}

irr::core::vector3d<irr::s32> const& bbman::Pillar::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

bool bbman::Pillar::hasExplosed(void) const
{
  return (true);
}

bbman::ItemID bbman::Pillar::getID(void) const
{
  return (ItemID::II_BLOCK_INBRKABLE);
}
