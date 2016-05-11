//
// IrrlichtComponent.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/examples/04.Movement
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May  3 03:06:43 2016 stephane galibert
// Last update Wed May  4 22:39:54 2016 stephane galibert
//

#ifndef _IRRLICHT_COMPONENT_HPP_
# define _IRRLICHT_COMPONENT_HPP_

# include <irrlicht.h>

namespace bbman
{
  struct IrrlichtComponent
  {
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver *driver;
    irr::scene::ISceneManager *smgr;
    irr::gui::IGUIEnvironment *guienv;
  };
}

#endif /* _IRRLICHT_COMPONENT_HPP_ */
