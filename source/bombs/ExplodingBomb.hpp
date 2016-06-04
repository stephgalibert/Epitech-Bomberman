//
// ExplodingBomb.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:59:06 2016 avelin_j
// Last update Sat Jun  4 23:59:07 2016 avelin_j
//

#ifndef _EXPLODINGBOMB_HPP_
# define _EXPLODINGBOMB_HPP_

# include <iostream>
# include <stdexcept>

# include "SoundBox.hpp"
# include "IBomb.hpp"
# include "APlayer.hpp"
# include "CacheManager.hpp"
# include "MemoryFile.hpp"
# include "StaticTools.hpp"
# include "Explosion.hpp"
# include "Beam.hpp"

namespace bbman
{
  class ExplodingBomb : public IBomb
  {
  public:
    static const irr::f32 constexpr DELAY_TO_EXPLOSE = 3.f;
    static const irr::f32 constexpr DELAY_EXPLOSING = 0.5f;
  public:
    ExplodingBomb(APlayer *owner);
    virtual ~ExplodingBomb(void);
    virtual void init(Irrlicht &irr, std::string const& color = "");
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual bool isInExplosion(IEntity *entity, irr::core::vector3df const& scale);
    virtual bool isInDeflagration(IEntity *entity, irr::core::vector3df const& scale);
    virtual IBomb *clone(void) const;
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual std::string getName(void) const;
    virtual bool isExplosing(void) const;
    virtual bool hasExplosed(void) const;
    virtual void setExplosed(bool value);
    virtual bool isExploding(void) const;
    virtual irr::f32 getDelay(void) const;
    virtual irr::f32 getDelta(void) const;
    virtual void setDelta(irr::f32 value);
    virtual void explode(Board *board);
    virtual void playExplosion(void);
    virtual irr::core::vector3d<irr::s32> const& getPosInMap(irr::core::vector3df const& scale);
    virtual size_t getOwnerID(void) const;
    virtual size_t getBombID(void) const;
    virtual size_t getRange(void) const;
    virtual void addRange(size_t n);
    virtual std::string const& getColor(void) const;
    virtual void setColor(std::string const& color);
    virtual void disableAnimation(void);
    virtual int getScoreValue(void) const;
    void setOwner(APlayer *owner);
    irr::scene::IMeshSceneNode const *testGetMesh(void) const;
    Explosion const *testGetExplosion(void) const;
    NorthernBeam const *testGetNorthernBeam(void) const;
    SouthernBeam const *testGetSouthernBeam(void) const;
    EasternBeam const *testGetEasternBeam(void) const;
    WesternBeam const *testGetWesternBeam(void) const;
    CenterBeam const *testGetCenterBeam(void) const;
    irr::f32 testGetDelta(void) const;
    irr::s32 testGetCpt(void) const;
  private:
    static CacheManager<std::string, MemoryFile> SoundCache;
  private:
    void initMesh(Irrlicht &irr);
    void initSound(void);
    void setExplosion(Irrlicht &irr);
    irr::scene::IMeshSceneNode *_mesh;
    Explosion *_explosion;
    NorthernBeam *_nbeam;
    SouthernBeam *_sbeam;
    EasternBeam *_ebeam;
    WesternBeam *_wbeam;
    CenterBeam *_cbeam;
    APlayer *_owner;
    irr::f32 _delta;
    bool _explosing;
    bool _explosed;
    SoundBox _sounds;
    irr::core::vector3d<irr::s32> _posInMap;
    irr::s32 _cpt;
    std::string _color;
    size_t _range;
    //bool _lol;
    bool _anim;
  };
}

#endif /* !_EXPLODINGBOMB_HPP_ */
