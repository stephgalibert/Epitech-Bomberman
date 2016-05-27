//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Fri May 27 08:47:01 2016 stephane galibert
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
  /*
  for (auto &it : this->_bombs) {
    delete (it);
  }
  for (auto &it : this->_players) {
    delete (it);
    }*/
}

void bbman::Game::init(Irrlicht &irr, std::string const& saves)
{
  try {
    if (!saves.empty()) {
      this->_loader.load(irr, saves);
      //this->_board->init(irr, this->_loader.getMap());
      this->_board->init(irr, this->_loader);
      /*this->_players = this->_loader.getPlayers();
	this->_bombs = this->_loader.getBombs();*/
    }
    else {
      this->_board->init(irr);
      // BEGIN todel
      HumanPlayer *p1 = bbman::HumanPlayer::create();
      p1->init(irr);
      p1->setPosition(this->_board->getSpawnPosition(0));
      //this->_players.push_back(p1);
      this->_board->addPlayer(p1); //
      HumanPlayer *p2 = bbman::HumanPlayer::create();
      p2->init(irr);
      p2->setPosition(this->_board->getSpawnPosition(1));
      //this->_players.push_back(p2);
      this->_board->addPlayer(p2); //
      // END todel
    }
    initCamera(irr);
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
    save("./save.txt");
    return (true);
  }
  else {
    this->_board->input(inputListener);
    /*for (auto &it : this->_players) {
      it->input(inputListener);
      }*/
  }
  return (false);
}

void bbman::Game::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  /*updatePlayers(irr, delta); //
  this->_powerUPs.update(irr, delta, this->_board); //
  updateBombs(irr, delta); //*/

  this->_board->update(irr, delta);
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
    this->_musics.setVolumeBySample("mbackground", 50.f);
    this->_musics.play("mbackground");
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }
}

//
void bbman::Game::save(std::string const& fname)
{
  std::ofstream ofs(fname.c_str(), std::ifstream::out);
  if (ofs) {
    ofs << *this->_board;
    /*ofs << "PLAYERS_BEGIN" << std::endl; //
    for (auto it : this->_players) {
      ofs << *it;
    }
    ofs << "PLAYERS_END" << std::endl;
    ofs << "BOMBS_BEGIN" << std::endl;
    for (auto it : this->_bombs) {
    ofs << *it;
    }
    ofs << "BOMBS_END" << std::endl;*/
  }
  else {
    throw (std::runtime_error("can not create ./save.txt"));
  }
}

/*void bbman::Game::updateBombs(bbman::Irrlicht &irr, irr::f32 delta) //
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
		&& this->_board->isNotProtected(it2->getPosInMap(this->_board->getScale()), (*it)->getPosInMap(this->_board->getScale()))) {
	      it2->explode();
	      std::cerr << " killed by " << (*it)->getOwnerID() << std::endl;
	    }
	  }
	}

	this->_board->explodeBlocks(*it);
	//this->_boar->exploseExplosable(*it, this->_explosable);

	for (auto &it2 : this->_bombs) {
	  if (!it2->hasExplosed()) {
	    if ((*it)->isInExplosion(it2, this->_board->getScale())
		&& this->_board->isNotProtected(it2->getPosInMap(this->_board->getScale()), (*it)->getPosInMap(this->_board->getScale()))) {
	      it2->explode();
	    }
	  }
	}

      }
      ++it;
    }
  }
}

void bbman::Game::updatePlayers(bbman::Irrlicht &irr, irr::f32 delta) //
{
  for (auto &it : this->_players) {
    it->play(irr, this->_board, this->_bombs);
    it->update(irr, delta);
    if (it->isRunning()) {
      this->_powerUPs.checkCollision(it);
    }
  }
  }*/
