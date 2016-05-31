//
// ExplosionTask.cpp for indie in /home/galibe_s/rendu/bomberman/source/thread
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 30 16:29:33 2016 stephane galibert
// Last update Tue May 31 12:53:32 2016 stephane galibert
//

#include "ExplosionTask.hpp"

bbman::ExplosionTask::ExplosionTask(Irrlicht &irr)
{
  this->_ps = irr.getSmgr()->addParticleSystemSceneNode(false);
  this->_ps->setMaterialTexture(0, irr.getTexture("./asset/media/fire.bmp"));
  this->_ps->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  this->_ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->_ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  this->_ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
  this->_isRunning = false;
  this->_isFinished = true;
  this->_timer.setTimer(irr.getTimer());
}

bbman::ExplosionTask::~ExplosionTask(void)
{
  this->_ps->remove();
  this->_ps = NULL;
}

void bbman::ExplosionTask::start(void)
{
  this->_isRunning = true;
  this->_isFinished = false;

  this->_ps->setPosition(this->_pos);
  irr::scene::IParticleEmitter* emitter =
    this->_ps->createSphereEmitter(irr::core::vector3df(0.0f,0.0f,0.0f),
				   0.5f,
				   irr::core::vector3df(0.0f,0.1f,0.0f),
				   120,150,
				   irr::video::SColor(0,127,127,127),
				   irr::video::SColor(0,255,255,255),
				   150,150,360,
				   irr::core::dimension2df(1.f,1.f),
				   irr::core::dimension2df(10.f,10.f));

  this->_ps->setEmitter(emitter);
  emitter->drop();

  irr::scene::IParticleAffector* gravityAffector =
    this->_ps->createGravityAffector(irr::core::vector3df(0.0f,-0.03f, 0.0f), 300);
  this->_ps->addAffector(gravityAffector);
  gravityAffector->drop();
  irr::scene::IParticleAffector* fadeOutAffector =
    this->_ps->createFadeOutParticleAffector(irr::video::SColor(0, 0, 0, 0), 100);
  this->_ps->addAffector(fadeOutAffector);
  fadeOutAffector->drop();

  this->_timer.start();
  while (this->_isRunning && this->_timer.getElapsedTime() < 100.f);
}

void bbman::ExplosionTask::stop(void)
{
  this->_isRunning = false;
}

void bbman::ExplosionTask::setFinished(bool v)
{
  this->_isFinished = v;
}

bool bbman::ExplosionTask::isFinished(void) const
{
  return (this->_isFinished);
}

bool bbman::ExplosionTask::isRunning(void) const
{
  return (this->_isRunning);
}

void bbman::ExplosionTask::setPosition(irr::core::vector3df const& pos)
{
  this->_pos = pos;
}
