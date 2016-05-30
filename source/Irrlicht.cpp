//
// Irrlicht.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:24:07 2016 stephane galibert
// Last update Mon May 30 20:25:14 2016 stephane galibert
//

#include "Irrlicht.hpp"

bbman::Irrlicht::Irrlicht(void)
{
  this->_irr.device = NULL;
  this->_irr.driver = NULL;
  this->_irr.smgr = NULL;
  this->_irr.guienv = NULL;
  this->_loader = NULL;
}

bbman::Irrlicht::~Irrlicht(void)
{
  if (this->_loader) {
    delete (this->_loader);
  }
  if (this->_irr.device) {
    this->_irr.device->drop();
  }
}

void bbman::Irrlicht::init(irr::video::E_DRIVER_TYPE dType,
			   irr::core::dimension2d<irr::u32> const& dim,
			   InputListener &inputListener)
{
  if (dType >= irr::video::EDT_COUNT) {
    throw (std::runtime_error("video driver not found"));
  }
  irr::SIrrlichtCreationParameters params;
  params.DriverType = dType;
  params.WindowSize = dim;
  params.AntiAlias = 16;
  params.Vsync = true;
  //params.Fullscreen = true;
  params.EventReceiver = &inputListener;
  params.Doublebuffer = true;
  this->_irr.device = createDeviceEx(params);
  if (this->_irr.device == NULL) {
    throw (std::runtime_error("could not create selected driver"));
  }
  this->_irr.driver = this->_irr.device->getVideoDriver();
  this->_irr.smgr = this->_irr.device->getSceneManager();
  this->_irr.guienv = this->_irr.device->getGUIEnvironment();
  this->_timer = this->_irr.device->getTimer();
  this->_loader = new IrrAssimp(this->_irr.smgr);
}

bool bbman::Irrlicht::isRunning(void)
{
  bool isRunning = false;
  if (this->_irr.device)
    isRunning = this->_irr.device->run();
  return (isRunning);

}


void bbman::Irrlicht::beginScene(void)
{
  this->_irr.driver->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));
}

void bbman::Irrlicht::drawScene(void)
{
  this->_irr.smgr->drawAll();
}

void bbman::Irrlicht::drawGUI(void)
{
  this->_irr.guienv->drawAll();
}

void bbman::Irrlicht::endScene(void)
{
  this->_irr.driver->endScene();
}

irr::video::ITexture *bbman::Irrlicht::getTexture(irr::io::path const& path) const
{
  return (this->_irr.driver->getTexture(path));
}

irr::scene::IAnimatedMesh *bbman::Irrlicht::getMesh(irr::io::path const& path) const
{
  if (this->_loader && this->_loader->isLoadable(path)) {
    return (this->_loader->getMesh(path));
  }
  return (this->_irr.smgr->getMesh(path));
}

irr::IrrlichtDevice *bbman::Irrlicht::getDevice(void) const
{
  return (this->_irr.device);
}

irr::video::IVideoDriver *bbman::Irrlicht::getDriver(void) const
{
  return (this->_irr.driver);
}

irr::scene::ISceneManager *bbman::Irrlicht::getSmgr(void) const
{
  return (this->_irr.smgr);
}

irr::gui::IGUIEnvironment *bbman::Irrlicht::getGUIEnv(void) const
{
  return (this->_irr.guienv);
}

irr::ITimer *bbman::Irrlicht::getTimer(void) const
{
  return (this->_timer);
}
