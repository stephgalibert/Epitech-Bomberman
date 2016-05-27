//
// Game.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 11 16:04:29 2016 stephane galibert
// Last update Fri May 27 08:45:59 2016 stephane galibert
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

# include <iostream>
# include <fstream>
# include <vector>
# include <cmath>
# include <algorithm>
# include <list>
# include <map>

# include "MusicBox.hpp"
# include "APlayer.hpp"
# include "IBomb.hpp"
# include "InputListener.hpp"
# include "PowerUPs.hpp"
# include "HumanPlayer.hpp"
# include "Board.hpp"
# include "MemoryFile.hpp"
# include "CacheManager.hpp"
# include "Loader.hpp"

namespace bbman
{
  class Game
  {
  public:
    Game(void);
    ~Game(void);
    void init(Irrlicht &irr, std::string const& saves = "");
    bool input(InputListener &inputListener);
    void update(Irrlicht &irr, irr::f32 delta);
    bool leaveGame(void) const;
  private:
    void initCamera(Irrlicht &irr);
    void initSound(void);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    void updatePlayers(Irrlicht &irr, irr::f32 delta);
    void save(std::string const& fname);
    bool _leaveGame;
    Loader _loader;
    irr::scene::ICameraSceneNode *_camera;
    Board *_board;

    //std::list<IBomb *> _bombs;
    //std::vector<APlayer *> _players;
    //std::list<IEntity *> _explosable; // => players, bombs
    //PowerUPs _powerUPs;

    MusicBox _musics;
    MemoryFile _musicBackground;
  };
}

#endif /* !_GAME_HPP_ */
