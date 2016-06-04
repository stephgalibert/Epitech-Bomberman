//
// Beam.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:57:27 2016 avelin_j
// Last update Sat Jun  4 23:57:28 2016 avelin_j
//

#include "Beam.hpp"

bbman::ABeam::ABeam(Irrlicht &irr, size_t range)
  : _irr(irr)
{
  this->_running = false;
  this->_range = range;
  this->_repeat = 0;
}

bbman::ABeam::~ABeam(void)
{
  for (auto it : this->_vls) {
    it->remove();
  }
}

void bbman::ABeam::setRepeat(size_t n)
{
  this->_repeat = n;
}

void bbman::ABeam::setPosition(irr::core::vector3df const& pos)
{
  this->_pos = pos;
}

bool bbman::ABeam::testGetRunning(void) const
{
  return (this->_running);
}

size_t bbman::ABeam::testGetRange(void) const
{
  return (this->_range);
}

size_t bbman::ABeam::testGetRepeat(void) const
{
  return (this->_repeat);
}

bbman::CenterBeam::CenterBeam(Irrlicht &irr, size_t range)
  : ABeam(irr, range)
{

}

bbman::CenterBeam::~CenterBeam(void)
{

}

void bbman::CenterBeam::init(Irrlicht &irr, std::string const& color)
{
  for (irr::s32 g = 7 ; g > 0 ; --g) {
    irr::core::stringc tmp;
    tmp = "./asset/bomb/Bomb/bomb";
    tmp += color.c_str();
    tmp += g;
    tmp += ".png";
    this->_textures.push_back(irr.getTexture(tmp.c_str()));
  }
}

void bbman::CenterBeam::play(void)
{
  irr::scene::ISceneNodeAnimator *glow = NULL;
  irr::scene::IVolumeLightSceneNode *vl = NULL;

  if (!this->_running) {
    this->_running = true;

    vl = this->_irr.getSmgr()->addVolumeLightSceneNode(0, -1, 32, 32, irr::video::SColor(0, 255, 255, 255), irr::video::SColor(0, 0, 0, 0));

    glow = this->_irr.getSmgr()->createTextureAnimator(this->_textures, 70);
    irr::core::vector3df pos = this->_pos;
    vl->setPosition(pos);
    vl->setScale(irr::core::vector3df(10, 10, 10));
    vl->addAnimator(glow);
    glow->drop();
    this->_vls.push_back(vl);
  }
}


bbman::NorthernBeam::NorthernBeam(Irrlicht &irr, size_t range)
  : ABeam(irr, range)
{

}

bbman::NorthernBeam::~NorthernBeam(void)
{

}

void bbman::NorthernBeam::init(Irrlicht &irr, std::string const& color)
{
  for (irr::s32 g = 7 ; g > 0 ; --g) {
    irr::core::stringc tmp;
    tmp = "./asset/Beam/vbeam";
    tmp += color.c_str();
    tmp += g;
    tmp += ".png";
    this->_textures.push_back(irr.getTexture(tmp.c_str()));
  }
}

void bbman::NorthernBeam::play(void)
{
  irr::scene::ISceneNodeAnimator *glow = NULL;
  irr::scene::IVolumeLightSceneNode *vl = NULL;

  if (!this->_running) {
    this->_running = true;
    for (size_t i = 0 ; i < this->_repeat ; ++i)
      {
	vl = this->_irr.getSmgr()->addVolumeLightSceneNode(0, -1, 32, 32, irr::video::SColor(0, 255, 255, 255), irr::video::SColor(0, 0, 0, 0));
	glow = this->_irr.getSmgr()->createTextureAnimator(this->_textures, 70);
	irr::core::vector3df pos = this->_pos;
	pos.Z += (10 * (i + 1));
	vl->setPosition(pos);
	vl->setScale(irr::core::vector3df(10, 10, 10));
	vl->addAnimator(glow);
	glow->drop();
	this->_vls.push_back(vl);
      }
  }
}

bbman::SouthernBeam::SouthernBeam(Irrlicht &irr, size_t range)
  : ABeam(irr, range)
{

}

bbman::SouthernBeam::~SouthernBeam(void)
{

}

