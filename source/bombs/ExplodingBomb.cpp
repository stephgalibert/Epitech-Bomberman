//
// ExplodingBomb.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 18:11:12 2016 stephane galibert
// Last update Sat Jun  4 01:32:52 2016 stephane galibert
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
  this->_explosion = NULL;
  this->_nbeam = NULL;
  this->_sbeam = NULL;
  this->_ebeam = NULL;
  this->_wbeam = NULL;
  this->_cbeam = NULL;
  this->_range = 3;
  //this->_lol = false;
  this->_anim = true;
}

bbman::ExplodingBomb::~ExplodingBomb(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }
  if (this->_nbeam) {
    delete (this->_nbeam);
  }
  if (this->_sbeam) {
    delete (this->_sbeam);
  }
  if (this->_ebeam) {
    delete (this->_ebeam);
  }
  if (this->_wbeam) {
    delete (this->_wbeam);
  }
  if (this->_cbeam) {
    delete (this->_cbeam);
  }
  if (this->_explosion) {
    delete (this->_explosion);
  }
}

void bbman::ExplodingBomb::init(bbman::Irrlicht &irr, std::string const& color)
{
  try {
    this->_color = color;
    initMesh(irr);
    initSound();
    this->_explosion = new Explosion;
    this->_explosion->init(irr, color);
    this->_nbeam = new NorthernBeam(irr, getRange());
    this->_nbeam->init(irr, color);
    this->_sbeam = new SouthernBeam(irr, getRange());
    this->_sbeam->init(irr, color);
    this->_ebeam = new EasternBeam(irr, getRange());
    this->_ebeam->init(irr, color);
    this->_wbeam = new WesternBeam(irr, getRange());
    this->_wbeam->init(irr, color);
    this->_cbeam = new CenterBeam(irr, getRange());
    this->_cbeam->init(irr, color);
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
  if (this->_explosion) {
    this->_explosion->update(delta);
    if (this->_explosion->hasFinished()) {
      delete (this->_explosion);
      this->_explosion = NULL;
    }
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
  IBomb *bomb = new ExplodingBomb(this->_owner);
  bomb->setColor(this->_color);
  return (bomb);
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

void bbman::ExplodingBomb::setExplosed(bool value)
{
  if (value)
    this->_delta = DELAY_TO_EXPLOSE;
  this->_explosed = value;
}

bool bbman::ExplodingBomb::isExploding(void) const
{
  return (this->_cpt == 1);
}

void bbman::ExplodingBomb::initMesh(bbman::Irrlicht &irr)
{
  std::string txt = "./asset/bomb/bomb.obj";
  std::string txtobj = "./asset/pillier/Texture_pillier_" + this->_color + ".png";
  //std::string light = "./asset/pillier/Texture_pillier_Selfillum_" + _color + ".png";
  //std::string alpha = "./asset/pillier/Texture_pillier_alpha_" + this->_color + ".png";

  this->_mesh = irr.getSmgr()->addMeshSceneNode(irr.getMesh(txt.data()));
  if (this->_mesh) {
    this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_mesh->setMaterialTexture(0, irr.getTexture(txtobj.data()));
    //this->_mesh->setMaterialTexture(1, irr.getTexture(light.data()));
    //this->_mesh->setMaterialTexture(2, irr.getTexture(alpha.data()));
    //this->_mesh->setMaterialTexture(2, irr.getTexture(alpha.data()));
    this->_mesh->setScale(irr::core::vector3df(1.8f, 1.8f, 1.8f));

    //this->_mesh->setMaterialType(irr::video::EMT_LIGHTMAP_ADD);
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
  this->_sounds.setVolumeBySample("explosion", tools::StaticTools::volume("effect"));
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
  int i = 0;
  irr::core::vector3df const& scale = board->getScale();
  irr::core::vector3d<irr::s32> const& pos = getPosInMap(scale);
  Map<Cell> const& map = board->getMap();

  if (this->_cbeam) {
    this->_cbeam->setPosition(getPosition());
  }
  if (this->_nbeam) {
    while (i < this->_range && pos.Z + i < map.h - 1
	   && map.at(pos.X, pos.Z + i).id == ItemID::II_NONE) {
      ++i;
    }
    if (map.at(pos.X, pos.Z + i).id == ItemID::II_BLOCK_INBRKABLE) {
      --i;
    }
    this->_nbeam->setRepeat(i);
    this->_nbeam->setPosition(getPosition());
  }

  i = 0;
  if (this->_sbeam) {
    while (i < this->_range && pos.Z - i > 1
	   && map.at(pos.X, pos.Z - i).id == ItemID::II_NONE) {
      ++i;
    }
    if (map.at(pos.X, pos.Z - i).id == ItemID::II_BLOCK_INBRKABLE) {
      --i;
    }
    this->_sbeam->setRepeat(i);
    this->_sbeam->setPosition(getPosition());
  }

  i = 0;
  if (this->_ebeam) {
    while (i < this->_range && pos.X + i < map.w - 1
	   && map.at(pos.X + i, pos.Z).id == ItemID::II_NONE) {
      ++i;
    }
    if (map.at(pos.X + i, pos.Z).id == ItemID::II_BLOCK_INBRKABLE) {
      --i;
    }
    this->_ebeam->setRepeat(i);
    this->_ebeam->setPosition(getPosition());
  }

  i = 0;
  if (this->_wbeam) {
    while (i < this->_range && pos.X - i > 1
	   && map.at(pos.X - i, pos.Z).id == ItemID::II_NONE) {
      ++i;
    }
    if (map.at(pos.X - i, pos.Z).id == ItemID::II_BLOCK_INBRKABLE) {
      --i;
    }
    this->_wbeam->setRepeat(i);
    this->_wbeam->setPosition(getPosition());
  }
  this->_delta = DELAY_TO_EXPLOSE;
}

/*void bbman::ExplodingBomb::setLol(bool value)
{
  this->_lol = value;
  }*/

void bbman::ExplodingBomb::playExplosion(void)
{
  if (!this->_anim)
    return;

  if (this->_explosion) {
    this->_explosion->play(getPosition());
  }
  if (this->_cbeam) {
    this->_cbeam->play();
  }
  if (this->_nbeam) {
    this->_nbeam->play();
  }
  if (this->_sbeam) {
    this->_sbeam->play();
  }
  if (this->_ebeam) {
    this->_ebeam->play();
  }
  if (this->_wbeam) {
    this->_wbeam->play();
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
  return (this->_range);
}

void bbman::ExplodingBomb::addRange(size_t n)
{
  this->_range += n;
}

void bbman::ExplodingBomb::setOwner(bbman::APlayer *owner)
{
  this->_owner = owner;
}

std::string const& bbman::ExplodingBomb::getColor(void) const
{
  return (this->_color);
}

void bbman::ExplodingBomb::setColor(std::string const& color)
{
  this->_color = color;
}

/*bool bbman::ExplodingBomb::getLol(void) const
{
  return (this->_lol);
  }*/

void bbman::ExplodingBomb::disableAnimation(void)
{
  this->_anim = false;
}
