//
// Game.hpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:38:22 2016 avelin_j
// Last update Sun Jun  5 13:05:52 2016 stephane galibert
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
# include "HighScore.hpp"

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
    irr::f32 getDelta(void) const;
    void setDelta(irr::f32 delta);
    Board const *testGetBoard(void) const;
    TimeOut const *testGetTimeOut(void) const;
  private:
    void cameraTargetSmoothAnimation(irr::f32 delta,
				     irr::core::vector3df const& cpos,
				     irr::core::vector3df const& npos);
    void cameraPositionSmoothAnimation(irr::f32 delta,
				       irr::core::vector3df const& cpos,
				       irr::core::vector3df const& npos);
    void initCamera(Irrlicht &irr);
    void initSound(void);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    void updatePlayers(Irrlicht &irr, irr::f32 delta);
    void displayEnd(int n);
    void save(std::string const& fname);
    void saveScore(void);
    void createPlayers(Irrlicht &irr);
    void pause(void);
    bool _leaveGame;
    Loader _loader;
    Board *_board;
    TimeOut *_timeout;
    MusicBox _musics;
    MemoryFile _musicBackground;
    irr::scene::ICameraSceneNode *_camera;
    layout *_layout;
    irr::f32 _delta;
    irr::f32 _delta_pause;
    bool _pause;
    bool _endscene;
  };
}

#endif /* !_GAME_HPP_ */
