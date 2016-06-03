//
// Game.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 11 16:04:29 2016 stephane galibert
// Last update Fri Jun  3 02:47:29 2016 stephane galibert
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

# include <iostream>
# include <fstream>
# include <cmath>
# include <algorithm>

# include "MusicBox.hpp"
# include "InputListener.hpp"
# include "PowerUPs.hpp"
# include "HumanPlayer.hpp"
# include "Board.hpp"
# include "MemoryFile.hpp"
# include "CacheManager.hpp"
# include "Loader.hpp"
# include "AIFunctions.hpp"
# include "TimeOut.hpp"
# include "AIPlayer.hpp"
# include "Binding.hpp"
# include "layout.hpp"

namespace bbman
{
  class Game
  {
  public:
    Game(void);
    ~Game(void);
    void init(Irrlicht &irr, layout *layout, std::string const& saves = "");
    bool input(InputListener &inputListener);
    void update(Irrlicht &irr, irr::f32 delta);
    bool leaveGame(void) const;
  private:
    void initCamera(Irrlicht &irr);
    void initSound(void);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    void updatePlayers(Irrlicht &irr, irr::f32 delta);
    void save(std::string const& fname);
    void createPlayers(Irrlicht &irr);
    bool _leaveGame;
    Loader _loader;
    Board *_board;
    TimeOut *_timeout;
    MusicBox _musics;
    MemoryFile _musicBackground;
    irr::scene::ICameraSceneNode *_camera;
    layout *_layout;
  };
}

#endif /* !_GAME_HPP_ */
