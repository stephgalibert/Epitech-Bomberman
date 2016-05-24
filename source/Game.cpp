//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Tue May 24 19:14:20 2016 stephane galibert
//

#include "Game.hpp"

bbman::Game::Game(void)
{
  this->_leaveGame = false;
  this->_board = new Board;
}

bbman::Game::~Game(void)
{
  if (this->_board) {
    delete (this->_board);
  }
  for (auto &it : this->_bombs) {
    delete (it);
  }
  for (auto &it : this->_players) {
    delete (it);
  }
}

void bbman::Game::init(Irrlicht &irr)
{
  try {
    this->_board->init(irr);
    this->_powerUPs.setArea(this->_board->getSize());
    initCamera(irr);
    // BEGIN todel
    HumanPlayer *p1 = bbman::HumanPlayer::create();
    p1->init(irr);
    p1->setPosition(this->_board->getSpawnPosition(0));
    this->_players.push_back(p1);
    HumanPlayer *p2 = bbman::HumanPlayer::create();
    p2->init(irr);
    p2->setPosition(this->_board->getSpawnPosition(1));
    this->_players.push_back(p2);
    // END todel
    initSound();
  } catch (std::runtime_error const& e) {
    throw (e);
  }
}

bool bbman::Game::input(InputListener &inputListener)
{
  if (inputListener.IsKeyDown(irr::KEY_ESCAPE)) {
    this->_leaveGame = true;
    return (true);
  }
  else if (inputListener.IsKeyDown(irr::KEY_KEY_P)) {
    save();
    return (true);
  }
  else {
    for (auto &it : this->_players) {
      it->input(inputListener);
    }
  }
  return (false);
}

void bbman::Game::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  updatePlayers(irr, delta);
  this->_powerUPs.update(irr, delta, this->_board);
  updateBombs(irr, delta);
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

void bbman::Game::initSound(void)
{
  this->_musicBackground.filename = "./sample/TronLegacy.wav";
  try {
    this->_musicBackground.load();
    this->_musics.addSample("mbackground", this->_musicBackground);
    this->_musics.setLoop("mbackground", true);
    this->_musics.setVolumeBySample("mbackground", 5.f);
    this->_musics.play("mbackground");
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Game::save(void)
{
  std::ofstream ofs("./save.txt");
  if (ofs) {
    ofs << *this->_board;
  }
  else {
    throw (std::runtime_error("can not create ./save.txt"));
  }
}

void bbman::Game::updateBombs(bbman::Irrlicht &irr, irr::f32 delta)
{
  for (std::list<IBomb *>::iterator it = std::begin(this->_bombs);
       it != std::end(this->_bombs); ) {
    if ((*it)->hasExplosed()) {
      delete (*it);
      it = this->_bombs.erase(it);
    }
    else {
      (*it)->update(irr, delta);
      if ((*it)->isExplosing()) {
	for (auto &it2 : this->_players) {
	  if (!it2->hasExplosed()) {
	    if ((*it)->isInExplosion(it2, this->_board->getScale())
		&& this->_board->isNotProtected(it2->getPosInMap(this->_board->getScale()),
						(*it)->getPosInMap(this->_board->getScale()))) {
	      it2->explode();
	    }
	  }
	}
	this->_board->explodeBlocks(*it);
      }
      ++it;
    }
  }
}

void bbman::Game::updatePlayers(bbman::Irrlicht &irr, irr::f32 delta)
{
  for (auto &it : this->_players) {
    it->play(irr, this->_board, this->_bombs);
    it->update(irr, delta);
    if (it->isRunning()) {
      this->_powerUPs.checkCollision(it);
    }
  }
}
