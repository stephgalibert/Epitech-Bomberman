//
// Application.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 15:36:32 2016 stephane galibert
// Last update Wed May 18 20:18:42 2016 stephane galibert
//

#ifndef _APPLICATION_HPP_
# define _APPLICATION_HPP_

# include "Irrlicht.hpp"
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
    //IrrAssimp *_loader;
    //Menu *_menu;
    Game *_game;
    InputListener _inputListener;
    tools::Chronometer _timer;
    bbman::ApplicationState _as;
  };
}

#endif /* !_APPLICATION_HPP_ */
