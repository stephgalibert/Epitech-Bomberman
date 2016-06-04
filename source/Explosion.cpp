//
// Explosion.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:37:07 2016 avelin_j
// Last update Sat Jun  4 23:37:09 2016 avelin_j
//

#include "Explosion.hpp"

bbman::Explosion::Explosion(void)
{
  this->_ps = NULL;
  this->_delta = 0;
  this->_hasFinished = false;
  this->_played = false;
}

bbman::Explosion::~Explosion(void)
{
  if (this->_ps) {
    this->_ps->remove();
    this->_ps = NULL;
  }
}

void bbman::Explosion::init(Irrlicht &irr, std::string const& color)
{
  std::string txt = "./asset/Particles/particle" + color + ".png";
  this->_color = color;
  this->_ps = irr.getSmgr()->addParticleSystemSceneNode(false);
  this->_ps->setMaterialTexture(0, irr.getTexture(txt.c_str()));
  this->_ps->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  this->_ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->_ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  this->_ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void bbman::Explosion::update(irr::f32 delta)
{
  if (this->_played) {
    this->_delta += delta;
    this->_hasFinished = (this->_delta > 0.4f);
  }
}

void bbman::Explosion::play(irr::core::vector3df const& pos)
{
  this->_played = true;
  this->_ps->setPosition(pos);
  irr::scene::IParticleEmitter* emitter =
    this->_ps->createSphereEmitter(irr::core::vector3df(0.0f,0.0f,0.0f),
				   0.5f,
				   irr::core::vector3df(0.0f,0.2f,0.0f),
				   10,30,
				   irr::video::SColor(0,127,127,127),
				   irr::video::SColor(0,255,255,255),
				   150,250,360,
				   irr::core::dimension2df(1.f,1.f),
				   irr::core::dimension2df(10.f,10.f));
  this->_ps->setEmitter(emitter);
  emitter->drop();
  irr::scene::IParticleAffector* gravityAffector =
    this->_ps->createGravityAffector(irr::core::vector3df(0.0f,-0.01f, 0.0f), 200);
  this->_ps->addAffector(gravityAffector);
  gravityAffector->drop();
  irr::scene::IParticleAffector* fadeOutAffector =
    this->_ps->createFadeOutParticleAffector(irr::video::SColor(0, 0, 0, 0), 200);
  this->_ps->addAffector(fadeOutAffector);
  fadeOutAffector->drop();
}

bool bbman::Explosion::hasFinished(void) const
{
  return (this->_hasFinished);
}

bool bbman::Explosion::testGetPlayed(void) const
{
  return (this->_played);
}

irr::scene::IParticleSystemSceneNode const *bbman::Explosion::testGetSystem(void) const
{
  return (this->_ps);
}

irr::f32 bbman::Explosion::testGetDelta(void) const
{
  return (this->_delta);
}
