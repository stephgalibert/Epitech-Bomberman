//
// Application.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 18:45:42 2016 stephane galibert
// Last update Wed May 11 16:06:08 2016 stephane galibert
//

#include "Application.hpp"

bbman::Application::Application(void)
{
  this->_game = NULL;
  this->_as = bbman::ApplicationState::AS_NONE;
}

bbman::Application::~Application(void)
{
  if (this->_game)
    delete (this->_game);
}

void bbman::Application::init(void)
{
  try {
    this->_irr.init(irr::video::EDT_OPENGL,
	      irr::core::dimension2d<irr::u32>(1920, 1080),
	      _inputListener);
    this->_timer.setTimer(this->_irr.getTimer());
    this->_irr.getDevice()->getCursorControl()->setVisible(true);
    // ! a delete quand y aura le menu
    goToGame();
  } catch (std::runtime_error const& e) {
    throw (e);
  }
}

int bbman::Application::play(void)
{
  irr::f32 delta = 0;

  this->_timer.start();
  while (this->_irr.isRunning())
    {
      delta = this->_timer.restart() / 1000.f;
      if (_inputListener.IsKeyDown(irr::KEY_KEY_N))
	return (0);
      // in game ...
      update_game(delta);
      // or in menu
      /*update_menu(delta);*/
    }
  return (0);
}

void bbman::Application::update_game(irr::f32 delta)
{
  if (this->_game)
    {
      this->_game->input(_inputListener);
      this->_game->update(_irr, delta);
      if (this->_game->leaveGame())
	{
	  goToMenu();
	  // ! a delete quand y aura le menu
	  this->_irr.beginScene(); // !
	  this->_irr.endScene(); // !
	}
      else
	{
	  this->_irr.beginScene();
	  this->_irr.drawScene();
	  this->_irr.drawGUI();
	  //this->_game->draw(this->_irr);
	  this->_irr.endScene();
	}
    }
}

void bbman::Application::update_menu(irr::f32 delta)
{
  (void)delta;
  /*if (_menu)
    {
    update menu
    _menu->input(_inputListener);
    _menu->update(delta);
    if (_menu->startGame())
    {
    delete (_menu);
    _menu = NULL;

    // ! a delete quand y aura le menu
    this->_irr.beginScene();
    this->_irr.endScene();
    // go to menu
    }
    else
    {
    this->_irr.beginScene();
    _menu->draw(this->_irr);
    this->_irr.endScene();
    }
    }*/
}

void bbman::Application::goToMenu(void)
{
  if (this->_as != bbman::ApplicationState::AS_MENU)
    {
      this->_as = bbman::ApplicationState::AS_MENU;
      if (this->_game)
	{
	  delete (this->_game);
	  this->_game = NULL;
	}
      // _menu = new Menu;
      // try
      // _menu->init(this->_irr);
      // catch
    }
}

void bbman::Application::goToGame(void)
{
  if (this->_as != bbman::ApplicationState::AS_GAME)
    {
      this->_as = bbman::ApplicationState::AS_GAME;
      /*if (_menu)
	{
	delete (_menu);
	_menu = NULL;
	}*/
      this->_game = new Game;
      try {
	this->_game->init(this->_irr);
      } catch (std::runtime_error const& e) {
	delete (this->_game);
	this->_game = NULL;
	throw (e);
      }
    }
}
