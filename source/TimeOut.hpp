//
// TimeOut.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 28 08:15:00 2016 stephane galibert
// Last update Sat May 28 17:56:35 2016 stephane galibert
//

#ifndef _TIMEOUT_HPP_
# define _TIMEOUT_HPP_

# include <irrlicht.h>

# include "ThreadPool.hpp"
# include "Irrlicht.hpp"
# include "Loader.hpp"
# include "Board.hpp"
# include "MemoryFile.hpp"
# include "CacheManager.hpp"
# include "SoundBox.hpp"

namespace bbman
{
  class TimeOut
  {
  public:
    TimeOut(void);
    ~TimeOut(void);
    void init(Irrlicht &irr, Board *board);
    void init(Irrlicht &irr, Board *board, Loader const& loader);
    void update(ThreadPool *pool, Irrlicht &irr, irr::f32 delta);
    irr::f32 getDelta(void) const;
    void setDelta(irr::f32 delta);
  private:
    static CacheManager<std::string, MemoryFile> SoundCache;
  private:
    void narrowBoard(Irrlicht &irr);
    void putBlock(Irrlicht &irr);
    void north(Irrlicht &irr);
    void south(Irrlicht &irr);
    void east(Irrlicht &irr);
    void west(Irrlicht &irr);
    SoundBox _sounds;
    irr::f32 _delta;
    irr::f32 _deltaAnim;
    Board *_board;
    irr::core::vector3d<irr::s32> _begin;
    irr::core::vector3d<irr::s32> _current;
    int _step;
  };
}

#endif /* !_TIMEOUT_HPP_ */
