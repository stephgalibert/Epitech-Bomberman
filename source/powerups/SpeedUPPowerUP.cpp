//
// SpeedUPPowerUP.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Jun  5 00:11:00 2016 avelin_j
// Last update Sun Jun  5 00:11:02 2016 avelin_j
//

#include "SpeedUPPowerUP.hpp"

bbman::SpeedUPPowerUP::SpeedUPPowerUP(void)
{
  //this->_node = NULL;
  this->_mesh = NULL;
  this->_delta = 0;
}

bbman::SpeedUPPowerUP::~SpeedUPPowerUP(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::SpeedUPPowerUP::init(Irrlicht &irr, std::string const& color)
{
  irr::scene::ISceneNodeAnimator *anms = NULL;
  std::string obj = "./asset/powerup/powerUpSpeed.obj";
  std::string txt = "./asset/pillier/Texture_pillier_Green.png";
  std::string txt1 = "./asset/pillier/Texture_pillier_Selfillum_Green.png";
  std::string txt2 = "./asset/pillier/Texture_pillier_alpha_Green.png";
  //std::string txt3 = "./asset/bomb2_normals.png";

  (void)color;
  //this->_mesh = irr.getSmgr()->addCubeSceneNode();
  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(obj.c_str()));
  if (this->_mesh) {

    this->_mesh->setMaterialTexture(0, irr.getTexture(txt1.data()));
    this->_mesh->setMaterialTexture(1, irr.getTexture(txt2.data()));

    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->_mesh->setScale(irr::core::vector3df(0.5f, 0.5f, 0.5f));
    this->_mesh->setRotation(irr::core::vector3df(-40, 0, 0));

    this->_mesh->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    //this->_mesh->setMaterialType(irr::video::EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR);

    anms = irr.getSmgr()->createRotationAnimator(irr::core::vector3df(0, 1, 0));
    if (anms) {
      this->_mesh->addAnimator(anms);
      anms->drop();
    }
  }
  else {
    std::cerr << "cannot create speeduppowerup" << std::endl;
  }
}

void bbman::SpeedUPPowerUP::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  this->_delta += delta;
}

void bbman::SpeedUPPowerUP::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::SpeedUPPowerUP::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::SpeedUPPowerUP::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
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

irr::scene::IMeshSceneNode const *bbman::SpeedUPPowerUP::testGetMesh(void) const
{
  return (this->_mesh);
}

irr::f32 bbman::SpeedUPPowerUP::testGetDelta(void) const
{
  return (this->_delta);
}
