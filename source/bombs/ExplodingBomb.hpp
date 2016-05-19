//
// ExplodingBomb.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 17:08:37 2016 stephane galibert
// Last update Thu May 19 14:59:05 2016 stephane galibert
//

#ifndef _EXPLODINGBOMB_HPP_
# define _EXPLODINGBOMB_HPP_

# include <iostream>
# include <stdexcept>

# include "SoundBox.hpp"
# include "IBomb.hpp"
# include "IPlayer.hpp"
# include "CacheManager.hpp"
# include "MemoryFile.hpp"

namespace bbman
{
  class ExplodingBomb : public IBomb
  {
  public:
    static const irr::f32 constexpr DELAY_TO_EXPLOSE = 3.f;
    static const irr::f32 constexpr DELAY_EXPLOSING = 1.f;
    static CacheManager<std::string, MemoryFile> SoundCache;
  public:
    ExplodingBomb(IPlayer *owner);
    virtual ~ExplodingBomb(void);
    virtual void init(Irrlicht &irr);
    virtual void update(Irrlicht &irr, irr::f32 delta);
    virtual IBomb *clone(void) const;
    virtual void setPosition(irr::core::vector3df const& pos);
    virtual irr::core::vector3df const& getPosition(void) const;
    virtual irr::core::aabbox3df const getBoundingBox(void) const;
    virtual bool isColliding(irr::core::aabbox3df const& box) const;
    virtual void playSound(std::string const& sound);
    virtual std::string getName(void) const;
    virtual bool isExplosing(void) const;
    virtual bool hasExplosed(void) const;
    virtual irr::f32 getDelay(void) const;
    virtual irr::f32 getDelta(void) const;
  private:
    void initMesh(Irrlicht &irr);
    //void initSound(void);
    void setExplosion(Irrlicht &irr);
    irr::scene::IAnimatedMeshSceneNode *_mesh;
    IPlayer *_owner;
    irr::f32 _delta;
    bool _explosing;
    bool _explosed;
    SoundBox _sounds;
  };
}

#endif /* !_EXPLODINGBOMB_HPP_ */
