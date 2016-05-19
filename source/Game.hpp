//
// Game.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 11 16:04:29 2016 stephane galibert
// Last update Thu May 19 15:52:07 2016 stephane galibert
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

# include <vector>
# include <cmath>
# include <algorithm>
# include <list>

# include "MusicBox.hpp"
# include "IPlayer.hpp"
# include "IBomb.hpp"
# include "InputListener.hpp"
# include "PowerUPs.hpp"
# include "HumanPlayer.hpp"
# include "Board.hpp"
# include "MemoryFile.hpp"
# include "CacheManager.hpp"

namespace bbman
{
  class Game
  {
  public:
    Game(void);
    ~Game(void);
    void init(Irrlicht &irr);
    bool input(InputListener &inputListener);
    void update(Irrlicht &irr, irr::f32 delta);
    bool leaveGame(void) const;
  private:
    void initCamera(Irrlicht &irr);
    void initSound(void);
    void addBomb(IPlayer *player, Irrlicht &irr);
    void checkCollision(IPlayer *player);
    void updateBombs(Irrlicht &irr, irr::f32 delta);
    Board *_board;
    bool _leaveGame;
    irr::scene::ICameraSceneNode *_camera;
    std::list<IBomb *> _bombs;
    std::vector<IPlayer *> _players;
    PowerUPs _powerUPs;
    MusicBox _musics;
    MemoryFile _musicBackground;
  };
}

#endif /* !_GAME_HPP_ */
