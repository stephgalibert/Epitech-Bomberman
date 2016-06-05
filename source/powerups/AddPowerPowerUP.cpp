//
// AddPowerPowerUP.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:07:59 2016 avelin_j
// Last update Sun Jun  5 13:24:06 2016 stephane galibert
//

#include "AddPowerPowerUP.hpp"

bbman::AddPowerPowerUP::AddPowerPowerUP(void)
{
  this->_mesh = NULL;
  this->_delta = 0;
}

bbman::AddPowerPowerUP::~AddPowerPowerUP(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::AddPowerPowerUP::init(Irrlicht &irr, std::string const& color)
{
  (void)color;
  irr::scene::ISceneNodeAnimator *anms = NULL;
  std::string obj = "./asset/powerup/powerUpP.obj";
  std::string txt1 = "./asset/pillier/Texture_pillier_Selfillum_Orange.png";
  std::string txt2 = "./asset/pillier/Texture_pillier_alpha_Orange.png";

  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(obj.c_str()));
  if (this->_mesh) {
    this->_mesh->setMaterialTexture(0, irr.getTexture(txt1.data()));
    this->_mesh->setMaterialTexture(1, irr.getTexture(txt2.data()));

    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->_mesh->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
    this->_mesh->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    this->_mesh->setRotation(irr::core::vector3df(130, 0, 0));

    anms = irr.getSmgr()->createRotationAnimator(irr::core::vector3df(0, 1, 0));
    if (anms) {
      this->_mesh->addAnimator(anms);
      anms->drop();
    }
  }
  else {
    throw (std::runtime_error("cannot add IndestructibleBlock"));
  }
}

void bbman::AddPowerPowerUP::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  this->_delta += delta;
}

void bbman::AddPowerPowerUP::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::AddPowerPowerUP::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::AddPowerPowerUP::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
}

bool bbman::AddPowerPowerUP::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::AddPowerPowerUP::explode(Board *board)
{
  (void)board;
}

void bbman::AddPowerPowerUP::playExplosion(void)
{

}

irr::core::vector3d<irr::s32> const& bbman::AddPowerPowerUP::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

void bbman::AddPowerPowerUP::affectPlayer(APlayer *player)
{
  if (player) {
    player->addEffect(new AddPowerEffect(player));
  }
}

bool bbman::AddPowerPowerUP::hasExplosed(void) const
{
  return (true);
}

std::string const& bbman::AddPowerPowerUP::getColor(void) const
{
  return (this->_color);
}

void bbman::AddPowerPowerUP::setColor(std::string const& color)
{
  this->_color = color;
}

irr::scene::IMeshSceneNode const *bbman::AddPowerPowerUP::testGetMesh(void) const
{
  return (this->_mesh);
}

irr::f32 bbman::AddPowerPowerUP::testGetDelta(void) const
{
  return (this->_delta);
}
