//
// Application.cpp for  in /home/avelin_j/bomberman
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:33:40 2016 avelin_j
// Last update Sun Jun  5 12:37:19 2016 stephane galibert
//

#include "Application.hpp"

bbman::Application::Application(void)
{
  this->_irr = NULL;
  this->_game = NULL;
  this->_menu = NULL;
  this->_as = bbman::ApplicationState::AS_NONE;
  this->_close = false;
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
    tools::StaticTools::volume("music", 50);
    tools::StaticTools::volume("effect", 50);
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
      if (this->_as == ApplicationState::AS_GAME) {
	update_game(delta);
      } else if (this->_as == ApplicationState::AS_MENU) {
	update_menu(delta);
      }
    }
  return (0);
}

bbman::Irrlicht const *bbman::Application::testGetIrrlicht(void) const
{
  return (this->_irr);
}

bbman::Game const *bbman::Application::testGetGame(void) const
{
  return (this->_game);
}

layout const *bbman::Application::testGetMenu(void) const
{
  return (this->_menu);
}

bool bbman::Application::testGetClose(void) const
{
  return (this->_close);
}

bbman::ApplicationState bbman::Application::testGetApplicationState(void) const
{
  return (this->_as);
}

void bbman::Application::update_game(irr::f32 delta)
{
  if (this->_game) {
    this->_game->input(this->_inputListener);
    this->_game->update(*this->_irr, delta);
    this->_irr->beginScene();
    this->_irr->drawScene();
    this->_irr->drawGUI();
    this->_menu->display();
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
    this->_menu->backToMenu();
  }
}

void bbman::Application::goToGame(void)
{
  if (this->_as != bbman::ApplicationState::AS_GAME) {
    this->_as = bbman::ApplicationState::AS_GAME;
    this->_game = new Game;
    try {
      if  (this->_menu && !this->_menu->getSaveName().empty()) {
	this->_game->init(*this->_irr, this->_menu, this->_menu->getSaveName());
	this->_menu->resetSaveName();
      } else {
	this->_game->init(*this->_irr, this->_menu);
      }
    } catch (std::runtime_error const& e) {
      delete (this->_game);
      this->_game = NULL;
      throw (e);
    }
  }
}
