//
// Application.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 15:36:32 2016 stephane galibert
// Last update Tue May 31 10:37:53 2016 stephane galibert
//

#ifndef _APPLICATION_HPP_
# define _APPLICATION_HPP_

# include "Irrlicht.hpp"
# include "layout.hpp"
# include "Chronometer.hpp"
# include "Game.hpp"
# include "InputListener.hpp"
# include "ApplicationState.hpp"

namespace bbman
{
  class Application
  {
  public:
    Application(void);
    ~Application(void);
    void init(void);
    int play(void);
  private:
    void update_game(irr::f32 delta);
    void update_menu(irr::f32 delta);
    void goToMenu(void);
    void goToGame(void);
    Irrlicht *_irr;
    //Menu *_menu;
    layout *_menu;
    Game *_game;
    bool _close;
    InputListener _inputListener;
    irr::core::array<irr::SJoystickInfo> _joystickInfo;
    tools::Chronometer _timer;
    bbman::ApplicationState _as;
  };
}

#endif /* !_APPLICATION_HPP_ */
