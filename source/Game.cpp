//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Thu May 12 00:20:17 2016 stephane galibert
//

#include "Game.hpp"

bbman::Game::Game(void)
{
  this->_leaveGame = false;
  this->_board = new Board;
}

bbman::Game::~Game(void)
{
  if (this->_board)
    delete (this->_board);
  for (auto &it : this->_bombs)
    delete (it);
  for (auto &it : this->_players)
    delete (it);
}

void bbman::Game::init(Irrlicht &irr)
{
  try {
    this->_board->init(irr);
    this->_powerUPs.setArea(this->_board->getSize());
    initCamera(irr);
    {
      HumanPlayer *p1 = new HumanPlayer;
      p1->init(irr);
      this->_players.push_back(p1);
    }
    {
      HumanPlayer *p2 = new HumanPlayer;
      p2->init(irr);
      this->_players.push_back(p2);
    }
  } catch (std::runtime_error const& e) {
    throw (e);
  }
}

bool bbman::Game::input(InputListener &inputListener)
{
  if (inputListener.IsKeyDown(irr::KEY_ESCAPE))
    {
      this->_leaveGame = true;
      return (true);
    }
  else
    for (auto &it : this->_players)
      it->input(inputListener);
  return (false);
}

void bbman::Game::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  for (auto &it : this->_players)
    {
      it->update(irr, delta);
      this->checkCollision(it);
      if (it->getAction() == Action::ACT_BOMB)
	this->addBomb(it, irr);
    }
  this->_powerUPs.update(irr, delta, this->_board);
  this->updateBombs(irr, delta);
}

bool bbman::Game::leaveGame(void) const
{
  return (this->_leaveGame);
}

void bbman::Game::initCamera(bbman::Irrlicht &irr)
{
  irr::core::vector3df pos;

  pos = this->_board->getPosition();
  this->_camera = irr.getSmgr()->addCameraSceneNode();
  this->_camera->setTarget(irr::core::vector3df(pos.X, pos.Y, pos.Z));
  this->_camera->setPosition(irr::core::vector3df(pos.X, pos.Y + 120, 0));
}

void bbman::Game::addBomb(IPlayer *player, bbman::Irrlicht &irr)
{
  IBomb *newBomb = player->createBomb(irr);
  irr::core::vector3df pos = player->getPosition();

  pos.X = this->_board->getScale().X / 2 + std::floor(pos.X)
    - (int)(std::floor(pos.X)) % (int)this->_board->getScale().X;
  pos.Z = this->_board->getScale().Z / 2 + std::floor(pos.Z)
    - (int)(std::floor(pos.Z)) % (int)this->_board->getScale().Z;
  newBomb->setPosition(pos);
  if (std::find_if(std::begin(this->_bombs), std::end(this->_bombs),
		   [&newBomb](IBomb *bomb) {
		     if (newBomb->getPosition() == bomb->getPosition())
		       return (true);
		     return (false);
		   }) == std::end(_bombs)
      && !this->_board->isOutside(pos))
    this->_bombs.push_back(newBomb);
  else
    delete (newBomb);
}

void bbman::Game::checkCollision(bbman::IPlayer *player)
{
  if (player->isRunning())
    {
      if (this->_board->isColliding(player->getBoundingBox())
	  || this->_board->isOutside(player->getPosition()))
	player->goToPrevPosition();
      this->_powerUPs.checkCollision(player);
    }
}

void bbman::Game::updateBombs(bbman::Irrlicht &irr, irr::f32 delta)
{
  for (std::list<IBomb *>::iterator it = std::begin(this->_bombs);
       it != std::end(this->_bombs); )
    {
      if ((*it)->hasExplosed())
	{
	  delete (*it);
	  it = this->_bombs.erase(it);
	}
      else
	{
	  (*it)->update(irr, delta);
	  ++it;
	}
    }
}
