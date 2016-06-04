//
// TimeOut.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 28 08:15:00 2016 stephane galibert
// Last update Sat Jun  4 22:22:00 2016 stephane galibert
//

#ifndef _TIMEOUT_HPP_
# define _TIMEOUT_HPP_

# include <irrlicht.h>

# include "Irrlicht.hpp"
# include "Board.hpp"
# include "MemoryFile.hpp"
# include "CacheManager.hpp"
# include "SoundBox.hpp"
# include "Direction.hpp"

namespace bbman
{
  class TimeOut
  {
  public:
    static const size_t constexpr Release = 60.f;
    static const size_t constexpr ReleaseStep = 10.f;
  public:
    TimeOut(void);
    ~TimeOut(void);
    void init(Irrlicht &irr, Board *board);
    void update(Irrlicht &irr, irr::f32 delta);
    irr::f32 getDelta(void) const;
    void setDelta(irr::f32 delta);
    void setStep(int step);
    void setDeltaAnim(irr::f32 delta);
    irr::f32 getDeltaAnim(void) const;
    int getStep(void) const;
    void setDirection(Direction dir);
    Direction getDirection(void) const;
    void setBegin(irr::core::vector3d<irr::u32> const& v);
    irr::core::vector3d<irr::u32> const& getBegin(void) const;
    void setCurrent(irr::core::vector3d<irr::u32> const& v);
    irr::core::vector3d<irr::u32> const& getCurrent(void) const;
  private:
    void updateAnim(void);
    void narrowBoard(Irrlicht &irr);
    void putBlock(Irrlicht &irr);
    void north(Irrlicht &irr);
    void south(Irrlicht &irr);
    void east(Irrlicht &irr);
    void west(Irrlicht &irr);
    irr::f32 _delta;
    irr::f32 _deltaAnim;
    Board *_board;
    irr::core::vector3d<irr::u32> _begin;
    irr::core::vector3d<irr::u32> _current;
    std::list<std::pair<IBlock *, irr::scene::ISceneNodeAnimator *> > _anims;
    size_t _step;
    Direction _direction;
  };

  inline std::ostream &operator<<(std::ostream &flux, TimeOut const& obj)
  {
    irr::core::vector3d<irr::u32> const& b = obj.getBegin();
    irr::core::vector3d<irr::u32> const& c = obj.getCurrent();
    flux << "delta:" << obj.getDelta() << ";"
	 << "deltaanim:" << obj.getDeltaAnim() << ";"
	 << "step:" << obj.getStep() << ";"
	 << "dir:" << (int)obj.getDirection() << ";"
	 << "begin:" << b.X << " " << b.Z << ";"
	 << "current:" << c.X << " " << c.Z << ";"
	 << std::endl;
    return (flux);
  }
}

#endif /* !_TIMEOUT_HPP_ */
