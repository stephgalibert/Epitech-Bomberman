//
// Explosion.hpp for indie in /home/galibe_s/rendu/bomberman/source/thread
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May 31 14:19:18 2016 stephane galibert
// Last update Tue May 31 14:42:36 2016 stephane galibert
//

#ifndef _EXPLOSION_HPP_
# define _EXPLOSION_HPP_

# include <irrlicht.h>

# include "Irrlicht.hpp"

namespace bbman
{
  class Explosion
  {
  public:
    Explosion(void);
    ~Explosion(void);
    void init(Irrlicht &irr);
    void update(irr::f32 delta);
    void play(irr::core::vector3df const& pos);
    bool hasFinished(void) const;
  private:
    irr::scene::IParticleSystemSceneNode *_ps;
    irr::f32 _delta;
    bool _hasFinished;
    bool _played;
  };
}

#endif /* !_EXPLOSION_HPP_ */
