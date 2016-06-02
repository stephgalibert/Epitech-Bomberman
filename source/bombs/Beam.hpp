//
// Beam.hpp for indie in /home/galibe_s/rendu/bomberman/source/bombs
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May 31 20:43:06 2016 stephane galibert
// Last update Thu Jun  2 12:11:25 2016 stephane galibert
//

#ifndef _BEAM_HPP_
# define _BEAM_HPP_

# include <irrlicht.h>

# include "Irrlicht.hpp"

namespace bbman
{
  class ABeam
  {
  public:
    ABeam(Irrlicht &irr, size_t range);
    virtual ~ABeam(void);
    virtual void init(Irrlicht &irr, std::string const& color) = 0;
    //virtual void setScale(irr::core::vector3df const& scale) = 0;
    virtual void play(void) = 0;
    void setRepeat(size_t n);
    void setPosition(irr::core::vector3df const& pos);
  protected:
    Irrlicht &_irr;
    bool _running;
    size_t _range;
    //irr::scene::IVolumeLightSceneNode *_vl;
    std::vector<irr::scene::IVolumeLightSceneNode *> _vls;
    //std::vector<irr::scene::ISceneNodeAnimator *> _glows;
    irr::core::vector3df _pos;
    size_t _repeat;
    irr::core::array<irr::video::ITexture *> _textures;
    //irr::scene::ISceneNodeAnimator* _glow;
  };

  class CenterBeam : public ABeam
  {
  public:
    CenterBeam(Irrlicht &irr, size_t range);
    virtual ~CenterBeam(void);
    virtual void init(Irrlicht &irr, std::string const& color);
    virtual void play(void);
  };

  class NorthernBeam : public ABeam
  {
  public:
    NorthernBeam(Irrlicht &irr, size_t range);
    virtual ~NorthernBeam(void);
    virtual void init(Irrlicht &irr, std::string const& color);
    virtual void play(void);
  };

  class SouthernBeam : public ABeam
  {
  public:
    SouthernBeam(Irrlicht &irr, size_t range);
    virtual ~SouthernBeam(void);
    virtual void init(Irrlicht &irr, std::string const& color);
    virtual void play(void);
  };

  class EasternBeam : public ABeam
  {
  public:
    EasternBeam(Irrlicht &irr, size_t range);
    virtual ~EasternBeam(void);
    virtual void init(Irrlicht &irr, std::string const& color);
    virtual void play(void);
  };

  class WesternBeam : public ABeam
  {
  public:
    WesternBeam(Irrlicht &irr, size_t range);
    virtual ~WesternBeam(void);
    virtual void init(Irrlicht &irr, std::string const& color);
    virtual void play(void);
  };
}

#endif /* !_BEAM_HPP_ */
