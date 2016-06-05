//
// Application.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 15:36:32 2016 stephane galibert
// Last update Sun Jun  5 14:43:13 2016 stephane galibert
//

#ifndef _APPLICATION_HPP_
# define _APPLICATION_HPP_

# include "Irrlicht.hpp"
# include "layout.hpp"
# include "Chronometer.hpp"
# include "Game.hpp"
# include "InputListener.hpp"
# include "ApplicationState.hpp"
# include "SoundBox.hpp"
# include "CacheManager.hpp"
# include "MemoryFile.hpp"

namespace bbman
{
  class Application
  {
  public:
    Application(void);
    ~Application(void);
    void init(void);
    int play(void);
    Irrlicht const *testGetIrrlicht(void) const;
    Game const *testGetGame(void) const;
    layout const *testGetMenu(void) const;
    bool testGetClose(void) const;
    ApplicationState testGetApplicationState(void) const;
  private:
    static CacheManager<std::string, MemoryFile> SoundCache;
  private:
    void update_game(irr::f32 delta);
    void update_menu(irr::f32 delta);
    void goToMenu(void);
    void goToGame(void);
    Irrlicht *_irr;
    layout *_menu;
    Game *_game;
    bool _close;
    MusicBox _musics;
    MemoryFile _musicBackground;
    InputListener _inputListener;
    irr::core::array<irr::SJoystickInfo> _joystickInfo;
    tools::Chronometer _timer;
    bbman::ApplicationState _as;
  };
}

#endif /* !_APPLICATION_HPP_ */
