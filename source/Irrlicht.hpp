//
// Irrlicht.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/examples/04.Movement
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May  3 03:29:01 2016 stephane galibert
// Last update Mon May 30 22:12:26 2016 stephane galibert
//

#ifndef _IRRLICHT_HPP_
# define _IRRLICHT_HPP_

# ifdef _MSC_VER
#  define _CRT_SECURE_NO_WARNINGS
#  pragma comment(lib, "Irrlicht.lib")
# endif

# include <irrlicht.h>
# include <stdexcept>
# include <iostream>

# include "IrrAssimp.h"
# include "IrrlichtComponent.hpp"
# include "InputListener.hpp"

namespace bbman
{
  class Irrlicht
  {
  public:
    Irrlicht(void);
    ~Irrlicht(void);
    void init(irr::video::E_DRIVER_TYPE dType,
	      irr::core::dimension2d<irr::u32> const& dim,
	      InputListener &inputListener);
    bool isRunning(void);
    void beginScene(void);
    void drawScene(void);
    void drawGUI(void);
    void endScene(void);
    void close(void);
    irr::video::ITexture *getTexture(irr::io::path const& path) const;
    irr::scene::IAnimatedMesh *getMesh(irr::io::path const& path) const;
    irr::IrrlichtDevice *getDevice(void) const;
    irr::video::IVideoDriver *getDriver(void) const;
    irr::scene::ISceneManager *getSmgr(void) const;
    irr::gui::IGUIEnvironment *getGUIEnv(void) const;
    irr::ITimer *getTimer(void) const;
  private:
    irr::ITimer *_timer;
    IrrlichtComponent _irr;
    IrrAssimp *_loader;
  };
}

#endif /* !_IRRLICHT_HPP_ */
