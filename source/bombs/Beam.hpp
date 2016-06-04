//
// Beam.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:57:20 2016 avelin_j
// Last update Sat Jun  4 23:57:21 2016 avelin_j
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
    virtual void play(void) = 0;
    void setRepeat(size_t n);
    void setPosition(irr::core::vector3df const& pos);
    bool testGetRunning(void) const;
    size_t testGetRange(void) const;
    size_t testGetRepeat(void) const;
  protected:
    Irrlicht &_irr;
    bool _running;
    size_t _range;
    std::vector<irr::scene::IVolumeLightSceneNode *> _vls;
    irr::core::vector3df _pos;
    size_t _repeat;
    irr::core::array<irr::video::ITexture *> _textures;
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
