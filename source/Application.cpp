//
// Application.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 18:45:42 2016 stephane galibert
// Last update Fri Jun  3 06:40:11 2016 stephane galibert
//

#include "Application.hpp"

bbman::Application::Application(void)
{
  this->_irr = NULL;
  this->_game = NULL;
  this->_menu = NULL;
  this->_as = bbman::ApplicationState::AS_NONE;
  this->_close = false;
  //tools::StaticTools::initThreadPool(16);
}

bbman::Application::~Application(void)
{
  if (this->_game) {
    delete (this->_game);
  }
  if (this->_menu) {
    delete (this->_menu);
  }
  if (this->_irr) {
    delete (this->_irr);
  }
  //tools::StaticTools::deleteThreadPool();
}

void bbman::Application::init(void)
{
  try {
    this->_irr = new Irrlicht;
    this->_irr->init(irr::video::EDT_OPENGL,
		     irr::core::dimension2d<irr::u32>(1920, 1080),
		     this->_inputListener);
    this->_timer.setTimer(this->_irr->getTimer());
    this->_irr->getDevice()->getCursorControl()->setVisible(true);
    this->_irr->getDevice()->activateJoysticks(this->_joystickInfo);

    this->_irr->getDevice()->setWindowCaption(L"Bomberman");
    this->_menu = new layout(this->_irr->getDevice());
    this->_menu->setGamepads(this->_joystickInfo);
    goToMenu();
  } catch (std::runtime_error const& e) {
    throw (e);
  }
}

int bbman::Application::play(void)
{
  irr::f32 delta = 0;

  this->_timer.start();
  while (!this->_close && this->_irr->isRunning())
    {
      delta = this->_timer.restart() / 1000.f;
      if (delta > 0.06000) {
	delta = 0.060;
      }
      if (this->_inputListener.IsKeyDown(irr::KEY_KEY_N)) {
	this->_close = true;
      }
      if (this->_as == ApplicationState::AS_GAME) {
	update_game(delta);
      } else if (this->_as == ApplicationState::AS_MENU) {
	update_menu(delta);
      }
    }
  return (0);
}

void bbman::Application::update_game(irr::f32 delta)
{
  if (this->_game) {
    this->_game->input(this->_inputListener);
    this->_game->update(*this->_irr, delta);
    this->_irr->beginScene();
    this->_irr->drawScene();
    this->_irr->drawGUI();
    //this->_irr->getLayout()->display();
    this->_irr->endScene();
    if (this->_game->leaveGame()) {
      goToMenu();
    }
  }
}

void bbman::Application::update_menu(irr::f32 delta)
{
  (void)delta;
  if (this->_menu) {
    this->_menu->input(this->_inputListener);
    //_menu->update(delta);
    //if (_menu->startGame()) {
      /*delete (_menu);
      _menu = NULL;

    // ! a delete quand y aura le menu
      this->_irr.beginScene();
      this->_irr.endScene();
      // go to menu*/
    // }
    //else
      this->_irr->beginScene();
      this->_menu->display();
      this->_irr->endScene();
      if (this->_menu->isGameStarted()) {
	goToGame();
      }
      if (this->_menu->isClosed()) {
	this->_close = true;
      }
  }
}

void bbman::Application::goToMenu(void)
{
  if (this->_as != bbman::ApplicationState::AS_MENU) {
    this->_as = bbman::ApplicationState::AS_MENU;
    if (this->_game) {
      delete (this->_game);
      this->_game = NULL;
    }
    //this->_menu = new layout(this->_irr->getDevice());
    this->_menu->backToMenu();
    // try
    // _menu->init(*this->_irr);
    // catch
  }
}

void bbman::Application::goToGame(void)
{
  if (this->_as != bbman::ApplicationState::AS_GAME) {
    this->_as = bbman::ApplicationState::AS_GAME;
    this->_game = new Game;
    try {
      //this->_game->init(*this->_irr, this->_menu, "./save.txt");
      this->_game->init(*this->_irr, this->_menu);
    } catch (std::runtime_error const& e) {
      delete (this->_game);
      this->_game = NULL;
      throw (e);
    }
  }
}