void bbman::SouthernBeam::init(Irrlicht &irr, std::string const& color)
{
  for (irr::s32 g = 7 ; g > 0 ; --g) {
    irr::core::stringc tmp;
    tmp = "./asset/Beam/vbeam";
    tmp += color.c_str();
    tmp += g;
    tmp += ".png";
    this->_textures.push_back(irr.getTexture(tmp.c_str()));
  }
}

void bbman::SouthernBeam::play(void)
{
  irr::scene::ISceneNodeAnimator *glow = NULL;
  irr::scene::IVolumeLightSceneNode *vl = NULL;

  if (!this->_running) {
    this->_running = true;
    for (size_t i = 0 ; i < this->_repeat ; ++i)
      {
	vl = this->_irr.getSmgr()->addVolumeLightSceneNode(0, -1, 32, 32, irr::video::SColor(0, 255, 255, 255), irr::video::SColor(0, 0, 0, 0));
	glow = this->_irr.getSmgr()->createTextureAnimator(this->_textures, 70);
	irr::core::vector3df pos = this->_pos;
	pos.Z -= (10 * (i + 1));
	vl->setPosition(pos);
	vl->setScale(irr::core::vector3df(10, 10, 10));
	vl->addAnimator(glow);
	glow->drop();
	this->_vls.push_back(vl);
      }
  }
}

bbman::EasternBeam::EasternBeam(Irrlicht &irr, size_t range)
  : ABeam(irr, range)
{

}

bbman::EasternBeam::~EasternBeam(void)
{

}

void bbman::EasternBeam::init(Irrlicht &irr, std::string const& color)
{
  for (irr::s32 g = 7 ; g > 0 ; --g) {
    irr::core::stringc tmp;
    tmp = "./asset/Beam/hbeam";
    tmp += color.c_str();
    tmp += g;
    tmp += ".png";
    this->_textures.push_back(irr.getTexture(tmp.c_str()));
  }
}

void bbman::EasternBeam::play(void)
{
  irr::scene::ISceneNodeAnimator *glow = NULL;
  irr::scene::IVolumeLightSceneNode *vl = NULL;

  if (!this->_running) {
    this->_running = true;
    for (size_t i = 0 ; i < this->_repeat ; ++i)
      {
	vl = this->_irr.getSmgr()->addVolumeLightSceneNode(0, -1, 32, 32, irr::video::SColor(0, 255, 255, 255), irr::video::SColor(0, 0, 0, 0));
	glow = this->_irr.getSmgr()->createTextureAnimator(this->_textures, 70);
	irr::core::vector3df pos = this->_pos;
	pos.X += (10 * (i + 1));
	vl->setPosition(pos);
	vl->setScale(irr::core::vector3df(10, 10, 10));
	vl->addAnimator(glow);
	glow->drop();
	this->_vls.push_back(vl);
      }
  }
}

bbman::WesternBeam::WesternBeam(Irrlicht &irr, size_t range)
  : ABeam(irr, range)
{

}

bbman::WesternBeam::~WesternBeam(void)
{

}

void bbman::WesternBeam::init(Irrlicht &irr, std::string const& color)
{
  for (irr::s32 g = 7 ; g > 0 ; --g) {
    irr::core::stringc tmp;
    tmp = "./asset/Beam/hbeam";
    tmp += color.c_str();
    tmp += g;
    tmp += ".png";
    this->_textures.push_back(irr.getTexture(tmp.c_str()));
  }
}

void bbman::WesternBeam::play(void)
{
  irr::scene::ISceneNodeAnimator *glow = NULL;
  irr::scene::IVolumeLightSceneNode *vl = NULL;

  if (!this->_running) {
    this->_running = true;
    for (size_t i = 0 ; i < this->_repeat ; ++i)
      {
	vl = this->_irr.getSmgr()->addVolumeLightSceneNode(0, -1, 32, 32, irr::video::SColor(0, 255, 255, 255), irr::video::SColor(0, 0, 0, 0));
	glow = this->_irr.getSmgr()->createTextureAnimator(this->_textures, 70);
	irr::core::vector3df pos = this->_pos;
	pos.X -= (10 * (i + 1));
	vl->setPosition(pos);
	vl->setScale(irr::core::vector3df(10, 10, 10));
	vl->addAnimator(glow);
	glow->drop();
	this->_vls.push_back(vl);
      }
  }
}
