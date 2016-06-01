//
// AddExplosingBombPowerUp.cpp for inde in /home/galibe_s/rendu/bomberman/source/powerups
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun May 29 10:09:35 2016 stephane galibert
// Last update Wed Jun  1 20:26:20 2016 stephane galibert
//

#include "AddExplosingBombPowerUP.hpp"

bbman::AddExplosingBombPowerUP::AddExplosingBombPowerUP(void)
{
  this->_mesh = NULL;
  this->_delta = 0;
}

bbman::AddExplosingBombPowerUP::~AddExplosingBombPowerUP(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
}

void bbman::AddExplosingBombPowerUP::init(Irrlicht &irr, std::string const& color)
{
  irr::scene::ISceneNodeAnimator *anms = NULL;
  (void)color;
  std::string obj = "./asset/powerup/powerUpBomb.obj";
  std::string txt1 = "./asset/bomb/Texture_pillier_Selfillum_Blue.png";
  std::string txt2 = "./asset/bomb/Texture_pillier_alpha_Blue.png";
  //std::string txt3 = "./asset/bomb2_normals.png";

  //this->_mesh = irr.getSmgr()->addCubeSceneNode();
  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(obj.c_str()));
  if (this->_mesh) {
    this->_mesh->setMaterialTexture(0, irr.getTexture(txt1.data()));
    this->_mesh->setMaterialTexture(1, irr.getTexture(txt2.data()));

    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->_mesh->setScale(irr::core::vector3df(0.7f, 0.7f, 0.7f));
    this->_mesh->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    this->_mesh->setRotation(irr::core::vector3df(-40, 0, 0));

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

void bbman::AddExplosingBombPowerUP::update(Irrlicht &irr, irr::f32 delta)
{
  (void)irr;
  this->_delta += delta;
}

void bbman::AddExplosingBombPowerUP::setPosition(irr::core::vector3df const& pos)
{
  this->_mesh->setPosition(pos);
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::AddExplosingBombPowerUP::getPosition(void) const
{
  return (this->_mesh->getPosition());
}

irr::core::aabbox3df const bbman::AddExplosingBombPowerUP::getBoundingBox(void) const
{
  return (this->_mesh->getTransformedBoundingBox());
}

bool bbman::AddExplosingBombPowerUP::isColliding(irr::core::aabbox3df const& box) const
{
  return (box.intersectsWithBox(this->getBoundingBox()));
}

void bbman::AddExplosingBombPowerUP::explode(Board *board)
{
  (void)board;
}

void bbman::AddExplosingBombPowerUP::playExplosion(void)
{

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

std::string const& bbman::AddExplosingBombPowerUP::getColor(void) const
{
  return (this->_color);
}

void bbman::AddExplosingBombPowerUP::setColor(std::string const& color)
{
  this->_color = color;
}
