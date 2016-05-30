//
// ExplodingBomb.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 18:11:12 2016 stephane galibert
// Last update Mon May 30 09:17:47 2016 stephane galibert
//

#include "ExplodingBomb.hpp"
#include "Board.hpp"

bbman::CacheManager<std::string, bbman::MemoryFile> bbman::ExplodingBomb::SoundCache;

bbman::ExplodingBomb::ExplodingBomb(bbman::APlayer *owner)
{
  this->_mesh = NULL;
  this->_owner = owner;
  this->_delta = 0;
  this->_explosing = false;
  this->_explosed = false;
  this->_cpt = 0;
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
    initMesh(irr);
    initSound();
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
    if (this->_explosing) {
      try {
	this->_sounds.play("explosion");
      } catch (std::runtime_error const& e) {
	std::cerr << e.what() << std::endl;
      }
    }
  }
  if (this->_explosing) {
    this->_explosed = !(this->_delta < DELAY_TO_EXPLOSE + DELAY_EXPLOSING);
    this->_mesh->setVisible(false);
    if (!this->_explosed) {
      this->_delta += delta;
    }
    ++this->_cpt;
  }
}

bool bbman::ExplodingBomb::isInExplosion(IEntity *entity, irr::core::vector3df const& scale)
{
  irr::core::vector3d<irr::s32> const& pos = entity->getPosInMap(scale);
  irr::core::vector3d<irr::s32> const& mypos = getPosInMap(scale);
  irr::s32 dist = tools::StaticTools::getDistance2D(pos, mypos);
  return (this->_cpt == 1 && dist < 4 && (pos.X == mypos.X || pos.Z == mypos.Z));
}

bool bbman::ExplodingBomb::isInDeflagration(IEntity *entity, irr::core::vector3df const& scale)
{
  irr::core::vector3d<irr::s32> const& pos = entity->getPosInMap(scale);
  irr::core::vector3d<irr::s32> const& mypos = getPosInMap(scale);
  irr::s32 dist = tools::StaticTools::getDistance2D(pos, mypos);
  return (this->_cpt > 1 && dist < 4 && (pos.X == mypos.X || pos.Z == mypos.Z));
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

bool bbman::ExplodingBomb::isExploding(void) const
{
  return (this->_cpt == 1);
}

void bbman::ExplodingBomb::initMesh(bbman::Irrlicht &irr)
{
  std::string txt = "./asset/media/ninja.b3d";

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

void bbman::ExplodingBomb::initSound(void)
{
  try {
    if (!SoundCache.find("explosion")) {
      SoundCache.insert("explosion", MemoryFile("./asset/sound/explosion.wav"));
      SoundCache["explosion"].load();
    }
  this->_sounds.addSample("explosion", SoundCache["explosion"]);
  this->_sounds.setVolumeBySample("explosion", 50.f);
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
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

void bbman::ExplodingBomb::setDelta(irr::f32 value)
{
  this->_delta = value;
}

void bbman::ExplodingBomb::explode(Board *board)
{
  this->_delta = DELAY_TO_EXPLOSE;
  APlayer *owner = board->getPlayerByID(getOwnerID());
  //explode(this);
  if (owner) {
    owner->addBomb(clone());
  }
}

irr::core::vector3d<irr::s32> const& bbman::ExplodingBomb::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return (this->_posInMap);
}

size_t bbman::ExplodingBomb::getOwnerID(void) const
{
  return (this->_owner->getID());
}

size_t bbman::ExplodingBomb::getBombID(void) const
{
  return (1);
}

size_t bbman::ExplodingBomb::getRange(void) const
{
  return (3);
}

void bbman::ExplodingBomb::setOwner(bbman::APlayer *owner)
{
  this->_owner = owner;
}
